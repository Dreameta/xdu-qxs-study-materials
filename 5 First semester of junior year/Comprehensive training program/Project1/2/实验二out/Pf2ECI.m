function [Y1] = Pf2ECI (Y0, Kep)

% 开普勒参数
a = Kep(1);  Omega = Kep(4);
e = Kep(2);  omega = Kep(5);
i = Kep(3);  M0    = Kep(6);
% 坐标系转换
%%%继续编
R1=[cos(omega),sin(omega),0;-sin(omega),cos(omega),0;0,0,1];
R2=[1,0,0;0,cos(i),sin(i);0,-sin(i),cos(i)];
R3=[cos(Omega),sin(Omega),0;sin(-Omega),cos(Omega),0;0,0,1];
Tpi=R1*R2*R3;
Tip=inv(Tpi);
R=Tip*Y0(1:3);
V=Tip*Y0(4:6);
Y1=[R;V];

