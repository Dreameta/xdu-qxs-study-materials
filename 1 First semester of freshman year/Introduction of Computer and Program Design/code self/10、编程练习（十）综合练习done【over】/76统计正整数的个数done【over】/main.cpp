#include <stdio.h>

//代码学习：重要思路。直接利用数组顺序的结构，将排序、计数统一起来。 
int main(void)
{
	/*输入数据1*/
	int n;
	scanf("%d", &n); 
	/*输入数据2+计数*/
	int integer[100000] = {0};
	int integer_n; //对应的数
	for (int i = 0; i < n; i++ )
	{
		scanf("%d", &integer_n); //对应的每位数字 
		integer[integer_n]++; //每位数字出现次数的记录 
	}
	
	/*用来条件输出数据*/
	for(int i=0; i<100000; i++)
	{
		if(integer[i])//只要不是0，就会输出； 
		{
			printf("%d:%d\n", i, integer[i]); 
		}
	} 
	
	return 0;
}


