%------------------------------------------------------------------------
%smoothen_frequency_image
%smoothens the frequency image through a process of diffusion
%Usage:
%new_oimg = smoothen_frequency_image(fimg,RLOW,RHIGH,diff_cycles)
%fimg       - frequency image image
%nimg       - filtered frequency image
%RLOW       - lowest allowed ridge separation
%RHIGH      - highest allowed ridge separation
%diff_cyles - number of diffusion cycles
%Contact:
%   ssc5@eng.buffalo.edu
%   www.eng.buffalo.edu/~ssc5
%Reference:
%S. Chikkerur, C.Wu and V. Govindaraju, "Systematic approach for feature
%extraction in Fingerprint Images", ICBA 2004
%------------------------------------------------------------------------
function nfimg = smoothen_frequency_image(fimg,RLOW,RHIGH,diff_cycles)
    valid_nbrs  =   3; %uses only pixels with more then valid_nbrs for diffusion
    [ht,wt]     =   size(fimg);
    nfimg       =   fimg;
    N           =   1;
    
    %---------------------------------
    %perform diffusion
    %---------------------------------
    h           =   fspecial('gaussian',2*N+1);
    cycles      =   0;
    invalid_cnt = sum(sum(fimg<RLOW | fimg>RHIGH));
    while((invalid_cnt>0 &cycles < diff_cycles) | cycles < diff_cycles)
        %---------------
        %pad the image
        %---------------
        fimg    =   [flipud(fimg(1:N,:));fimg;flipud(fimg(ht-N+1:ht,:))]; %pad the rows
        fimg    =   [fliplr(fimg(:,1:N)),fimg,fliplr(fimg(:,wt-N+1:wt))]; %pad the cols
        %---------------
        %perform diffusion
        %---------------
        for i=N+1:ht+N
         for j = N+1:wt+N
                blk = fimg(i-N:i+N,j-N:j+N);
                msk = (blk>=RLOW & blk<=RHIGH);
                if(sum(sum(msk))>=valid_nbrs)
                    blk           =blk.*msk;
                    nfimg(i-N,j-N)=sum(sum(blk.*h))/sum(sum(h.*msk));
                else
                    nfimg(i-N,j-N)=-1; %invalid value
                end;
         end;
        end;
        %---------------
        %prepare for next iteration
        %---------------
        fimg        =   nfimg;
        invalid_cnt =   sum(sum(fimg<RLOW | fimg>RHIGH));
        cycles      =   cycles+1;
    end;
%     cycles
%end function smoothen_orientation_image