% COORDINATION TRANSFORM FUNCTION
%
% Usage:  [ Tnew ] = transform2( T, alpha );
%
% Argument:   T     - Transformed Minutiae
%             alpha - Rotation angle
%               
% Returns:    Tnew  - T with new coordinations

% Vahid. K. Alilou
% Department of Computer Engineering
% The University of Semnan
%
% July 2013

function [ Tnew ] = transform2( T, alpha )
    Count=size(T,1);
    Tnew=zeros(Count,4);
    R=[cos(alpha) sin(alpha) 0 0;...
      -sin(alpha) cos(alpha) 0 0;...
      0 0 1 0; 0 0 0 1];             % Transformation Matrix
    for i=1:Count
        B=T(i,:)-[0 0 alpha 0];
        Tnew(i,:)=R*B';
    end
end