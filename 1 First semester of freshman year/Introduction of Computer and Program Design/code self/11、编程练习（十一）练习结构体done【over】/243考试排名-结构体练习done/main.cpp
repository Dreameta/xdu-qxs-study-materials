#include <stdio.h>

struct student{
	char name[20];
	int score_1;
	int score_2;
	int score_3;
	int score_4;
	int score_5;
	int score_more;
	int score_sum;
};

int main(void)
{
	int n;
	scanf("%d", &n);
	
	struct student stu[100];
	for(int i=0; i<n; i++)
	{
		scanf("%s%d%d%d%d%d%d", &stu[i].name, &stu[i].score_1, &stu[i].score_2, &stu[i].score_3, &stu[i].score_4, &stu[i].score_5, &stu[i].score_more);
		stu[i].score_sum = stu[i].score_1 + stu[i].score_2 + stu[i].score_3 + stu[i].score_4 + stu[i].score_5 + stu[i].score_more;
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(stu[i].score_sum < stu[j].score_sum)
			{
				struct student t = stu[i];
				stu[i] = stu[j];
				stu[j] = t;
			}
			if(stu[i].score_sum == stu[j].score_sum)
			{
				if(stu[i].score_more < stu[j].score_more)
				{
					struct student t = stu[i];
					stu[i] = stu[j];
					stu[j] = t;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		printf("%s %d %d\n", &stu[i].name, stu[i].score_sum, stu[i].score_more);
	}
	
	return 0; 
} 




