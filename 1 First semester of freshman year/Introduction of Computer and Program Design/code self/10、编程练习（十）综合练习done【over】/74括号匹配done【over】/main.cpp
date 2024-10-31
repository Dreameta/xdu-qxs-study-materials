// 代码学习
//感悟：本质是个选择结构 

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[55];
	gets(str);
 	// scanf("%s",str);

	//下面的思路：一次检测每个位置的字符，并做相应处理 
	int a=0, b=0, c=0; //三种括号的计数 
	int flag=0;	
	for(int i=0; i<strlen(str); i++)
	{
		
		//前三个if是记录左边符号的数目 
		if(str[i]=='(') 
			a++;
		else if (str[i]=='[') 
			b++;
		else if (str[i]=='{') 
			c++;
			
		//后三个if是记录右边符号的数目 
		else if (str[i]==')')
		{
			a--;
			if(a<0)
			{
				flag=1;
				break;
			}
		}
		else if (str[i]==']')
		{
			b--;
			if(b<0)
			{
				flag=1;
				break;
			}
		}
		else if (str[i]=='}')
		{
			c--;
			if(c<0)
			{
				flag=1;
				break;
			}
		}
		
	}
	
	if(flag==0 && a==0 && b==0 && c==0)
		printf("yes");	
	else
		printf("no");
	//经验：凡是所有的if语句一定要考虑到所有的情况，省略掉“else”本身，说明你就输了 
}








