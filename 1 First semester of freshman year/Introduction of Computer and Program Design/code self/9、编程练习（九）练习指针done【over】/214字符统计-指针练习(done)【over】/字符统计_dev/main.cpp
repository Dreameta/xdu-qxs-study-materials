//学习代码 
#include<stdio.h>
#include<string.h>

int main()
{
	int count(char *s); //声明函数 
	char string[100]; //定义符号累数组 
	
	gets(string); //输入字符
	 
	count(string); //调用自定义函数 
	
	return 0;
 } 
 
 /*
	@relief 统计对应字符 
 */
 int count(char *s)
 {
 	int num[5]={0};
 	
 	char *p = s;
 	
 	while(*p != '\0')
 	{
 		if(*p>='A' && *p<='Z')
 			num[0]++;
 		else if(*p>='a' && *p<='z')
 			num[1]++;
 		else if(*p==' ')
 			num[2]++;
 		else if(*p>='0' && *p<='9')
 			num[3]++;
 		else
 			num[4]++;
 			
		p++;
	 }
	 
	 printf("%d %d %d %d %d",num[0],num[1],num[2],num[3],num[4]);
 }


