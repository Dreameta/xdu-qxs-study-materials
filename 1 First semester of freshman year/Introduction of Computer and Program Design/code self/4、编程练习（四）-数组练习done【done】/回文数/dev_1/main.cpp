# include <stdio.h>

//函数：判断是否为回文数 
bool f(int n)
{
	int m; //用于求n的倒位数字
	m = n; 
	
	int sum = 0;
	
	for(int i=0; m>0; i++) //注意这个执行条件； 
	{
		sum = (sum*10)+ (m%10);
		m = m/10;
	} 
	
	if ( sum == n)
		return true;
	else
		return false;
}

//函数：计算每位数字之和 
int g(int n) 
{
	int i; //循环计数变量 
	int sum = 0; //计数每位数字 
	
	for(i=0; n>0; i++)
	{
		sum = sum + n%10;
		n /= 10;
	}
	
	return sum; 
}

int main(void)
{
	int n;
	
	scanf("%d", &n);
	
	if (f(n))
		printf("%d", g(n));
	else
		printf("no");
	
	return 0;
}

