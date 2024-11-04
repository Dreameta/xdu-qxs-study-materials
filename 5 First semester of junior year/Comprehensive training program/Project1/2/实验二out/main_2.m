clear ;
close all;
lati=34+1/60;
longi=108+8/60;
t=decyear(2022,10,1);
[G0,H0]=Get_GM();
h=0:10e3:36000e3;
for k=1:length(h)
    [F,H,XD,YD,ZD,D,I]=get_out(lati,longi,h(k),G0,H0);
    f(k)=F;
end
figure(1);
plot(h/1e3,f,'linewidth',1.6);
title("西安的地磁总强度随海拔变化曲线(108.8°，34.1°)")
ylabel('磁场总强度\nT');
xlabel('高度\m');
