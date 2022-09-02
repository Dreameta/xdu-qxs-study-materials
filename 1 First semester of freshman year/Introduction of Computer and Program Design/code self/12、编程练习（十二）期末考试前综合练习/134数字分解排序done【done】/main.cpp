#include <stdio.h>

int main(void)
{
	int n;
	int m[10];
	
	scanf("%d", &n);
	int sum = 0;
	for(int i=0; n != 0; i++)
	{
		m[i] = n % 10;
		n = n / 10;
		sum++;
	}
	
	for(int i=0; i<sum; i++)
	{
		for(int j=i+1; j<sum; j++)
		{
			if(m[i] < m[j])
			{
				int t = m[i];
				m[i] = m[j];
				m[j] = t;
			}
		}
	}
	
	for(int i=0; i<sum; i++)
		printf("%d ", m[i]);
	
	return 0;
}

