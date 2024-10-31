#include <stdio.h>

struct student{
	char number[20];
	int score_all;
	int score_Eng;
};

int main(void)
{
	/*ÊäÈëÊı¾İ*/
	int m, n;
	scanf("%d%d", &m, &n);
	
	struct student stu[200] = {0};
	for(int i=0; i<m; i++)
	{
		scanf("%s%d%d", &stu[i].number, &stu[i].score_all, &stu[i].score_Eng);
	}
	
	/*ÅÅĞò*/
	for(int i=0; i<m; i++)
	{
		for(int j=i+1; j<m; j++)
		{
			
			if(stu[i].score_all < stu[j].score_all)
			{
				struct student temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
			
			if(stu[i].score_all == stu[j].score_all)
			{
				if(stu[i].score_Eng < stu[j].score_Eng)
				{
					struct student temp = stu[i];
					stu[i] = stu[j];
					stu[j] = temp;
				}
			}
			
			if(stu[i].score_all == stu[j].score_all)
			{
				if(stu[i].score_Eng == stu[j].score_Eng)
				{
					if(stu[i].number > stu[j].number)
					{
						struct student temp = stu[i];
						stu[i] = stu[j];
						stu[j] = temp;
					}
				}
			}
			
		}
	}
	
	for(int i=0; i<n; i++)
	{
		printf("%s %d %d\n", stu[i].number, stu[i].score_all, stu[i].score_Eng); 
	} 
	
	return 0;
	
}



