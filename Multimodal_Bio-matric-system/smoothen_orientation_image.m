%------------------------------------------------------------------------
%smoothen_orientation_image
%smoothens the orientation image through vectorial gaussian filtering
%Usage:
%new_oimg = smoothen_orientation_image(oimg)
%oimg     - orientation image
%new_oimg - filtered orientation image
%Contact:
%   ssc5@eng.buffalo.edu
%   www.eng.buffalo.edu/~ssc5
%Reference:
%M. Kaas and A. Witkin, "Analyzing oriented patterns", Computer Vision
%Graphics Image Processing 37(4), pp 362--385, 1987
%------------------------------------------------------------------------
function noimg = smoothen_orientation_image(oimg)
    %---------------------------
    %smoothen the image
    %---------------------------
    gx      =   cos(2*oimg);
    gy      =   sin(2*oimg);
    
    msk     =   fspecial('gaussian',5);
    gfx     =   imfilter(gx,msk,'symmetric','same');
    gfy     =   imfilter(gy,msk,'symmetric','same');
    noimg   =   atan2(gfy,gfx);
    noimg(noimg<0) = noimg(noimg<0)+2*pi;
    noimg   =   0.5*noimg;
%end function smoothen_orientation_image