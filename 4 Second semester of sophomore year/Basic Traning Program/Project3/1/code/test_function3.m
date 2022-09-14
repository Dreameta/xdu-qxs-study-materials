clc
clear all
close all
%控制变量法
%1 不带噪声的脉冲轮廓的分析与绘制

%%调整参数，调用函数
t = 0.0001:0.0001:0.0335;
A1 = 100;
A2 = 150;
A3 = 200;
rate_pulsal1 = 15;
rate_pulsal2 = 30;

Pulse_profile_1 = f_getconmod(A1,rate_pulsal1,t);
Pulse_profile_2 = f_getconmod(A2,rate_pulsal1,t);
Pulse_profile_3 = f_getconmod(A3,rate_pulsal1,t);
Pulse_profile_4 = f_getconmod(A1,rate_pulsal2,t);
Pulse_profile_5 = f_getconmod(A2,rate_pulsal2,t);
Pulse_profile_6 = f_getconmod(A3,rate_pulsal2,t);

%%画出图像
figure(1)
subplot(2,3,1);plot(t,Pulse_profile_1,'r-',t,Pulse_profile_4,'b-');title('A1=100cm^2不变，改变辐射频率');
subplot(2,3,2);plot(t,Pulse_profile_2,'r-',t,Pulse_profile_5,'b-');title('A2=150cm^2不变，改变辐射频率');
subplot(2,3,3);plot(t,Pulse_profile_3,'r-',t,Pulse_profile_6,'b-');title('A3=200cm^2不变，改变辐射频率');
subplot(2,3,4);plot(t,Pulse_profile_1,'r-',t,Pulse_profile_2,'b-',t,Pulse_profile_3,'g-');title('rate_pulsar=15ph/s/cm^2不变，改变探测面积');
subplot(2,3,5);plot(t,Pulse_profile_4,'r-',t,Pulse_profile_5,'b-',t,Pulse_profile_6,'g-');title('rate_pulsar=30ph/s/cm^2不变，改变探测面积');























