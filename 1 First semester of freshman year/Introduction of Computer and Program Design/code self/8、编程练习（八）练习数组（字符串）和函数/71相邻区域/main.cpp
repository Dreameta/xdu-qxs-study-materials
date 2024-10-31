//studycode

#include <stdio.h>

#define LEFT_DOWN 2
#define RIGHT_UP  4

int main(void)
{
	int matrix[20][20];
	int n,m,t,k;
	int i,j;
	int k_start_row,k_start_col;
	int neighbourhood_up=-1;
	int neighbourhood_down=-1;
	int neighbourhood_left=-1;
	int neighbourhood_right=-1;
	int neighbourhood_num=0;
	
	scanf("%d %d %d %d",&n,&m,&t,&k);
	
	for(i=0;i<n;i++)
	{
		for(j =0;j<m;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	
	for(i=0; i<n; i++)
	{
		for(j =0; j<m; j++)
		{
			if(matrix[i][j] == k)
			{
				k_start_row = i;
				k_start_col = j;
				break;
			}
		}
		if(j<m)
		{
			break;
		}
	}
	i=k_start_row;
	for(;i<n;i++)
	{
		for(j=k_start_col;j<m;j++)
		{
			if(matrix[i][j] == k)
			{
				if(i>0)
				{
					if(matrix[i-1][j] !=k && matrix[i-1][j] != neighbourhood_up)
					{
						neighbourhood_num++;
						neighbourhood_up = matrix[i-1][j];
				//		printf("up:%d\n",neighbourhood_up);
					}
				}
				if(i<n-1)
				{
					if(matrix[i+1][j] !=k && matrix[i+1][j] != neighbourhood_down)
					{
						neighbourhood_num++;
						neighbourhood_down = matrix[i+1][j];
				//		printf("down:%d\n",neighbourhood_down);
					}
				}
				if(j>0)
				{
					if(matrix[i][j-1] !=k && matrix[i][j-1] != neighbourhood_left)
					{
						neighbourhood_num++;
						neighbourhood_left = matrix[i][j-1];
				//		printf("left:%d\n",neighbourhood_left);
					}
				}
				if(j<m-1)
				{
					if(matrix[i][j+1] !=k && matrix[i][j+1] != neighbourhood_right)
					{
						neighbourhood_num++;
						neighbourhood_right = matrix[i][j+1];
				//		printf("right:%d\n",neighbourhood_right);
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	printf("%d\n", neighbourhood_num);
	
	return 0;
}





