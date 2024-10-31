#include <stdio.h>
#include <string.h>

int main(void)
{
	char l;
	int n;
	scanf("%c%d", &l, &n);

	char str[100];
	gets(str);

	int sum = 0; //用于计数 
	if(n == 0)
	{
		for(int i = 0; i<strlen(str); i++)
		{
			if(str[i] <= 'a' && str[i] >= 'z')
			{
				if(str[i] == 'l' ||  str[i] == 'l' - 32)
				{
					sum++; 
				} 
				else
					continue;
			}
			
			if(str[i] <= 'A' && str[i] >= 'Z')
			{
				if(str[i] == 'l' ||  str[i] == 'l' + 32)
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
			if(str[i] == 'l')
				sum++;
		}
	}	
			
	printf("%d", sum);

	return 0;
} 
