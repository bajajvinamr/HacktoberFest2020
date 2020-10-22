clc;
close all;
clear all;
TemplatePath = uigetdir('C:\Users\Fathima\Desktop\train', 'Select template path');
    
    for i=1:30
            str = int2str(i);
     str = strcat('\',str,'.tif');
     str = strcat(TemplatePath ,str);
     img = imread(str);
     if ndims(img) == 3; img = rgb2gray(img); end   % colour image
            %disp(['extracting features from ' filename ' ...']);
            ff{i}=ext_finger(img,1);
        
    end
    save('db1.mat','ff');
