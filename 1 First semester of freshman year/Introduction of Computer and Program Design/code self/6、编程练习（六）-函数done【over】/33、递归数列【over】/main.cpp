# include <stdio.h>

//函数：纯求递归数列 
double function(int n)
{
	double An[11] = {0};
	An[0] = 1;
	
	if(n == 1)
		return An[0];
	else
	{
		for(int i=1; i<n; i++)
		{
			An[i] = 1 / (1 + An[i-1]);
		}
		return An[n-1];
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	
	printf("%.6lf", function(n));
	
	return 0;
}


