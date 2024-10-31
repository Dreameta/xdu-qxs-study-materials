# include <stdio.h>

int main(void)
{
	/*初始化函数*/
	/*******************函数初始化********************/
	int sum(int x);
	//int iteration_sum_units_digit(int n);
	/************************************************/
	
	/*输入数据*/
	int n;
	scanf("%d", &n);
	
	int sum_n; //定义数字n的个数
	int result_n = 0; //最后结果：每位数字的和 
	
	while(1)
	{
		
		for(sum_n = sum(n); sum_n>0; sum_n--)
		{	
			result_n = result_n + (n % 10);
			
			n =  n / 10;
			
			//if(result_n >= 0 && result_n <= 9)
			//千万要注意在循环处理时，一定要注明每位数都参与了 
			if(result_n >= 0 && result_n <= 9 && sum_n==0)
				break;
		} 
		
		if(result_n >= 0 && result_n <= 9 && sum_n==0)
			break;
		else
		{
			n = result_n;
			result_n = 0; 
		}

	}
	
	printf("%d", result_n);
	
	return 0;
}

//sum函数:计算一个整数有多少位数 
int sum(int x)
{
	int i; //循环计数变量 
	for(i=1; i>0; i++)
	{
		x = x/10; //可以理解为去尾数 
		if (x == 0)
		break;
	 } 
	return i;
}

