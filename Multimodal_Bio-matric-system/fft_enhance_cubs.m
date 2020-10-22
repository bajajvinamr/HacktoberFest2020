%--------------------------------------------------------------------------
%fft_enhance_cubs
%enhances the fingerprint image
%syntax:
%[oimg,fimg,bwimg,eimg,enhimg] =  fft_enhance_cubs(img, BLKSZ)
%oimg -  [OUT] block orientation image(can be viewed using
%        view_orientation_image.m)
%fimg  - [OUT] block frequency image(indicates ridge spacing)
%bwimg - [OUT] shows angular bandwidth image(filter bandwidth adapts near the
%        singular points)
%eimg  - [OUT] energy image. Indicates the 'ridgeness' of a block (can be 
%        used for fingerprint segmentation)
%enhimg- [OUT] enhanced image
%img   - [IN]  input fingerprint image (HAS to be of DOUBLE type)
%Contact:
%   ssc5@eng.buffalo.edu
%   www.eng.buffalo.edu/~ssc5
%Reference:
%S. Chikkerur,C. Wu and Govindaraju, "A Systematic approach for 
%feature extraction in fingerprint images",ICBA 2004
%--------------------------------------------------------------------------
function [enhimg, cimg, oimg,fimg,bwimg,eimg] =  fft_enhance_cubs(img, BLKSZ)
    global NFFT;

    if BLKSZ > 0
       NFFT        =   32;     %size of FFT
       OVRLP       =   2;      %size of overlap
       ALPHA       =   0.5;    %root filtering
       RMIN        =   4;%%3;      %min allowable ridge spacing
       RMAX        =   40;     %maximum allowable ridge spacing
       ESTRETCH    =   20;     %for contrast enhancement
       ETHRESH     =   19;      %threshold for the energy
    else
       NFFT        =   32;     %size of FFT
       BLKSZ       =   12;     %size of the block
       OVRLP       =   6;      %size of overlap
       ALPHA       =   0.5;    %root filtering
       RMIN        =   3;      %min allowable ridge spacing
       RMAX        =   18;     %maximum allowable ridge spacing
       ESTRETCH    =   20;     %for contrast enhancement
       ETHRESH     =   6;      %threshold for the energy
    end
    
    [nHt,nWt]   =   size(img);  
    img         =   double(img);    %convert to DOUBLE
    nBlkHt      =   floor((nHt-2*OVRLP)/BLKSZ);
    nBlkWt      =   floor((nWt-2*OVRLP)/BLKSZ);
    fftSrc      =   zeros(nBlkHt*nBlkWt,NFFT*NFFT); %stores FFT
    nWndSz      =   BLKSZ+2*OVRLP; %size of analysis window. 
    %-------------------------
    %allocate outputs
    %-------------------------
    oimg        =   zeros(nBlkHt,nBlkWt);
    fimg        =   zeros(nBlkHt,nBlkWt);
    bwimg       =   zeros(nBlkHt,nBlkWt);
    eimg        =   zeros(nBlkHt,nBlkWt);
    enhimg      =   zeros(nHt,nWt);
    
    %-------------------------
    %precomputations
    %-------------------------
    [x,y]       =   meshgrid(0:nWndSz-1,0:nWndSz-1);
    dMult       =   (-1).^(x+y); %used to center the FFT
    [x,y]       =   meshgrid(-NFFT/2:NFFT/2-1,-NFFT/2:NFFT/2-1);
    r           =   sqrt(x.^2+y.^2)+eps;
    th          =   atan2(y,x);
    th(th<0)    =   th(th<0)+pi;
    w           =   raised_cosine_window(BLKSZ,OVRLP); %spectral window

    %-------------------------
    %Load filters
    %-------------------------
    load angular_filters_pi_4;   %now angf_pi_4 has filter coefficients
    angf_pi_4 = angf;
    load angular_filters_pi_2;   %now angf_pi_2 has filter coefficients
    angf_pi_2 = angf;
    %-------------------------
    %Bandpass filter
    %-------------------------
    FLOW        =   NFFT/RMAX;
    FHIGH       =   NFFT/RMIN;
    
    dRLow       =   1./(1+(r/FHIGH).^4);    %low pass butterworth filter
    dRHigh      =   1./(1+(FLOW./r).^4);    %high pass butterworth filter
    dBPass      =   dRLow.*dRHigh;          %bandpass
    
    %-------------------------
    %FFT Analysis
    %-------------------------
    for i = 0:nBlkHt-1
        nRow = i*BLKSZ+OVRLP+1;  
        for j = 0:nBlkWt-1
            nCol = j*BLKSZ+OVRLP+1;
            %extract local block
            blk     =   img(nRow-OVRLP:nRow+BLKSZ+OVRLP-1,nCol-OVRLP:nCol+BLKSZ+OVRLP-1);
            %remove dc
            dAvg    =   sum(sum(blk))/(nWndSz*nWndSz);
            blk     =   blk-dAvg;   %remove DC content
            blk     =   blk.*w;     %multiply by spectral window
            %--------------------------
            %do pre filtering
            %--------------------------
            blkfft  =   fft2(blk.*dMult,NFFT,NFFT);
            blkfft  =   blkfft.*dBPass;             %band pass filtering
            dEnergy =   abs(blkfft).^2;
            blkfft  =   blkfft.*sqrt(dEnergy);      %root filtering(for diffusion)
            fftSrc(nBlkWt*i+j+1,:) = transpose(blkfft(:));
            dEnergy =   abs(blkfft).^2;             %----REDUCE THIS COMPUTATION----
            %--------------------------
            %compute statistics
            %--------------------------
            dTotal          =   sum(sum(dEnergy))/(NFFT*NFFT);
            fimg(i+1,j+1)   =   NFFT/(compute_mean_frequency(dEnergy,r)+eps); %ridge separation
            oimg(i+1,j+1)   =   compute_mean_angle(dEnergy,th);         %ridge angle
            eimg(i+1,j+1)   =   log(dTotal+eps);                        %used for segmentation
        end;%for j
    end;%for i

    %-------------------------
    %precomputations
    %-------------------------
    [x,y]       =   meshgrid(-NFFT/2:NFFT/2-1,-NFFT/2:NFFT/2-1);
    dMult       =   (-1).^(x+y); %used to center the FFT

    %-------------------------
    %process the resulting maps
    %-------------------------
    for i = 1:3
        oimg = smoothen_orientation_image(oimg);            %smoothen orientation image
    end;
    fimg    =   smoothen_frequency_image(fimg,RMIN,RMAX,5); %diffuse frequency image
    cimg    =   compute_coherence(oimg);                    %coherence image for bandwidth
    bwimg   =   get_angular_bw_image(cimg);                 %QUANTIZED bandwidth image
    %-------------------------
    %FFT reconstruction
    %-------------------------
    for i = 0:nBlkHt-1
        for j = 0:nBlkWt-1
            nRow = i*BLKSZ+OVRLP+1;            
            nCol = j*BLKSZ+OVRLP+1;
            %--------------------------
            %apply the filters
            %--------------------------
            blkfft  =   reshape(transpose(fftSrc(nBlkWt*i+j+1,:)),NFFT,NFFT);
            %--------------------------
            %reconstruction
            %--------------------------
            af      =   get_angular_filter(oimg(i+1,j+1),bwimg(i+1,j+1),angf_pi_4,angf_pi_2);
            blkfft  =   blkfft.*(af); 
            blk     =   real(ifft2(blkfft).*dMult);
            enhimg(nRow:nRow+BLKSZ-1,nCol:nCol+BLKSZ-1)=blk(OVRLP+1:OVRLP+BLKSZ,OVRLP+1:OVRLP+BLKSZ);
        end;%for j
    end;%for i
    %end block processing
    %--------------------------
    %contrast enhancement
    %--------------------------
    enhimg =sqrt(abs(enhimg)).*sign(enhimg);
    mx     =max(max(enhimg));
    mn     =min(min(enhimg));
    enhimg =uint8((enhimg-mn)/(mx-mn)*254+1);
    
    %--------------------------
    %clean up the image
    %--------------------------
    emsk  = imresize(eimg,[nHt,nWt]);
    enhimg(emsk<ETHRESH) = 128;
%end function fft_enhance_cubs

%-----------------------------------
%raised_cosine
%returns 1D spectral window
%syntax:
%y = raised_cosine(nBlkSz,nOvrlp)
%y      - [OUT] 1D raised cosine function
%nBlkSz - [IN]  the window is constant here
%nOvrlp - [IN]  the window has transition here
%-----------------------------------
function y = raised_cosine(nBlkSz,nOvrlp)
    nWndSz  =   (nBlkSz+2*nOvrlp);
    x       =   abs(-nWndSz/2:nWndSz/2-1);
    y       =   0.5*(cos(pi*(x-nBlkSz/2)/nOvrlp)+1);
    y(abs(x)<nBlkSz/2)=1;
%end function raised_cosine

%-----------------------------------
%raised_cosine_window
%returns 2D spectral window
%syntax:
%w = raised_cosine_window(blksz,ovrlp)
%w      - [OUT] 1D raised cosine function
%nBlkSz - [IN]  the window is constant here
%nOvrlp - [IN]  the window has transition here
%-----------------------------------
function w = raised_cosine_window(blksz,ovrlp)
    y = raised_cosine(blksz,ovrlp);
    w = y(:)*y(:)';
%end function raised_cosine_window

%---------------------------------------------------------------------
%get_angular_filter
%generates an angular filter centered around 'th' and with bandwidth 'bw'
%the filters in angf_xx are precomputed using angular_filter_bank.m
%syntax:
%r = get_angular_filter(t0,bw)
%r - [OUT] angular filter of size NFFTxNFFT
%t0- mean angle (obtained from orientation image)
%bw- angular bandwidth(obtained from bandwidth image)
%angf_xx - precomputed filters (using angular_filter_bank.m)
%-----------------------------------------------------------------------
function r = get_angular_filter(t0,bw,angf_pi_4,angf_pi_2)
    global NFFT;
    TSTEPS = size(angf_pi_4,2);
    DELTAT = pi/TSTEPS;
    %get the closest filter
    i      = floor((t0+DELTAT/2)/DELTAT);
    i      = mod(i,TSTEPS)+1; 
    if(bw == pi/4)
        r      = reshape(angf_pi_4(:,i),NFFT,NFFT)';
    elseif(bw == pi/2)
        r      = reshape(angf_pi_2(:,i),NFFT,NFFT)';
    else
        r      = ones(NFFT,NFFT);
    end;
%end function get_angular_filter


%-----------------------------------------------------------
%get_angular_bw_image
%the bandwidth allocation is currently based on heuristics
%(domain knowledge :)). 
%syntax:
%bwimg = get_angular_bw_image(c)
%-----------------------------------------------------------
function bwimg = get_angular_bw_image(c)
    bwimg   =   zeros(size(c));
    bwimg(:,:)    = pi/2;                       %med bw
    bwimg(c<=0.7) = pi;                         %high bw
    bwimg(c>=0.9) = pi/4;                       %low bw
%end function get_angular_bw


%-----------------------------------------------------------
%get_angular_bw_image
%the bandwidth allocation is currently based on heuristics
%(domain knowledge :)). 
%syntax:
%bwimg = get_angular_bw_image(c)
%-----------------------------------------------------------
function mth = compute_mean_angle(dEnergy,th)
    global NFFT;
    sth         =   sin(2*th);
    cth         =   cos(2*th);
    num         =   sum(sum(dEnergy.*sth));
    den         =   sum(sum(dEnergy.*cth));
    mth         =   0.5*atan2(num,den);
    if(mth <0)
        mth = mth+pi;
    end;
%end function compute_mean_angle

%-----------------------------------------------------------
%get_angular_bw_image
%the bandwidth allocation is currently based on heuristics
%(domain knowledge :)). 
%syntax:
%bwimg = get_angular_bw_image(c)
%-----------------------------------------------------------
function mr = compute_mean_frequency(dEnergy,r)
    global NFFT;
    num         =   sum(sum(dEnergy.*r));
    den         =   sum(sum(dEnergy));
    mr          =   num/(den+eps);
%end function compute_mean_angle
