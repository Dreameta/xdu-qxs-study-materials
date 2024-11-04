function [fai,lambada,r,segma] = WGS2GCS(FAI,lambada,h)
%地理坐标转地心坐标
%输入为：FAI是地理纬度，lambada是地理经度，h是高度
%输出为：fai是地心纬度,lambada是地心经度,r是测点离开地心的距离
FAI=FAI*pi/180;
lambada=lambada*pi/180;
%角度转弧度
a=6378137.000;
b=6356752.300;
r=sqrt(h*(h+2*sqrt(a^2*cos(FAI)^2+b^2*sin(FAI)^2))+(a^4*cos(FAI)^2+b^4*sin(FAI)^2)/(a^2*cos(FAI)^2+b^2*sin(FAI)^2));
segma=acos((h+sqrt(a^2*cos(FAI)^2+b^2*sin(FAI)^2))/r);
fai=FAI-segma;
end


