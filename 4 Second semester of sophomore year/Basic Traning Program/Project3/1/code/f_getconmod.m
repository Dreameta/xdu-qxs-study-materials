%%该程序的功能：产生不同探测面积A，不同脉冲星辐射流率下的脉冲星轮廓模型
%%输入参数 一个数据原文件
%%输出参数 原数据图 和 cftool拟合函数
%%编写人：王梦祥
%%编写日期：2022年5月20日14:19:31
%%
function ft = f_getconmod(A, rate_pulsar, x)

Va = A* rate_pulsar;
ft = Va * f_getproden(x); 


