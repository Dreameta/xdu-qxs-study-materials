function [Y] = State (gm, Kep, dt)

% 开普勒参数
a = Kep(1);  Omega = Kep(4);
e = Kep(2);  omega = Kep(5);
i = Kep(3);  M0    = Kep(6);

% 平近点角
if (dt==0.0)
  M = M0;
else
  n = sqrt(gm/(a*a*a)); %平均角速度
  M = M0 +n*dt; %平近点角
end

% 偏近点角
E = EccAnom(M,e);
%%%%%继续编
% 卫星至地星距离R和速度V
 R=a*(1-e*cos(E));
 V=sqrt(gm*a)/R;

%真近点角seta
seta=atan(sqrt((1+e)/(1-e))*tan(E/2))*2;

%卫星在近焦点坐标系中的坐标
xp=R*cos(seta);
yp=R*sin(seta);
zp=0;
vxp=-V*sin(E);
vyp=V*sqrt(1-e*e)*cos(E);
vzp=0;
Y=[xp;yp;zp;vxp;vyp;vzp];
