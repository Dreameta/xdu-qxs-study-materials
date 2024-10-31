%%该程序的功能：计算SNR并绘制SNR随信号和噪声射流率的关系
%%输入参数 无  
%%输出参数 三维数据图  
%%编写人：王梦祥  
%%编写日期：2022年5月20日19:19:31  

clc
clear all
close all

t = 0:0.0335/99:0.0335;
A = 200; %only one 
rate_pulsar = 15:135/99:150;
rate_nosie = 30:270/99:300;

% for i = 1:100
%     for j = 1:100
%         U_signal = sum(f_getconmod(A,rate_pulsar(i),t));
%         U_noise = sum(f_getnoicon(A,rate_pulsar(i),rate_nosie(j),t));
%         SNR1(i,j) = 20*log10(U_signal/(U_noise-U_signal));
%     end
% end

for i = 1:100
    for j = 1:100
        U_signal = sum(f_getconmod(A,rate_pulsar(i),t));
        U_noise = sum(f_getnoicon(A,rate_pulsar(i),rate_nosie(j),t));
        SNR1(i,j) = 20*log10(U_signal/(U_noise-U_signal));
    end
end


mesh (rate_nosie, rate_pulsar,SNR1);
xlabel("噪声辐射率");
ylabel("脉冲星辐射流率");
zlabel("信噪比SNR");
title("信噪比随脉冲星辐射流率和噪声辐射流率变化的三维趋势图");

