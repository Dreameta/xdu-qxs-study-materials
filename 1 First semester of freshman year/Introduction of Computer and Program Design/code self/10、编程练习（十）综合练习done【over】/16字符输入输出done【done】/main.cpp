#include <stdio.h>
#include <string.h>

int main (void)
{
	/*输入数据*/
	char str[5];
	char*p = str;
	
	gets(str); 
	
	/*对字符串进行处理*/
	//大小写字母转换 
	for (int i = 0; i< strlen(str); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32; 
	} 
	
	//通过指针控制对应位置进行输出 
	//☆下面是利用指针直接输出对应位置的字符 
	for (int i = 0; i<(strlen(str)/2+1) ; i++)
	{
		printf("%c", p[0]);
		p = p + 2;
	}
	printf("!");
	
	return 0;
}

/*第一次尝试书写 
int main (void)
{
	char str[5];
	char*p = str;
	
	for(int i = 0; i<9; i++)
	{
		scanf("%c", &str[i]);
	}
	
	//去“|”
	for (int i = 0; i<strlen(str); i++)
	{
		if (str[i] == '|')
			str[i] = ' ';
	} 
	
	//大小写字母转换 
	for (int i = 0; i< strlen(str); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32; 
	} 
	
	//去空格 
	//int temp1, temp2;
	/*
	int t;
	for( int i = 0; i< strlen(str); i++)
	{
		if(str[i] == ' ')
		{
			t = str[i+1];
			str[i+1] = str[i];
			str[i] = t;
			
			temp1 = str[i+1];
			str[i] = temp1;
			str[i+1] = ' ';
			
			for(int j = i; j < strlen(str); j++)
			{
				temp2 = str[j+2];
	            str[j+1] = temp1;
	      		temp1 = temp2;
			}
		}
	}

	
	for (int i = 0; i<strlen(str) ; i++)
	{
		printf("%c", str[i]);
	}
	printf("!");
	
	return 0;
}
*/





