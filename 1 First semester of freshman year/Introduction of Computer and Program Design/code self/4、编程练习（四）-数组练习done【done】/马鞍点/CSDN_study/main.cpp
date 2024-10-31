#include<stdio.h>
#define m 3
#define n 3
/*求矩阵A中的马鞍点*/
void Get_Saddle(int A[m][n])
{
	/*
	   基本思想：1.首先它是一个二维数组，需要遍历每一行，需要一个for循环，且需要放在最外层
	             2.然后，依次从每一行中横向遍历到最后（直到本行结束），找到最小值
				    1)又需要一层循环，循环结束至这一行中的最后位置，
					2)找的最小值，记录最小值所在列数
				 3.找到最小值之后，用一个变量minCol记下当前列数
				 4.顺这当前列数竖向遍历（从当前列第一行开始向下）判断是否是最大的，如果是，则这个元素就是整个矩阵的马鞍点
				    1)又需要一个循环，用来遍历竖向遍历
	*/
	int i,j,k;
	int flag,min,minCol;
	for(i=0;i<m;i++)
	{
		//求一行中的最小值
		min = A[i][0];//先假设每行中第一个元素为最小值
		minCol = 0; //
		for(j=0;j<n;j++)//每行元素向后遍历
		{
			if(A[i][j] < min)//如果遇到比第一个元素小的
			{
				min =  A[i][j];//使最小值为当前行当前列
			    minCol =j;//标记出当前列数
			}
		}
		/*判断这个最小值是否是马鞍点，即是不是所在列的最大值*/
		flag = 1;
		for(k=0;k<m;k++)
		{
			if(min < A[k][minCol])//如果当前行的最小值小于所在列中的值，即这个数不是马鞍点
			{
				flag = 0;//标记变量置零
				break;//因为已经找到了这个点不是马鞍点，所以无需再去比较，直接返回
			}
		}
		if(flag)//如果成立，则表示找到了马鞍点，输出
		{
			printf("Found a saddle element !\nA[%d][%d] = %d\n",i+1,minCol+1,A[i][minCol]);
		}
	}

}
int main(void)
{
	/*初始化A[m][n]*/
	int A[m][n] = {1,2,3,
	               4,5,6,
	               7,8,9};
	for(int i=0;i<m;i++)
	{
		for(int j = 0;j<n;j++)
			printf("%d  ",A[i][j]);

	    printf("\n");
	}
	Get_Saddle(A);
	getchar();
	return 0;
}
