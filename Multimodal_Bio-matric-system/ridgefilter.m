
function newim = ridgefilter(im, orient, freq, kx, ky, showfilter)

    if nargin == 5
        showfilter = 0;
    end
    
    angleInc = 3;  % Fixed angle increment between filter orientations in
                   % degrees. This should divide evenly into 180
    
    im = double(im);
    [rows, cols] = size(im);
    newim = zeros(rows,cols);
    
    [validr,validc] = find(freq > 0);  % find where there is valid frequency data.
    ind = sub2ind([rows,cols], validr, validc);

    % Round the array of frequencies to the nearest 0.01 to reduce the
    % number of distinct frequencies we have to deal with.
    freq(ind) = round(freq(ind)*100)/100;
    
    % Generate an array of the distinct frequencies present in the array
    % freq 
    unfreq = unique(freq(ind)); 
    
    % Generate a table, given the frequency value multiplied by 100 to obtain
    % an integer index, returns the index within the unfreq array that it
    % corresponds to
    freqindex = ones(100,1);
    for k = 1:length(unfreq)
        freqindex(round(unfreq(k)*100)) = k;
    end
    
    % Generate filters corresponding to these distinct frequencies and
    % orientations in 'angleInc' increments.
    filter = cell(length(unfreq),180/angleInc);
    sze = zeros(length(unfreq),1);
    
    for k = 1:length(unfreq)
        sigmax = 1/unfreq(k)*kx;
        sigmay = 1/unfreq(k)*ky;
        
        sze(k) = round(3*max(sigmax,sigmay));
        [x,y] = meshgrid(-sze(k):sze(k));
        reffilter = exp(-(x.^2/sigmax^2 + y.^2/sigmay^2)/2)...
                .*cos(2*pi*unfreq(k)*x);

        % Generate rotated versions of the filter.  Note orientation
        % image provides orientation *along* the ridges, hence +90
        % degrees, and imrotate requires angles +ve anticlockwise, hence
        % the minus sign.
        for o = 1:180/angleInc
            filter{k,o} = imrotate(reffilter,-(o*angleInc+90),'bilinear','crop'); 
        end
    end

%    if showfilter % Display largest scale filter for inspection
%        figure(7), imshow(filter{1,end},[]); title('filter'); 
%    end
    
    % Find indices of matrix points greater than maxsze from the image
    % boundary
    maxsze = sze(1);    
    finalind = find(validr>maxsze & validr<rows-maxsze & ...
                    validc>maxsze & validc<cols-maxsze);
    
    % Convert orientation matrix values from radians to an index value
    % that corresponds to round(degrees/angleInc)
    maxorientindex = round(180/angleInc);
    orientindex = round(orient/pi*180/angleInc);
    i = find(orientindex < 1);   orientindex(i) = orientindex(i)+maxorientindex;
    i = find(orientindex > maxorientindex); 
    orientindex(i) = orientindex(i)-maxorientindex; 

    % Finally do the filtering
    for k = 1:length(finalind)
        r = validr(finalind(k));
        c = validc(finalind(k));

        % find filter corresponding to freq(r,c)
        filterindex = freqindex(round(freq(r,c)*100));
        
        s = sze(filterindex);   
        newim(r,c) = sum(sum(im(r-s:r+s, c-s:c+s).*filter{filterindex,orientindex(r,c)}));
    end

    

