clc;
close all;
clear all;
TrainDatabasePath = uigetdir('C:\Users\Fathima\Desktop\thesis folder\orl', 'Select training database path');
M=40;
N=9;
%P=2;
M1=M*N;
u=[];
 num_lines= 1;
def = {'1','10'};
prompt={'Enter test image name (a number between 1 to 40):','enter a no:between 1 to 10'};
dlg_title = 'Input of PCA-Based Face Recognition System';
 TestDatabasePath = uigetdir('C:\Users\Fathima\Desktop\thesis folder\orl', 'Select test database path');
 answer = inputdlg(prompt,dlg_title,num_lines,def);
x = str2num(answer{1}); 
 y = str2num(answer{2});
FT=[];
y=10;
TestImage= strcat('\S',sprintf('%d',x),'\',int2str(y),'.pgm');
TestImage = strcat(TestDatabasePath,TestImage);
gama=[];
for i=1:M
    for j=1:N
        if (i==x)&&(j==y)
            continue;
        end
        str = strcat('\S',sprintf('%d',i),'\',int2str(j),'.pgm');
        str = strcat(TrainDatabasePath,str);
         img = imread(str);
   
    temp=transpose(img);
    temp=reshape(temp,numel(temp),1);
   gama=[gama temp];
    end
end
mean_All= mean(gama,2);
A = [];  
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
 imshow(InputImage);title('Input Test Image');
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
        str =  strcat('Matched person is :  ',int2str(L));
        disp(str);
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
 for i=1:M1

     if ED(i)<=0.36
         INDEX=[INDEX i];
     end
 end
 T=size(INDEX,2)
 if T==0
  display('Not authenticated'); 
  break
 end
 k=pca281(INDEX,InputImage);
 [tem in]=min(k);
 %u=array containing index of first 10 min score
for i=1:8
[Euc_dist_min , I] = min(k);
fvi = INDEX(I);
FM=FINGERFIN5(fvi);
u=[u FM];
k(I)=1000

end
 
[d R]=mainedt6()
  g=size(d);
  c=0;
  for i=1:8
      for j=1:8
          if R(i)== u(j)
              c=1;
             str =  strcat('Matched person is :  ',int2str(u(j)));
             disp(str);
             display('Authenticated');
             break
          
          end
         
      end
     
  end
 if c==0
     display('NOT Authenticated');
 end


