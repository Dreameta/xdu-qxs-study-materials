# include <stdio.h>
# include <math.h>

//sum函数:计算一个整数有多少位数 
double sum(double x)
{
	int y;
	y = (int)x;
	int i; //循环计数变量 
	for(i=1; i>0; i++)
	{
		y = y/10; //可以理解为去尾数 
		if (y == 0)
		break;
	 } 
	return i;
}

//narcissistic_number函数：计算某个[a,b]范围内的水仙花数 
int narcissistic_number(double a, double b)
{
	int sum_narcissistic_number = 0; //记录有几个水仙花数 
	double number; //记录第i个数有几个数有几位数 
	
	for(double i=a; i<=b; i++) //小结：依旧通过for循环进行自增来计算 
	{
		int b = (int)i; //在运算时所需要保留a值，故找个替换值。 	
	
		//先计算位数； 
		number = sum(i);
		if (number == 1)
			continue;
		
		//按水仙花数的计算方式进行计算；
		double intermediate_variable = 0; //标记记录按水仙花数计算方式计算的结果 
		for(int j = number ; j>0; j--)
		{
			intermediate_variable =  intermediate_variable + pow((double)(b%10),number); 
			b /= 10;
		}
		
		//验证是否为水仙花数 
		if(i == intermediate_variable)
			sum_narcissistic_number ++;
		else
			continue;		
	} 
	
	return sum_narcissistic_number;
}

int main(void)
{
	double a, b;
	scanf("%lf%lf", &a, &b);
	
	printf("%d", narcissistic_number(a,b));
	
	return 0;
}
