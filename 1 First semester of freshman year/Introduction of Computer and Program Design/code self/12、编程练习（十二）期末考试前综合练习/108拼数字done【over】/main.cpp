#include <stdio.h>
#include <string.h>

int main(void)
{
	/*输入数据*/
	char str[100] = {0};
	gets(str);
	
	/*找出符合的数据，赋值给另一个数组*/
	char str_1[100] = {0};
	int j = 0;
	for(int i=0; i<strlen(str); i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			str_1[j] = str[i];
			j++;
		}
	}
	
	if(str_1[0] != '\0' )
	{
		int x = 0; //转换成相应的整数型 
		for(int i=0; i<strlen(str_1); i++)
		{
			x = x*10 + str_1[i] - '0'; //字符串型数字转换成整数型数字 
		}
		
		if(x>2)
		{
			int i;
			for(i=x-1; ; i--)
			{
				if(x % i == 0)
					break;
			} 
			printf("%d", i);
		}
		else //特殊情况 
			printf("%d", x);
	}
	else
		printf("0");
	//注意这个else，当没有数字储存的时候，就不需要转换数字和算最大公因数
	//反而要注意没有数字储存还经历上面的数字转换和找最大公因数会出现没有必要的差错 
	
	return 0;
}

/*
int greatest_common_factor(int x, int str[])
{
	int sum = y;
	for(int i=2; ; i++)
	{
		
		y = x % i; 
	}
}
*/

