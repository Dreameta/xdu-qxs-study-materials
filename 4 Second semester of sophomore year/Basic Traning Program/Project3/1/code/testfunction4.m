%%该程序的功能：产生不同探测面积A，不同脉冲星辐射流率下的噪声
%%输入参数 一个数据原文件
%%输出参数 原数据图 和 cftool拟合函数
%%编写人：王梦祥
%%编写日期：2022年5月20日15:50:22

clc
clear all
close all
%控制变量法
%2 带噪声的脉冲轮廓的分析与绘制
%探测面积、信号辐射流率、噪声辐射流率全部修改了一遍

%%信号生成：调整参数，调用函数
t = 0.0001:0.0001:0.0335;
A1 = 100;
A2 = 300;
A3 = 600;
rate_pulsal1 = 50;
rate_pulsal2 = 100;
rate_pulsal3 = 150;

Pulse_profile_1 = f_getconmod(A1,rate_pulsal1,t);
Pulse_profile_2 = f_getconmod(A2,rate_pulsal1,t);
Pulse_profile_3 = f_getconmod(A3,rate_pulsal1,t);
Pulse_profile_4 = f_getconmod(A1,rate_pulsal2,t);
Pulse_profile_5 = f_getconmod(A2,rate_pulsal2,t);
Pulse_profile_6 = f_getconmod(A3,rate_pulsal2,t);
Pulse_profile_7 = f_getconmod(A1,rate_pulsal3,t);
Pulse_profile_8 = f_getconmod(A2,rate_pulsal3,t);
Pulse_profile_9 = f_getconmod(A3,rate_pulsal3,t);

%噪声生成
rate_noise1 = 30;
rate_noise2 = 150;
rate_noise3 = 300;

Noise_profile_1 = f_getnoicon(A1,rate_pulsal1,rate_noise1,t);
Noise_profile_2 = f_getnoicon(A2,rate_pulsal1,rate_noise1,t);
Noise_profile_3 = f_getnoicon(A3,rate_pulsal1,rate_noise1,t);
Noise_profile_4 = f_getnoicon(A1,rate_pulsal2,rate_noise2,t);
Noise_profile_5 = f_getnoicon(A2,rate_pulsal2,rate_noise2,t);
Noise_profile_6 = f_getnoicon(A3,rate_pulsal2,rate_noise2,t);
Noise_profile_7 = f_getnoicon(A1,rate_pulsal3,rate_noise3,t);
Noise_profile_8 = f_getnoicon(A2,rate_pulsal3,rate_noise3,t);
Noise_profile_9 = f_getnoicon(A3,rate_pulsal3,rate_noise3,t);

%信号和噪声叠加
Pulse_Noise_1 = Pulse_profile_1 + Noise_profile_1;PN1 = [t; Pulse_Noise_1].';save Pulse_Noise_1.txt -ascii PN1;save ('Pulse_Noise_1.mat','PN1');
Pulse_Noise_2 = Pulse_profile_2 + Noise_profile_2;PN2 = [t; Pulse_Noise_2].';save Pulse_Noise_2.txt -ascii PN2;save ('Pulse_Noise_2.mat','PN2');
Pulse_Noise_3 = Pulse_profile_3 + Noise_profile_3;PN3 = [t; Pulse_Noise_3].';save Pulse_Noise_3.txt -ascii PN3;save ('Pulse_Noise_3.mat','PN3');
Pulse_Noise_4 = Pulse_profile_4 + Noise_profile_4;PN4 = [t; Pulse_Noise_4].';save Pulse_Noise_4.txt -ascii PN4;save ('Pulse_Noise_4.mat','PN4');
Pulse_Noise_5 = Pulse_profile_5 + Noise_profile_5;PN5 = [t; Pulse_Noise_5].';save Pulse_Noise_5.txt -ascii PN5;save ('Pulse_Noise_5.mat','PN5');
Pulse_Noise_6 = Pulse_profile_6 + Noise_profile_6;PN6 = [t; Pulse_Noise_6].';save Pulse_Noise_6.txt -ascii PN6;save ('Pulse_Noise_6.mat','PN6');
Pulse_Noise_7 = Pulse_profile_7 + Noise_profile_7;PN7 = [t; Pulse_Noise_7].';save Pulse_Noise_7.txt -ascii PN7;save ('Pulse_Noise_7.mat','PN7');
Pulse_Noise_8 = Pulse_profile_8 + Noise_profile_8;PN8 = [t; Pulse_Noise_8].';save Pulse_Noise_8.txt -ascii PN8;save ('Pulse_Noise_8.mat','PN8');
Pulse_Noise_9 = Pulse_profile_9 + Noise_profile_9;PN9 = [t; Pulse_Noise_9].';save Pulse_Noise_9.txt -ascii PN9;save ('Pulse_Noise_9.mat','PN9');


%%画出带噪声的信号图像
figure(1)
subplot(3,3,1);plot(t,Pulse_Noise_1,'-');title('A1=100cm^2，rate_pulsal1=50ph/s/cm^2，rate_noise1 = 30ph/s/cm^2');
subplot(3,3,2);plot(t,Pulse_Noise_2,'-');title('A2=150cm^2，rate_pulsal1=50ph/s/cm^2，rate_noise1 = 30ph/s/cm^2');
subplot(3,3,3);plot(t,Pulse_Noise_3,'-');title('A3=300cm^2，rate_pulsal1=50ph/s/cm^2，rate_noise1 = 30ph/s/cm^2');
subplot(3,3,4);plot(t,Pulse_Noise_1,'-');title('A1=100cm^2，rate_pulsal2=100ph/s/cm^2，rate_noise2 = 100ph/s/cm^2');
subplot(3,3,5);plot(t,Pulse_Noise_4,'-');title('A2=150cm^2，rate_pulsal2=100ph/s/cm^2，rate_noise2 = 100ph/s/cm^2');
subplot(3,3,6);plot(t,Pulse_Noise_4,'-');title('A3=300cm^2，rate_pulsal2=100ph/s/cm^2，rate_noise2 = 100ph/s/cm^2');
subplot(3,3,7);plot(t,Pulse_Noise_4,'-');title('A1=100cm^2，rate_pulsal3=150ph/s/cm^2，rate_noise3 = 300ph/s/cm^2');
subplot(3,3,8);plot(t,Pulse_Noise_4,'-');title('A2=150cm^2，rate_pulsal3=150ph/s/cm^2，rate_noise3 = 300ph/s/cm^2');
subplot(3,3,9);plot(t,Pulse_Noise_4,'-');title('A3=300cm^2，rate_pulsal3=150ph/s/cm^2，rate_noise3 = 300ph/s/cm^2');


