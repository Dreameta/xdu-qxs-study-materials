/*
	标题:	
	排序2
	
	类别:
	数组
	
	时间限制	
	2S
	
	内存限制	
	1000Kb
	
	问题描述：	
	给定N个不同的整数，要求对这N个整数按如下规则排序并输出。
	规则一：所有的偶数排在奇数前面。
	规则二：在规则一的前提下按照从大到小的顺序排序。
	
	输入说明	
	数据由两行构成，第一行为整数n（n<=100），表示待排序整数的数量。第二行是n个整数，每个整数的取值区间都为[-32768~32767]，整数之间以空格间隔。
	
	输出说明	
	在一行输出排好序的整数，整数之间以空格间隔。
	
	输入样例	
	5 
	1 2 3 4 5
	
	输出样例	
	4 2 5 3 1
*/

//分析学习程序
#include <stdio.h>

int main()
{
	/*输入数据1*/
	int n; 
	scanf("%d",&n);
	
	/*输入数据2*/
	//这里的输入的同时也将奇偶数直接分类，存入对应数组（数据结构）中 
	int num1=0, num2=0;
	int a[100]={0} ,b[100]={0}, c[100]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2 == 0)
		{
			b[num1] = a[i];
			num1 += 1;
		}
		else
		{
			c[num2]=a[i];
			num2 += 1;
		}
	}

	//分别将奇、偶数进行排序 
	
	//警醒：也许有些内容就是原来的内容，需要自己潜心默默进行分析 

	for(int i=0; i<num1; i++)
		for(int j=i+1; j<num1; j++)
			if(b[j] > b[i])
			{
				int t = b[j];
				b[j] = b[i];
				b[i] = t;
			}
	
	for(int i=0; i<num2; i++)
		for(int j=i+1; j<num2; j++)
			if(c[j] > c[i])
			{
				int t = c[j];
				c[j] = c[i];
				c[i] = t;
			}
	
	//按序排列数据 
	for(int i=0; i<num1; i++)
		printf("%d ",b[i]);	
	for(int i=0; i<num2; i++)
		printf("%d ",c[i]);
		
	return 0;
 } 











/* 自己编写的程序 
int main(void)
{
	int n;
	scanf("%d", &n);
	int m[100];
	for (int i=0; i<n; i++)
	{
		scanf("%d", &m[i]);
	}
	
	for(int i=0; i<n; i++)
	{
		if(m[i]%2 == 0) //选出奇数并排序 
		{
			//这里是排序 
			for(int j=0; j<n; j++)
			{
				if(m[j] == m[])
				
				for(int k=j; k<n; k++)
				{
					
				}
			}
		}
	}
	
	
	
	
	return 0;
}
*/
































