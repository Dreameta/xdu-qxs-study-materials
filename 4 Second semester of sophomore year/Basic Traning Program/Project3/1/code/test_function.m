clc
clear all
close all

%% 画函数的图像
a = 0:0.0001:0.0335
b = f_getproden(a)
plot(a,b,'-');

%% 检测两个曲线重合度
hold on

data = load("data.txt");

plot(data(:,1), data(:,2), 'bo')
xlabel("一个周期的时间/s");
ylabel("光子到达概率");

%% 检测两组数据的误差
data = load("data.txt");
c = f_getproden(data(:,1)) - data(:,2);
plot(data(:,1), c, '-');

