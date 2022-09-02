//自己的代码 

#include <stdio.h>
#include <string.h>

int main(void)
{
	//输入数据 
	char str[255];
	gets(str);
	
	//将符合数据存入另一个数组中 
	char str_1[255] = {0}; //将其中的字母提取出来；且注意初始化，否则会有坏数据 
	int j = 0; 
	for(int i=0; i<strlen(str)-1; i++)
	{
		if(str[i] == '-')
			if(str[i+1] >= 'a' && str[i+1] <= 'z')
			{
				str_1[j] = str[i+1];
				j++;
			}
	}
	
	//排序+不重复输出 
	if(str_1[0] != '\0') //如果有字母的话，则进行排序和输出 
	{
		for(int i=0; i<strlen(str_1)-1; i++)
		{
			for(int j=i+1; j<strlen(str_1); j++)
			{
				if(str_1[i] > str_1[j])
				{
					char t = str_1[i];
					str_1[i] = str_1[j];
					str_1[j] = t;
				}
			}
		}
	
		for(int i=0; i<strlen(str_1); i++)
		{
			if(str_1[i] != str_1[i+1]) //依次扫描，遇到不同才输出——>巧妙地避开了去掉重复数据的算法 
	   			printf("-%c ", str_1[i]);
		}
	}
	
	else
		printf("no");
	
	return 0;
}





/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	
	char a[255]={'\0'}, b[200]={'\0'};
	gets(a);
	
	int flag=0, j=0, count=0, limit=0;
	
	//每个字符进行分析 
 	for(int i=0; a[i] != '\0'; i++)
 	{
		if(a[i] == '-')
	    {
			flag = 1;
			limit = 0;
		}
	  	else if(a[i] == ' ')
	  		flag = 0;
		else if(flag == 1 && limit < 1)
		{
			b[j++] = a[i]; //先赋值，再自增 
			count++;
		 	limit++;
		}
	}
	
	if(count > 0)
	{
		for(int i=0; i<strlen(b)-1; i++)
	    	for(j=0; j<strlen(b)-1-i; j++)
	    	{
				if(b[j]>b[j+1])
		   		{
					char temp=b[j];
			    	b[j]=b[j+1];
			    	b[j+1]=temp;
				}
			}
		/*
		if(count > 0)
		{
			for(int i=0; i<strlen(b); i++)
			{
				if(b[i] != b[i+1])
		   		printf("-%c ",b[i]);
			}
		}
		//
		for(int i=0; i<strlen(b); i++)
		{
			if(b[i] != b[i+1])
	   			printf("-%c ",b[i]);
		}
	}
	
	else
		printf("no");
	
	return 0;
}
*/

/*

学习代码一 

#include <stdio.h>
#include <string.h>

int main(void)
{
	//输入数据； 
	char string[256];
	gets(string);
	
	int n;
	
	int flag = 0;
	
	int j = 0;
	
	char str[100][20]; 
	for(int i=0; string[i] != '\0'; i++)
	{
		
		if(string[i] == '-')
		{
			flag=1;//标记命令存在，所以不是no
			
			for(int k=0; string[i] != ' ' && string[i] != '\0'; i++, k++)
				str[j][k] = string[i];
				
			str[j][k] = '\0';  //二维数组来存字符串的一行 最后以\0结束
			
			j++; //j控制行标 k控制列标 而i为原字符串的索引 
		}
		
		if(string[i]=='\0') 
			break;//好像没意义
		
	}
	n=j;//此时的j为行数，也就是带“-”的命令符的数量
	
	if(flag)//如果存在命令 ，改进：直接判断n是否为0即可
	{
		for(int i=0;i<n-1;i++)//选择排序 ，string多次重复利用 
		{
			k=i;
			for(int j=i+1;j<n;j++)
				if(strcmp(str[k],str[j])>0) k=j;
			if(k!=i)
			{
				strcpy(string,str[i]);
				strcpy(str[i],str[k]);
				strcpy(str[k],string);
			}
		}
		
		strcpy(string, str[0]);
		printf("%s", string);
		for(int i=1; i<n; i++)
		{
		 	if(strcmp(string, str[i]) != 0)
		 	{
		 		strcpy(string, str[i]);
		 		printf(" %s", string);
			}
		} 
	}
	else printf("no");
	
	return 0;
}

*/


