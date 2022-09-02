#include <stdio.h>
#include <string.h>

int main(void)
{
	/*输入数据*/
	char l; //后面if语句中的比较应该直接写l，而不是'l' 
	int n;
	scanf("%c%d", &l, &n);

	char str[100];
	getchar(); 	/*☆关键一步*/ 
				//在输入L 0时会按下回车，如果不加这句，则gets()以这个回车为输入结束符,导致输入为空 
	gets(str);

	/*进行判断*/
	int sum = 0; //用于计数 
	
	/*进入模式：不区分大小写*/
	if(n == 0)
	{
		for(int i = 0; i<strlen(str); i++)
		{
			if(str[i] >= 'a' && str[i] <= 'z') //自我反思：这句话是判断字符串中某个的部分是否是小写字母 
			{
				if(str[i] == l ||  str[i] == l + 32) //两个或的关系：表示不区分大小写。前面是str和l都是小写，后面是小写str对应大写l的小写形式。 
				//这句体现了一种易混的逻辑关系：字符串中是小写的情况下，可能对应“l”所代表的是大写或小写。
				//这样编写程序的话，就体现了两重相互对应。这点在逻辑严密的情况下是十分重要的。 
				{
					sum++; 
				} 
				else
					continue;
			}
			
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				if(str[i] == l ||  str[i] + 32 == l) //这里还是可以表示长度的 
				{
					sum++; 
				} 
				else
					continue;
			}
		}
	}
	
	/*模式：区分大小写*/
	else
	{
		for(int i = 0; i<strlen(str); i++)
		{
			if(str[i] == 'l')
				sum++;
		}
	}	
			
	printf("%d", sum);

	return 0;
} 





