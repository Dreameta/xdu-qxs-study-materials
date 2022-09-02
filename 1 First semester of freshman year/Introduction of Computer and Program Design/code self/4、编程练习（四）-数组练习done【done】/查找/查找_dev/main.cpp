# include <stdio.h>

int main(void)
{
	int n, k;
	int an[10000] = {0};
	
	scanf("%d%d", &n, &k);
	
	for (int i=0; i<n; i++)
	{
		scanf("%d", &an[i]);
	}
	
	int flag = 0; //标记未出现的次数 
	for(int i=0; i<n; i++)
	{
		if(an[i] == k)
			printf("%d ", i);
		else
			flag++; 	
	}
	
	if(flag == n)
		printf("-1"); 
	
	return 0;
}

