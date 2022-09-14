t = 0:0.0335/99:0.0335;
A=300;
rate_pulsar=100;
rate_nosie=150;

X = f_getnoicon(A,rate_pulsar,rate_nosie,t);    %产生含信号噪声

Y1 = awgn(X,-30,'measured');                     %加入信噪比为10db的噪声，加入前预估信号的功率（强度）

%Y_Gauss = [t; Y].';save Y_Gayss.txt -ascii Y_Gauss;save ('Y_Gayss.mat','Y_Gauss');
Y2 = awgn(X,30,'measured');
Y3 = awgn(X,60,'measured');

% %%验证
% sigPower = sum(abs(X).^2)/length(X)             %求出信号功率
% noisePower=sum(abs(Y-X).^2)/length(Y-X)         %求出噪声功率
% SNR=10*log10(sigPower/noisePower)               %由信噪比定义求出信噪比，单位为db

%%接下来进行去噪
Y4 = movmean(Y2,5);

%画图
subplot(1,3,1);plot(t,Y1,'-');
subplot(1,3,2);plot(t,Y2,t,Y4);
subplot(1,3,3);plot(t,Y3,'-');
%figure(1);
%plot(t,Y4,'-');







