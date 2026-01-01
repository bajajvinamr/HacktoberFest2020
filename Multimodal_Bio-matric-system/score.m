% TRANSFORMED MINUTIAE MATCHING SCORE
%
% Usage:  [ si ] = score( T1, T2 );
%
% Argument:   T1 -  First  Transformed Minutiae 
%             T2 -  Second Transformed Minutiae
%               
% Returns:    sm - Similarity Measure

% Vahid. K. Alilou
% Department of Computer Engineering
% The University of Semnan
%
% July 2013

function [ sm ] = score( T1, T2 )
    Count1=size(T1,1); Count2=size(T2,1); n=0;
    T=15;  %Threshold for distance
    TT=14; %Threshold for theta
    for i=1:Count1
        Found=0; j=1;
        while (Found==0) && (j<=Count2)
            dx=(T1(i,1)-T2(j,1));
            dy=(T1(i,2)-T2(j,2));
            d=sqrt(dx^2+dy^2);    %Euclidean Distance between T1(i) & T2(i)
            if d<T
                DTheta=abs(T1(i,3)-T2(j,3))*180/pi;
                DTheta=min(DTheta,360-DTheta);
                if DTheta<TT
                    n=n+1;        %Increase Score
                    Found=1;
                end
            end
            j=j+1;
        end
    end
    sm=sqrt(n^2/(Count1*Count2));       %Similarity Index
end