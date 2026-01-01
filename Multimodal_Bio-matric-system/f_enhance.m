% ENHANCING FINGERPRINT IMAGE
%
% Usage:  [ binim, mask, cimg, cimg2, orient_img, orient_img_m ] =
%          ... f_enhance( img );
%
% Argument:   img - FingerPrint Image
%               
% Returns:    binim   - binary image 
%             mask    - binary mask
%             cimg1,2 - coherence image
%             oimg1,2 - The orientation image in radians.

% Vahid. K. Alilou
% Department of Computer Engineering
% The University of Semnan
%
% July 2013

function [ binim, mask, cimg1, cimg2, oimg1, oimg2 ] = f_enhance( img )
    enhimg =  fft_enhance_cubs(img,6);             % Enhance with Blocks 6x6
    enhimg =  fft_enhance_cubs(enhimg,12);         % Enhance with Blocks 12x12
    [enhimg,cimg2] =  fft_enhance_cubs(enhimg,24); % Enhance with Blocks 24x24
    blksze = 5;   thresh = 0.085;                  % FVC2002 DB1
    normim = ridgesegment(enhimg, blksze, thresh);
    oimg1 = ridgeorient(normim, 1, 3, 3);          % FVC2002 DB1
    
    [enhimg,cimg1] =  fft_enhance_cubs(img, -1);
    [normim, mask] = ridgesegment(enhimg, blksze, thresh);
    oimg2 = ridgeorient(normim, 1, 3, 3); 
    [freq, medfreq] = ridgefreq(normim, mask, oimg2, 32, 5, 5, 15);
    binim = ridgefilter(normim, oimg2, medfreq.*mask, 0.5, 0.5, 1) > 0;
end