%% 本程序的功能：对一定观测时间下的脉冲星实测的数据：光子到达时间进行不同 bin 块下的轮廓累积
%% 输入参数：光子达到时间
%% 输出参数：信号轮廓波形
%% 编写人：王梦祥
%% 编写日期：2022年6月7日16:08:49
%%

clc 
clear all 
close all

x = importdata('90802-02-04-00.mat');
datatime=x-x(1);
L=length(x);
tobs=datatime(L)-datatime(1);

Nbin=[256,512,1024,1024*10];

P=1/29.79123091;

for i=1:4

    i %对应的i次

    Tbin=P/Nbin(i); %将周期分为Nbin份

    LOC=ceil((datatime-floor(datatime./P).*P)./Tbin); 

    f=hist(LOC,Nbin(i));

    %去噪部分

    %高斯去噪
    g=fspecial('gaussian',[1 50],1.5);
    y1=conv(f,g);
    y1 = imgaussfilt(f,2);
    %y1 = y5[2:256];
    corfy1 = corrcoef(f, y1)
    %rmse = sqrt(mean((YPred-Obverval).^2));
    rmse = sqrt(mean((f-y1).^2))

    
    %均值
    y2 = movmean(f,5);
    corfy2 = corrcoef(f, y2)
    rmse = sqrt(mean((f-y2).^2))


    %小波去噪
    y3 = wden(f,'sqtwolog','h','mln',5,'sym8');
    corfy3 = corrcoef(f, y3)
    rmse = sqrt(mean((f-y3).^2))

    subplot(2,2,i);
    plot(f,'k-'); %原信号

    hold on
    plot(y1,'b-');
    hold on
    plot(y2,'g-');
    hold on
    plot(y3,'r-');


    xlabel('X射线脉冲星信号总观测时间');
    ylabel('第一个周期内的光子数');
    title(sprintf('脉冲星信号的轮廓累积/Nbin=%d',Nbin(i)));


end