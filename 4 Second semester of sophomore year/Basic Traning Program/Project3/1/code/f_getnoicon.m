%%该程序的功能：产生不同探测面积A，不同脉冲星辐射流率下的噪声
%%输入参数 一个数据原文件
%%输出参数 原数据图 和 cftool拟合函数
%%编写人：王梦祥
%%编写日期：2022年5月20日15:50:22
%%

function ft = f_getnoicon(A, rate_pulsar, rate_nosie, t)

Va = A* rate_pulsar;
Vb = A * rate_nosie;
ft = Va* f_getproden(t) + Vb; 
