#include <stdio.h>
#include <string.h>

int main(void)
{
	char l; //后面if语句中的比较应该直接写l，而不是'l' 
	int n;
	scanf("%c%d", &l, &n);


	char str[100];
	getchar(); //在输入L 0时会按下回车，如果不加这句，则gets()以这个回车为输入结束符,导致输入为空 
	gets(str);

	int sum = 0; //用于计数 
	if(n == 0)
	{
		for(int i = 0; i<strlen(str); i++)
		{
			//if(str[i] <= 'a' && str[i] >= 'z')
			if(str[i] >= 'a' && str[i] <= 'z')
			{
			//	if(str[i] == l ||  str[i] == l - 32)
				if(str[i] == l ||  str[i] == l + 32)
				{
					sum++; 
				} 
				else
					continue;
			}
			
		//	if(str[i] <= 'A' && str[i] >= 'Z')
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
			//	if(str[i] == l ||  str[i] == l + 32)
				if(str[i] == l ||  str[i] == l - 32)
				{
					sum++; 
				} 
				else
					continue;
			}
		}
	}
	
	else
	{
		for(int i = 0; i<strlen(str); i++)
		{
			if(str[i] == l)
				sum++;
		}
	}	
			
	printf("%d", sum);

	return 0;
} 

