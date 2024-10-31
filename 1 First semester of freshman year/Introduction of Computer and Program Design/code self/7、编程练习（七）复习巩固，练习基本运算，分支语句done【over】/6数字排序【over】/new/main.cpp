#include <stdio.h> 

struct an{
	int n;
	int sum;
};

/*求每位数的和*/
int avg(int n)
{
	int sum = 0;
	for(int j=0; n!=0; j++)
		{
			sum = sum + n%10;
			n = n / 10;
		}
	return sum; 
}

int main(void)
{
	/*输入数据*/
	int n;
	scanf("%d", &n);
	
	struct an an1[1000] = {0, 0};
	for(int i=0; i<n; i++)
		scanf("%d", &an1[i].n);
	
	/*先求出每个数的各位数之和*/
	for(int i=0; i<n; i++) 
	{
		an1[i].sum = avg(an1[i].n);
	}
	
	/*排序*/
	for(int i=0; i<n; i++)	
		for(int j=i+1; j<n; j++)
		{
			if(an1[i].sum < an1[j].sum)
			{
				struct an t = an1[i];
				an1[i] = an1[j];
				an1[j] = t;
			}
			
			if(an1[i].sum == an1[j].sum)
			{
				if(an1[i].n < an1[j].sum)
				{
					struct an t = an1[i];
					an1[i] = an1[j];
					an1[j] = t;
				}
			}
			
		}
	
	/*输出*/
	for(int i=0; i<n; i++)
	{
		printf("%d %d\n", an1[i].n, an1[i].sum);
	}
	
	return 0;
}

