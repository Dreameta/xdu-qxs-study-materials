#include <stdio.h>

int main()
{
	int n;
	int an[100];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &an[i]);
	
	//先进行排序
	for (int i = 0; i <n; ++i)  
		for (int j = i + 1; j < n; ++j)  
			if (an[j] < an[i])
			{
				int t = an[i];
				an[i] = an[j];
				an[j] = t;  //这里的交换是将第i位之后最小值进行交换 
			} 
	
	//然后判断等差
	for(int i=0; i<n-2; i++)
	{
		if (an[i+1]-an[i] != an[i+2]-an[i+1])
		{
			printf("no");
			return 0;
		}
		else
			continue;
	} 
	
	printf("%d", an[1]-an[0]);
	
	return 0;
} 







