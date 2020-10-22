%------------------------------------------------------------------------
%compute_coherence
%Computes the coherence image. 
%Usage:
%[cimg] = compute_coherence(oimg)
%oimg - orientation image
%cimg - coherence image(0-low coherence,1-high coherence)
%Contact:
%   ssc5@eng.buffalo.edu
%   www.eng.buffalo.edu/~ssc5
%Reference:
%A. Ravishankar Rao,"A taxonomy of texture description", Springer Verlag
%------------------------------------------------------------------------
function [cimg] = compute_coherence(oimg)
    [h,w]   =   size(oimg);
    cimg    =   zeros(h,w);
    N       =   2;
    %---------------
    %pad the image
    %---------------
    oimg    =   [flipud(oimg(1:N,:));oimg;flipud(oimg(h-N+1:h,:))]; %pad the rows
    oimg    =   [fliplr(oimg(:,1:N)),oimg,fliplr(oimg(:,w-N+1:w))]; %pad the cols
    %compute coherence
    for i=N+1:h+N
        for j = N+1:w+N
            th  = oimg(i,j);
            blk = oimg(i-N:i+N,j-N:j+N);
            cimg(i-N,j-N)=sum(sum(abs(cos(blk-th))))/((2*N+1).^2);
        end;
    end;
%end function compute_coherence