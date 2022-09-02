#include <stdio.h> 

struct an{
	int n;
	int sum;
};

int main(void)
{
	/*输入数据*/
	int n;
	scanf("%d", &n);
	
	struct an an1[10000] = {0, 0};
	for(int i=0; i<n; i++)
		scanf("%d", an1[i].n);
	
	/*先求出每个数的各位数之和*/
	for(int i=0; i<n; i++) 
	{
		for(int j=0; an1[i].n!=0; j++)
		{
			an1[i].sum = an1[i].sum + an1[i].n%10;
			an1[i].n = an1[i].n / 10;
		}
	}
	
	/*排序*/
	
	
	/*输出*/
	for(int i=0; i<n; i++)
	{
		printf("%d %d\n", an1[i].n, an1[i].sum);
	}
	
	return 0;
}
