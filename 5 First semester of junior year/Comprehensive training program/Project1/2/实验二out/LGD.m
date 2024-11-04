function [P,dP,seta] = LGD(fai)
%求解勒让德函数，输入fai是地心纬度
seta=pi/2-fai;
P=zeros(14,14);
dP=zeros(14,14);
P(1,1)=1;P(1,2)=0;P(2,1)=cos(seta);P(2,2)=sin(seta);
for i=3:14
    for j=1:i
        n=i-1;m=j-1;
        if i~=j
            P(i,j)=(2*n-1)/sqrt(n^2-m^2)*cos(seta)*P(i-1,j)-sqrt(((n-1)^2-m^2)/(n^2-m^2))*P(i-2,j);
        else
            P(i,j)=(2*n-1)/sqrt((n+m)*(n+m-1))*sin(seta)*P(i-1,j-1);
        end
    end
end
dP(1,1)=0;
for i= 2:14
    for j=1:i
        n=i-1;m=j-1;
        dP(i,j)=n*cos(seta)/sin(seta)*P(i,j)-sqrt(n^2-m^2)/sin(seta)*P(i-1,j);
    end
end




