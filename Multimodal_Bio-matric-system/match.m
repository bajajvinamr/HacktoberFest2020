

function [ S ] = match( M1, M2, display_flag )
    if nargin==2; display_flag=0; end
    M1=M1(M1(:,3)<5,:);
    M2=M2(M2(:,3)<5,:);    
    count1=size(M1,1); count2=size(M2,1); 
    bi=0; bj=0; ba=0; % Best i,j,alpha
    S=0;            % Best Similarity Score
    for i=1:count1
        T1=transform(M1,i);
        for j=1:count2
            if M1(i,3)==M2(j,3)
                T2=transform(M2,j);
                for a=-5:5                      %Alpha
                    T3=transform2(T2,a*pi/180);
                    sm=score(T1,T3);
                    if S<sm
                        S=sm;
                        bi=i; bj=j; ba=a;
                    end                
                end
            end
        end
    end
    if display_flag==1
        figure, title(['Similarity Measure : ' num2str(S)]);
        T1=transform(M1,bi);
        T2=transform(M2,bj);
        T3=transform2(T2,ba*pi/180);
        plot_data(T1,1);
        plot_data(T3,2);
    end
end