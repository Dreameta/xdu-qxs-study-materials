#include<stdio.h>
#include<string.h>
int main()
{
	/*数据输入*/
	char s[19];
	gets(s);
	
	int sum1, sum2; 
	int k,n=0; 
	int flag = 0; //作为标记，是否为相邻的数。
	
	/*第一个循环：把其中的两个数字找出来*/ 
	for(int i=0; i<strlen(s); i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			n = n*10 + (s[i]-'0'); //重点注意：这里的步骤是数组储存多位数求值必要的步骤 
			
			if(i == strlen(s)-1) //特殊形式：如果n满足这个形式，那么就说明是数字在最后的情况且到底了。 
				sum2 = n;
			else
				if ( (s[i+1]<'0') || (s[i+1]>'9') ) //判断下一位是否为非数字； 
				{
					if (flag==0) //若成立，说明不是相邻数，则直接把第一个数赋值给sum1，得到第一个数。
								//注意：这里标记的限制是只适用于两种情况（即两位数）的情况。如果想要三位数，四位数等等需要进一步的分类标志符。
								//当然也可以找寻更好的算法 
					{
						sum1 = n;
						n = 0;
						flag = 1;	
					}
					else 
						sum2 = n; //这里的n其实是两个循环获得的结果，即两位数 
				}
		}
		
		else continue; //只要不是数字，则进入下一个循环 
	}
	
	/*第二个循环：找出对应的运算符*/ 
	for(int i=0; i<strlen(s); i++)
	{
		if((s[i]<'0') || (s[i]>'9') && s[i] != ' ') //从左到右执行：先|| 后&& 
		{
			if(s[i] == '+') 
				k = sum1 + sum2;
			else if(s[i] == '-') 
				k = sum1 - sum2;
			else if(s[i] == '*') 
				k = sum1 * sum2;
			else if(s[i] == '/') 
				k = sum1 / sum2;
			else if(s[i] == '%') 
				k = sum1 % sum2;
		}
	}
	printf("%d",k);
	
	return 0;
 } 

