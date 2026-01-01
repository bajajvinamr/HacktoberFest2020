function [d R Q]=mainedt6()

%% BUILD FINGERPRINT TEMPLATE DATABASE
% build_db(10,1);        %THIS WILL TAKE ABOUT 30 MINUTES
load('db4.mat');

%% EXTRACT FEATURES FROM AN ARBITRARY FINGERPRINT
num_lines= 1;
def = {'1'};
prompt = {'Enter test image name (a number between 1 to 40):'}
dlg_title = 'Input FingerPrint Recognation System';
TestDb = uigetdir('C:\Users\Keshav\Multimodal-MultiAlgorithmic_Biometric-Fusion-master\test fp\Databases\orl', 'Select test database path');
TestIm = inputdlg(prompt,dlg_title,num_lines,def)
filename = strcat(TestDb,'\',char(TestIm),'.tif');
%filename='101_1.tif';
img = imread(filename);
if ndims(img) == 3; img = rgb2gray(img); end  % Color Images
disp(['Extracting features from ' filename ' ...']);
ffnew=ext_finger(img,1);

%% FOR EACH FINGERPRINT TEMPLATE, CALCULATE MATCHING SCORE IN COMPARISION WITH FIRST ONE
S=zeros(40,1);
for i=1:40
%     second=['10' num2str(fix((i-1)/8)+1) '_' num2str(mod(i-1,8)+1)];
%     fprintf(['Computing similarity between ' filename ' and ' second ' from FVC2002 : ']);
    S(i)=match(ffnew,ff{i});
    fprintf([num2str(S(i)) '\n']);
    drawnow
end
%% OFFER MATCHED FINGERPRINTS
Matched_FingerPrints=find(S>0.42)
h=S(Matched_FingerPrints);
[maxval index]=max(S)
if (maxval<0.5)
    display('NOT AUTHENTICATED BY FINGERPRINT')
else display('AUTHENTICATED BY FINGERPRINT')
end
d=Matched_FingerPrints;
R=[]; %R is an array with first 8 high scores
Q=[];
for i=1:5
    [x v]=max(S);
    w=v;
    Q=[Q x];
    R=[R w];
    S(v)=0
    
end


%imposter 42,43