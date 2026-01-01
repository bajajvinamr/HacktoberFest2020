%-----Sub functions-------
function [j,X, Y] = p(img, x, y, i)
% get pixel value based on chart:
%  4 | 3 | 2
%  5 |   | 1
%  6 | 7 | 8

switch (i)
    case {1, 9}
        Y=y;
        X=x+1;
        j = img(y, x + 1);
    case 2
        Y=y-1;
        X=x+1;
        j = img(y - 1, x + 1);
    case 3
        Y=y-1;
        X=x;
        j = img(y - 1, x);
    case 4
        Y=y-1;
        X=x-1;
        j = img(y - 1, x - 1);
    case 5
        Y=y;
        X=x-1;
        j = img(y, x - 1);
    case 6
        Y=y+1;
        X=x-1; 
        j = img(y + 1, x - 1);
    case 7
        Y=y+1;
        X=x;
        j = img(y + 1, x);
    case 8
        Y=y+1;
        X=x+1; 
        j = img(y + 1, x + 1);
end

