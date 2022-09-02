# include <stdio.h>

//函数：求第n位数的斐波那契数 
//可移植性进行探讨：只需修改f斐波那契数列的第一、二个项便可以直接移植 
int fib(int n)
{
	int m[41];
	m[0] = 1;
	m[1] = 1;
	int p; //作为输出值 
	
	int i; //循环变量 
	
	if (n == 0)
		p = m[0];
	else if (n == 1)
		p = m[1];
	else
	{
		for (i=2; i<=n; i++)
		{
			m[i] = m[i-1] + m[i-2];
		}
	}
	return m[n-1]; //可以用n来做下标——下标可以用整型来表示	 	
} 

//函数：判断是否为素数 
bool prime_number (int m)
{
	if (m == 1)
		return true;
	for(int i=2; i<m; i++)
	{
		if(m%i != 0)
			continue;
		else
			return false;
	} 
	return true;
}

int main(void)
{
	int n;
	scanf("%d", &n); //定义并输入所要求的第n项数字 
	
	int fib_n; //第n位的斐波那契数列的数
	fib_n = fib(n);
	
	if(prime_number(fib_n))
		printf("yes");
	else
		printf("%d", fib_n);
	 
	return 0;
 } 

/*
# include <stdio.h>

//函数：求第n位数的斐波那契数 
//可移植性进行探讨：只需修改第一、二个元素便可以直接移植 
int fib(int n)
{
	int m[41];
	m[0] = 7;
	m[1] = 11;
	int p; //作为输出值 
	
	int i; //循环变量 
	
	if (n == 0)
		p = m[0];
	else if (n == 1)
		p = m[1];
	else
	{
		for (i=2; i<=n; i++)
		{
			m[i] = m[i-1] + m[i-2];
		}
	}
	return m[n]; //可以用n来做下标——下标可以用整型来表示	 	
} 

int main(void)
{
	int n;
	scanf("%d", &n);
	
	printf("%d", fib(n));
	
	return 0;
}
*/
