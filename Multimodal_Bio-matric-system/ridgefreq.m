

function [freq, medianfreq] = ridgefreq(im, mask, orient, blksze, windsze, ...
                                        minWaveLength, maxWaveLength)     
    
    [rows, cols] = size(im);
    freq = zeros(size(im));
    
    for r = 1:blksze:rows-blksze
        for c = 1:blksze:cols-blksze
          blkim = im(r:r+blksze-1, c:c+blksze-1);   
          blkor = orient(r:r+blksze-1, c:c+blksze-1);       
          
          freq(r:r+blksze-1,c:c+blksze-1) =  ...
              freqest(blkim, blkor, windsze, minWaveLength, maxWaveLength);
        end
    end

    % Mask out frequencies calculated for non ridge regions
    freq = freq.*mask;
    
    % Find median freqency over all the valid regions of the image.
    medianfreq = median(freq(find(freq>0)));  
