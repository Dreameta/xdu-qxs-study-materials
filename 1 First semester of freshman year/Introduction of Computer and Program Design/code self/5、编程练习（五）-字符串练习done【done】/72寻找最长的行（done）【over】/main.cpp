/*
问题描述	
寻找若干行文本中最长的一行

输入说明	
输入为多个字符串(每个字符串长度不超过100个字符)，每个字符串占一行，输入的行为“***end***”时表示输入结束

输出说明	
输出其中最长的一行长度后换行再输出最长行的内容，如果最长行不止一个，则输出其中的第一行。

输入样例	
abce
abdf dlfd
***end***

输出样例	
9
abdf dlfd 
*/
//此程序为网上摘抄，完全是学习文件

# include <stdio.h>
# include <string.h>
# include <math.h> 

int main(void)
{
	char c;
	char a[100]={0}, b[100];
	
	int sum = 0, max = 0;
	
	//输入和判断部分 
	while(1) //表示输入多个字符 
	{
		//输入部分 
		gets(a); 
		sum = strlen(a);
		
		//判断是否为最长 
		if(sum > max)
		{
			max = sum;
			strcpy(b, a); //传递字符串的函数，相当于之前的赋值 
		}
		
		//跳出循环条件，即跳出输入多行字符串的步骤 
		if(strncmp(a, "***end***", 9) == 0) 
			break;
		//新函数：前两个参数字符串前9位数字进行比较 →其实就是当输入 "***end***" 是这个死循环跳了出来
	
	}
	
	/*
	字符串函数复习：
	 strcat 字符串连接
	 strcpy 字符串赋值
	 
	 strcmp 字符串比较函数
	 strncmp 字符串比较_长度_函数
	 
	 strcpy  字符串复制函数 
	 strncpy 字符串复制_长度_函数 
	*/
	
	//输出部分 
	printf("%d\n", max);
	
	for(int j=0; j<max; j++)
	{
		printf("%c", b[j]);
	}
	printf("\n");
	
	return 0;
}



