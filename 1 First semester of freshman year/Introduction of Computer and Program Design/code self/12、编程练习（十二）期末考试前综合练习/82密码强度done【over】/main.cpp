#include <stdio.h>
#include <string.h>

//引入结构体，统一变量形式，记录各种分数项 
struct score{
	int score_sum;
	/*
	int score_litte_letter;
	int score_capital_letter;
	int score_number;
	int score_no_letter;
	*/
	int score_basic; 
	int score_more1;
	int score_more2; 
};

int main(void)
{
	char password[100]; //输入字符串 
	gets(password);
	
	struct score SCORE = {0, 0, 0, 0}; //记录分数，初始化 
	//下面分类型处理
	if (strlen(password) == 0)
		SCORE.score_basic = 0; //无字符就是0 
	else
	{
		SCORE.score_basic = 1; //有字符就是1 
		
		if(strlen(password) > 8)
			SCORE.score_more1 = 1;
		
		for(int i=0; i<strlen(password); i++)
			if(password[i] >= 'a' && password[i] <= 'z')
			{
				SCORE.score_more2++;
				break; 
			} 
		
		for(int i=0; i<strlen(password); i++)
			if(password[i] >= 'A' && password[i] <= 'Z')
			{
				SCORE.score_more2++;
				break; 
			}
			
		for(int i=0; i<strlen(password); i++)
			if(password[i] >= '0' && password[i] <= '9')
			{
				SCORE.score_more2++;
				break; 
			}	
		
		for(int i=0; i<strlen(password); i++)
			if ( ((password[i] >= '0' && password[i] <= '9')||(password[i] >= 'A' && password[i] <= 'Z')||(password[i] >= 'a' && password[i] <= 'z')) != true) 
			//attention：注意取上面这句，表示剩下方面情况的说法 
			//if ( (password[i] >= '0' && password[i] <= '9')||(password[i] >= 'A' && password[i] <= 'Z')||(password[i] >= 'a' && password[i] <= 'z') != 1)
			{
				SCORE.score_more2++;
				break; 
			}
		
		if(SCORE.score_more2 == 1)
			SCORE.score_more2 = 0;
		else if(SCORE.score_more2 == 2)
			SCORE.score_more2 = 1;
		else if(SCORE.score_more2 == 3)
			SCORE.score_more2 = 2;
		else
			SCORE.score_more2 = 3;	
	}
	
	SCORE.score_sum = SCORE.score_basic + SCORE.score_more1 + SCORE.score_more2;
	printf("%d", SCORE.score_sum);
	
	return 0;
}

 

