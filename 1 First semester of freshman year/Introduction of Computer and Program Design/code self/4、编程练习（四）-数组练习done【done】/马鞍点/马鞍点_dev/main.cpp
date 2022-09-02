# include <stdio.h>

//函数：判断是否为马鞍点+输出相关参数 
void Get_Saddle(int c[100][100], int m, int n) 
{
    int x, y; //定义储存位置变量,分别为行，列； 
    int flag; //标记第一次在某行找到的最小值位置假设为所需马鞍点；
    		  //GET：二维控制确定的时候可以以变量进行标注来执行； 
	
    for (int i = 0; i < m; i++)
    {
			x = i;
			y = 0; 
    	
		//先找每行的最小值 
        for (int j = 0; j < n; j++)
        { 
            if (c[i][j] < c[i][0])
                { 
                y = j;
                c[i][0] = c[i][j];
                } 
        }
        
        //接下来在这行中，确定是否为这列的最大值 
        flag = 1;
		for (int k = 0; k < m; k++) //这里使用第三重循环变量的原因：避免和前面的i相影响。 
    	{
	        if(c[x][y] < c[k][y])
			{ 
				flag = 0;
				break;
			}
		}
		
		/*
		接下来的部分是可以改变的部分：
		前面是判断了是否为马鞍点，下面是对马鞍点的相关处理。
		另外，这里不好作为函数来输出多个值，所以可以直接在函数中直接输出值，不用return返回多个值。 
		*/ 
		
		if (flag)
		{
			printf("%d %d %d", x, y, c[x][y]); //这里就是所谓输出的多变量的地方 
			return; 
		}
			
    }
    if(flag == 0)
    {
    	printf("no");
    	return;
	}
}

int main (void)
{
    int m, n; //行，列 
    int c[100][100]; //分别定义行数、列数及其各部分内容；

    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
  	
   	Get_Saddle(c, m, n);

	return 0;
}



