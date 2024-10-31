%% 本程序的功能：对一定观测时间下的脉冲星实测的数据：光子到达时间进行不同 bin 块下的轮廓累积并加入功率为-20dB的高斯白噪声
%% 输入参数：光子达到时间
%% 输出参数：信号轮廓波形
%% 编写人：王梦祥
%% 编写日期：2022年6月7日16:28:42
%%

clc 
clear all 
close all 

x = importdata('90802-02-04-00.mat');
datatime=x-x(1);
L=length(x);

snr=0;

tobs=datatime(L)-datatime(1);
Nbin=[256,512,1024,1024*10];
P=1/29.79123091;


for i=1:4
    
        Tbin=P/Nbin(i);
        LOC=ceil((datatime-floor(datatime./P).*P)./Tbin);
        f=hist(LOC,Nbin(i));
    
end



for i=1:4
    
        Tbin=P/Nbin(i);
        DATA=ceil((datatime-floor(datatime./P).*P)./Tbin);
        f=hist(DATA,Nbin(i));
        f1=awgn(f,snr,'measured');

        %f1=awgn(f,snr);
%       TT =[P/Nbin(i):P/Nbin(i):P];

%         %测试：高斯去噪对数据的去噪方式
%         g=fspecial('gaussian',[1 2],1.5);
%         y1=conv(f1,g);
%         g=fspecial('gaussian',[1 6],1.5);
%         y2=conv(f1,g);
%         %依旧存在下划线，因此需要对其原理进行进一步的探究

        subplot(2,2,i);
        plot(f1,'b-');
%         hold on
%         plot(y1,'r-');
%         hold on
%         plot(y2,'g-');
        
        xlabel('X射线脉冲星信号总观测时间');
        ylabel('第一个周期内的光子数');
        title(sprintf('加入%ddB高斯白噪声的脉冲星信号的轮廓累积/Nbin=%d',snr,Nbin(i)));   


end



