/*
标题	
数列求和

类别
函数与递归

时间限制	
1S

内存限制	
1000Kb

问题描述	
有一分数序列：
2/1,3/2,5/3,8/5,13/8,21/13,......An/Bn
A1=2，A2=3，An=An-1+An-2；
B1=1，B2=2，Bn=Bn-1+Bn-2。
求出这个数列的前n(2<=n<=30)项之和。

输入说明	
一个整数n

输出说明	
输出一个实数表示数列前n项之和，结果保留2位小数（四舍五入）

输入样例	
2
输出样例	
3.50
*/

# include <stdio.h>

//函数：刻意用该函数来求此题中的前n项和； 
float Sn(float n)
{
	float Bn[31];
	float An[31];
	float Sn;
	
	An[0] = 2;
	An[1] = 3;
	
	Bn[0] = 1;
	Bn[1] = 2;
	
	if(n == 2)
		Sn = 3.50;
	else if(n > 2)
	{
		Sn = 3.50; 
		for( int i=2; i<n; i++)
		{
			An[i] = An[i-1] + An[i-2];
			Bn[i] = Bn[i-1] + Bn[i-2];
			Sn = Sn + (An[i]/Bn[i]);
		}		
	} 
	return Sn;
}

int main(void)
{
	float n;
	scanf("%f", &n);
	
	printf("%.2f", Sn(n)) ;
	
	return 0;
}
 
