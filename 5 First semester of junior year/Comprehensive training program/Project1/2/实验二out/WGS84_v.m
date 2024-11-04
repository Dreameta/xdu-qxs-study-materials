function [Longitude,Latitude,N,H]=WGS84_v(Y)
%%% Y为地固坐标系坐标矢量
%%%%%输出地理经纬度
%%%%继续编
xc=Y(1);
yc=Y(2);
zc=Y(3);
a=6378137.000;
f=1/298.257223563;
L=atan(yc/xc);
b=a*(1-f);
e1=sqrt(a*a-b*b)/b;
e=sqrt(a*a-b*b)/a;
seta=atan(zc*a/(sqrt(xc*xc+yc*yc)*b));

B=atan((zc+e1*e1*b*sin(seta)*sin(seta)*sin(seta))/(sqrt(xc*xc+yc*yc)-e*e*a*cos(seta)*cos(seta)*cos(seta)));
N=a/sqrt(1-e*e*sin(B)*sin(B));
H=sqrt(xc*xc+yc*yc)/cos(B)-N;

if (yc>0 && L<0)
    L=L+pi;
elseif (yc<0 && L>0)
    L=L-pi;
end
Longitude=L*180/pi;
Latitude=B*180/pi;



