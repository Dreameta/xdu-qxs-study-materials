function [F,H,XD,YD,ZD,D,I] = GCS2WGS(X,Y,Z,segma)
%将地心球坐标系下的地磁三分量转换为大地坐标系下的地磁分量
XD=X*cos(segma)+Z*sin(segma);
YD=Y;
ZD=-X*sin(segma)+Z*cos(segma);
F=sqrt(XD^2+YD^2+ZD^2);
H=sqrt(XD^2+YD^2);
D=acos(XD/H)*180/pi;
I=acos(H/F)*180/pi;
end