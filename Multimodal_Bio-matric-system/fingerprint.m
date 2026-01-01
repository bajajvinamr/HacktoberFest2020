close all;
clc;
clear all;

% selecting test image using prompt window

num_lines= 1;
def = {'1'};
prompt = {'Enter test image name (a number between 1 to 10):'}
dlg_title = 'Input FingerPrint Recognation System';
TestDb = uigetdir('C:\Users\Fathima\Desktop\thesis folder\test fp', 'Select test database path');
TestIm = inputdlg(prompt,dlg_title,num_lines,def)
TestIm = strcat(TestDb,'\',char(TestIm),'mbw.tif');

% Read test image

InputImage = imread(TestIm); 
  
% Covert to binary

 binary_image=im2bw(InputImage);

% Thinning

 thin_image=~bwmorph(binary_image,'thin',5);
 
  B= thin_image(20:270,20:270);
     
%selecting template path(10 templates(template names are 1.jpg, 2.jpg etc ))

 TemplatePath = uigetdir('C:\Users\Fathima\Desktop\thesis folder\modification\imt', 'Select template path'); 

Min=[];
 Cr=[];
 Cb=[];
NI=[];
NT=[];
SCORE=[];
  
 for z = 1 :10
     str = int2str(z);
     str = strcat('\',str,'.jpg');
     str = strcat(TemplatePath ,str);
     tem = imread(str);  % reading template
     T=im2bw(tem);

% for each template find the count of minutiae(Nt)  

 Nt=0;
  
[P Q]=size(T);
for r=1:P
    for s=1:Q
        if T(r,s)==0
            Nt=Nt+1;
        end
    end
end
NT=[NT Nt];
 
 
 % find the number of minutiae in input test image(Ni) and the count of minutiae that matches with template(MIN)
 
   [h w]=size(B);
   temp=~zeros(h,w);
   rid=~zeros(h,w);
   MIN=0;
   C1=0;
   C2=0;
   
   for i=2:h-1
       for j=2:w-1
             c=0;
           if B(i,j)==0
                for k=i-1:i+1
                    for l=j-1:j+1
                        if B(k,l)==0
                            c=c+1;  
                        end
                    end
                end
               if c==4
                   C1=C1+1;
                   temp(i,j)=B(i,j);
                    if B(i,j)==T(i,j)
                        MIN=MIN+1;
                    end
                   
               end
               if c==2
                   C2=C2+1;
                   rid(i,j)=B(i,j);
                   if B(i,j)==T(i,j)
                        MIN=MIN+1;
                    end
               end
           end
           
       end 
   end

%    Score=matching minutiae/max(NI,NT)
   
   Ni=C1+C2;
   NI=[NI Ni];
  Min=[Min MIN];
   Score=MIN/max(Ni,Nt);
   SCORE=[SCORE Score];
   
   Cr=[Cr C2];
  Cb=[Cb C1];
 
 
end
 
 [dis ind]=max(SCORE);
 
 
 
OutputName = strcat(int2str(ind),'mbw.tif');
  disp(OutputName);
figure;imshow(InputImage);title('test fingerprint');
SelectedImage = strcat(TestDb,'\',OutputName);
SelectedImage = imread(SelectedImage);
 
 
figure,imshow(SelectedImage);
title('Equivalent Image');
 
if dis >= 0.6
  display(' authenticated by fingerprint'); 
end
 
if dis < 0.6
  display('not authenticated by fingerprint'); 
end
    
 
 
 
 
 
 
 
 


