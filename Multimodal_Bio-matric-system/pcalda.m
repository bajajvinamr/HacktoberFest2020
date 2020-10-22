clc;%for clear the WINDOW OPENED
close all;%close all
clear all;%cLEAR all the Matrix
TrainDatabasePath = uigetdir('C:\Users\Keshav\Multimodal-MultiAlgorithmic_Biometric-Fusion-master\test fp\Databases\orl', 'Select training database path');
M=40;%Size of the image in pixel
N=9;
%P=2;
M1=M*N;
gama=[];%initialization
num_lines= 1;
def = {'1','10'};
prompt={'Enter test image name (a number between 1 to 40):'};
dlg_title = 'Input of PCA-Based Face Recognition System';%Principal Component Analysis (PCA) is a method for compressing high dimensional databases [1]. If it used for image compression
TestDatabasePath = uigetdir('C:\Users\Keshav\Multimodal-MultiAlgorithmic_Biometric-Fusion-master\test fp\Databases\orl', 'Select test database path');
answer = inputdlg(prompt,dlg_title,num_lines,def);
x = str2num(answer{1});%converting string to number(pixels)  
y = str2num(answer{2});
TestImage= strcat('\s',sprintf('%d',x),'\',int2str(y),'.pgm');%pgm defiened as portable grey mapping
TestImage = strcat(TestDatabasePath,TestImage);%Testing the image from data base.
for i=1:M %looping
    for j=1:N 

        str = strcat('\s',sprintf('%d',i),'\',int2str(j),'.pgm');%Here concation the file of image integer to string
        str = strcat(TrainDatabasePath,str);
         img = imread(str);%reading the image
   
    temp=transpose(img);
    temp=reshape(temp,numel(temp),1);
   gama=[gama temp];
    end
end
mean_All= mean(gama,2);%taking the mean of every pixels
A = [];  %Initialization of the variable  
for i = 1 : M1
    t = double(gama(:,i)) - mean_All;
    A = [A t];
end
L=A'*A;
[V D] = eig(L);
L_eig_vec = [];

for i=360:-1:320;
   
        L_eig_vec = [L_eig_vec V(:,i)];
   
end
Eigenfaces = A * L_eig_vec; 
 
 ProjectedImages_PCA= [];
 for i = 1 :M1
    temp = Eigenfaces'*A(:,i); % Projection of centered images into facespace
    ProjectedImages_PCA = [ProjectedImages_PCA temp]; 
 end
 P=M*N;
 Class_population=N;
 Class_number=M;
 m_PCA = mean(ProjectedImages_PCA,2); % Total mean in eigenspace
m = zeros(41,Class_number); 
Sw = zeros(41,41); % Initialization os Within Scatter Matrix
Sb = zeros(41,41); % Initialization of Between Scatter Matrix

 for i = 1 : Class_number
    m(:,i) = mean( ( ProjectedImages_PCA(:,((i-1)*Class_population+1):i*Class_population) ), 2 )';    
    
    S  = zeros(41,41); 
    for j = ( (i-1)*Class_population+1 ) : ( i*Class_population )
        S = S + (ProjectedImages_PCA(:,j)-m(:,i))*(ProjectedImages_PCA(:,j)-m(:,i))';
    end
    
    Sw = Sw + S; % Within Scatter Matrix
Sb = Sb + Class_number*((m(:,i)-m_PCA) * (m(:,i)-m_PCA)'); % Between Scatter Matrix
end
 [J_eig_vec, J_eig_val] = eig(Sb,Sw); % Cost function J = inv(Sw) * Sb
J_eig_vec = fliplr(J_eig_vec);

%%%%%%%%%%%%%%%%%%%%%%%% Eliminating zero eigens and sorting in descend order
for i = 1 : Class_number-1 
    V_Fisher(:,i) = J_eig_vec(:,i); % Largest (C-1) eigen vectors of matrix J
end
 
for i = 1 : Class_number*Class_population
    ProjectedImages_Fisher(:,i) = V_Fisher' * ProjectedImages_PCA(:,i);
end
 InputImage= imread(TestImage);
 figure;
 imshow(InputImage);title('Input Test Image');%taking the input as image
 temp = InputImage(:,:,1);
[irow icol] = size(temp);
InImage = reshape(temp',irow*icol,1);
Difference = double(InImage)- mean_All; % Centered test image
ProjectedTestImage = V_Fisher' * Eigenfaces' * Difference; % Test image feature vectorED = [];
ED=[];
for i=1:M1
    
q = ProjectedImages_Fisher(:,i);
d= ProjectedTestImage - q;
d1=sum(d.*d);
ED=[ED d1];
end
[Euc_dist_min , Recognized_index] = min(ED);
n = Recognized_index;
for L=1:M
    if n<=9*L
        str =  strcat('Matched person is :  ',int2str(L));%result has been showed in connsole part 
        disp(str);%displayig the image in string either its is authenticated or not
        break
    end
end

b= mod(n,9);
if b==0
    b=9;
end

outputname= strcat('\S',sprintf('%d',L),'\',int2str(b),'.pgm');
disp(outputname);
outputname = strcat(TestDatabasePath,outputname);
outputname=imread(outputname);
figure,imshow(outputname);
title('Matched Image');
INDEX=[];

 u=[];
 t=[];
 for i=1:5
[Euc_dist_min , Recognized_index] = min(ED);
n = Recognized_index;
u=[u n];
t=[t Euc_dist_min];
ED(n)=100
end
 INDEX=u;
 T=size(INDEX,2)
 if T==0
  display('Not authenticated'); 
  break
 end
 
 FT=[];
for i=1:5
fvi=u(i);
  FM=FINGERFIN5(fvi);
  FT=[FT FM];
end
%disp(FT);
[d R Q]=mainedt6()
d1=[];
FD=[];
c=0;
 for i=1:5
     for j=1:5
         if FT(i)==R(j)
             c=1;
             d1=[d1 FT(i)];
             Fsc=(1-t(i))+Q(j)
             FD=[FD Fsc]; 
             display('AUTHENTICATED');
         end
     end
 end
 if c==0
     display('NOT AUTHENTICATED');
 end
[q v]=max(FD);
r=d1(v);
if c==1
str =  strcat('Matched person is :  ',int2str(r));
disp(str);
end