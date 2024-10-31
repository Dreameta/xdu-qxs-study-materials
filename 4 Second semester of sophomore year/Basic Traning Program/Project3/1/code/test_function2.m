clc
clear all
close all

%%调整参数，调用函数
a = 0.0001:0.0001:0.0335;

%千万注意：修改输入参数时，要记得修改输出文件内容
%A1 = 100;
%A2 = 150;
A3 = 200;
%rate_pulsal1 = 15;
rate_pulsal2 = 30;

b = f_getconmod(A3,rate_pulsal2,a);

c = [a;b].' %合并时间和轮廓数据

%%画出图像
%plot(a,b,'-');

%%写入txt文件
%dlmwrite('A3rate_pulsal2.txt',c,'delimiter','\t','precision',8);
save testfile.txt -ascii c
save ('testmat.mat','c');
