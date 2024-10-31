#include <stdio.h>

//主要收获：直接运用了结构体进行相关变量的统一化 

struct student{
	int stu_ID;
	char name[10];
	float score_1;
	float score_2;
	float score_3;
	float average;
};

int main(void)
{
	int n;
	scanf("%d", &n);
	
	struct student stu[100] = {0};
	for (int i=0; i<n; i++)
	{
		scanf("%d%s%f%f%f", &stu[i].stu_ID, &stu[i].name, &stu[i].score_1, &stu[i].score_2, &stu[i].score_3);
		stu[i].average = (stu[i].score_1 + stu[i].score_2 + stu[i].score_3) / 3;
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(stu[i].average < stu[j].average)
			{
				struct student t = stu[i];
				stu[i] = stu[j];
				stu[j] = t;
				
			}
			if(stu[i].average == stu[j].average)
			{
				if(stu[i].stu_ID > stu[j].stu_ID)
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
		printf("%d %s %.1f\n", stu[i].stu_ID, stu[i].name, stu[i].average);
	}
	
	return 0;
}

