//studycode 
#include <stdio.h>

#define LEFT_DOWN 2
#define RIGHT_UP  4
//仅仅是两个标志，进行的调换 

int main(void)
{
	/*输入数据*/ 
	int n;
	int matrix[100][100];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	/*开始进行z字形扫描*/
	int row, column; //行，列 
	//int output_count = 0;
	int direction;
	int left_dowm_row, left_dowm_col, right_up_row, right_up_col;// 
	
	/*
	学习点：
	1、这道题通过运用标志位进行转换，左下和右上的扫描 
	*/
	direction = RIGHT_UP;
	for(int output_count=0; output_count<2*n-1; output_count++)
	{
		
		//
		/*判断扫描的范围*/
		if(output_count < n)//这是在达到最大扫描边界之前 
		{
			left_dowm_row = output_count;
			left_dowm_col = 0;
			right_up_row = 0;
			right_up_col = output_count;
		}
		else//这是达到最大边界之后 
		{
			left_dowm_row = n-1;
			left_dowm_col = output_count - (n-1) ;
			right_up_row = output_count-(n-1);
			right_up_col = n-1;
		}
		
		/*进行扫描并输出*/
		if(direction == RIGHT_UP)
		{
			
			row = left_dowm_row;
			column = left_dowm_col;
			do
			{
				printf("%d ", matrix[row][column]);
				row--;
				column++;
			}
			while(row >= right_up_row);
			///转换 
			direction = LEFT_DOWN;
		}
		else if(direction == LEFT_DOWN)
		{
			row = right_up_row;
			column = right_up_col;
			do
			{
				printf("%d ", matrix[row][column]);
				row++;
				column--;
			}
			//while(row <= left_dowm_row); 可以 
			while(column >= left_dowm_col);
			///转换
			direction = RIGHT_UP;
		}
		//

	}
	return 0;
}

