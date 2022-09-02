//studycode from teacher 
#include <stdio.h>

int main(void)
{
	/*输入数据*/
	int m,n;
	scanf("%d%d",&m,&n);
	
	int matrix[100][100];
	for(int i=0; i<m; i++)
	{
		for(int j =0; j<n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	
	/*算法：处理数据*/ 
	int finding_one_flag; //发现一个1的标志 
	int temp_start, temp_end, temp_length; //记录某个1的开始结尾位置和长度 
	int longest_start, longest_end, max_length; //记录最长1的开始结尾位置和长度
	 
	for(int i=0; i<m; i++)
	{
		//初始化数据：如果没有遇到1，那么输出结果都是-1 
		longest_start=-1;
		longest_end = -1;
		
		max_length=0;
		finding_one_flag=0;
		
		//每行每行的扫描数据：先找某个1，再处理截止位置 
		for(int j =0; j<n; j++)
		{
			//判断类型1：发现了“1 ”，但是只操作开始的第一步
			//注意：这里只是操作第一步，之后如果是1，只会继续计数 
			if(finding_one_flag == 0 && matrix[i][j] == 1)
			{
				
				if(j == n-1)//【特殊情况】当第一位出现位置就是最后一位 
				{
					if(1 > max_length)
					{
						longest_start = j;
						longest_end = j;
					}
				}
				
				else //第一位出现位置未到边界 
				{
					temp_start = j; //某个1的开始位 
					finding_one_flag = 1;	
				}
			}
			
			//判断类型2_1_截止判断：已经找到一个1的位置，且到了以0为结尾的位置 
			else if(finding_one_flag == 1 && matrix[i][j] == 0) 
			{
				temp_end = j-1; //某个1的结束位 
				finding_one_flag = 0; //将找到标志进行赋值变为0、
				
				temp_length = temp_end - temp_start + 1; //计算对应长度 —> 用来输出1这个数据 
				
				//判断：将这个某个1的开始结束和长度位 和 最长进行交换 
				if(temp_length > max_length)
				{
					longest_start=temp_start;
					longest_end = temp_end;
					max_length = temp_length;
				}		
					
			}

			//判断类型2_2_截止判断：【特殊情况】如果这一行是111111，且没有下面的这个截止条件。那么longest_start和longest_end初始值是不变的。  
			else if(finding_one_flag == 1 && matrix[i][j] == 1 && j == n-1)
			{
				
				temp_end = j;
				finding_one_flag = 0; 
				temp_length = temp_end - temp_start+1;
				
				//判断：将这个某个1的开始结束和长度位 和 最长进行交换 
				if(temp_length > max_length)
				{
					longest_start = temp_start;
					longest_end = temp_end;
				}
							
			}
			
		}

		printf("%d %d\n", longest_start, longest_end); //输出最长部分的位置 
		
	}

	return 0;
}



