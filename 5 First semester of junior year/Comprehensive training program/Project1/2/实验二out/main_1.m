
clear ;
close all;
x=xlsread('20组数据');
[G0,H0]=Get_GM();

for k=1:20
    FAI=x(k,1);lambada=x(k,2); h=x(k,3);year=x(k,4);month=x(k,5);day=x(k,6);
    [XYZ,H1,D1,I1,F1]=igrfmagm(h,FAI,lambada,decyear(year,month,day),13);

    [F,H,XD,YD,ZD,D,I]=get_out(FAI,lambada,h,G0,H0);

    result(k,1)=XYZ(1);result(k,2)=XD;  error(k,1)=XYZ(1)-XD;%北向分量
    result(k,3)=XYZ(2);result(k,4)=YD;  error(k,2)=XYZ(2)-YD;%东向分量
    result(k,5)=XYZ(3);result(k,6)=ZD;  error(k,3)=XYZ(3)-ZD;%垂直分量
    result(k,7)=F1;    result(k,8)=F;   error(k,4)=F1-F;     %磁场总强度
    result(k,9)=H1;    result(k,10)=H;  error(k,5)=H1-H;     %水平强度
    result(k,11)=D1;   result(k,12)=D;  error(k,6)=D1-D;     %磁偏角
end

title1={'北向分量标准值','北向分量计算值','东向分量标准值','东向分量计算值','垂直分量标准值','垂直分量计算值'...
       '磁场总强度标准值','磁场总强度计算值','水平强度标准值','水平强度计算值','磁偏角标准值','磁偏角计算值' };
xlswrite('compar.xls',title1,'sheet1');
xlswrite('compar.xls',result,'sheet1','A2');

figure(1);
plot(error(:,1),'LineWidth',1.5)
hold on
plot(error(:,2),'LineWidth',1.5)
plot(error(:,3),'m','LineWidth',1.5)
axis([0 20 -1500 1500]);
grid on
legend('北向分量','东向分量','垂直分量')
xlabel('输入数据序号')
ylabel('误差/nT')
title('标准值与计算值的误差')

figure(2);
subplot(3,1,1);
plot(error(:,4),'LineWidth',1.5)
axis([0 20 -300 300]);
legend('磁场总强度')
xlabel('输入数据序号')
ylabel('误差/nT')
title('标准值与计算值的误差')

subplot(3,1,2);
plot(error(:,5),'r','LineWidth',1.5)
axis([0 20 -300 300]);
legend('水平强度')
xlabel('输入数据序号')
ylabel('误差/nT')
title('标准值与计算值的误差')

subplot(3,1,3);
plot(error(:,6),'m','LineWidth',1.5)
axis([0 20 -300 300]);
legend('磁偏角')
xlabel('输入数据序号')
ylabel('误差')
title('标准值与计算值的误差')

% lati=34+7/60+29/3600;
% longi=108+50/60+3/3600;
% h=0:10e3:36000e3;
% for k=1:length(h)
%     [F,H,XD,YD,ZD,D,I]=get_out(lati,longi,h(k),G0,H0);
%     f(k)=F;
% end
% figure(1);
%plot(h/1e3,f,'linewidth',1.6);
