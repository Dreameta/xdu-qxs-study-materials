//自己编写代码
# include <stdio.h>

//函数：图象旋转及输出 
void szxz(int zb[100][100], int m, int n)
{
	//接下来是用循环来做旋转操作
	int t; //定义中间变量；
	int shift[100][100] = {0};
	
	/*先旋转*/
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			shift[i][n-1-j] = zb[j][i]; /*☆关键旋转部分：一行一行的输入*/
		}
	}
	
	/*再输出*/
	for (int i=0; i<m; i++)
	{
		for (int j = 0;j < n;j++)
		{
			printf("%d ", shift[i][j]);
		}
		printf ("\n");
	}
}

/*
试数：
以n=2,m=3为例
shift[0][1] = zb[0][0]
shift[0][0] = zb[1][0]

shift[1][1] = zb[0][1]
shift[1][0] = zb[1][1]

shift[2][1] = zb[0][2]
shift[2][0] = zb[1][2]
*/

int main(void)
{
	/*数据输入*/
	int n, m; //n是行数，m是列数；在旋转之后，就变了；
	scanf("%d%d", &n, &m);

	int zb[100][100] = {0};
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d", &zb[i][j]);
		}		
	}
	
	/*数组旋转函数部分*/
	szxz(zb, m, n);
	
	return 0;
}

//学习代码
/*
#include <stdio.h>
int main ()
{
	int m = 0,n = 0;
	scanf ("%d %d\n",&m,&n);
	int a[100][100] = {0};
	int i = 0,j = 0;
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < n;j++)
		{
			scanf ("%d",&a[i][j]);
		}
	}

	int b[100][100] = {0};
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			b[i][m-1-j] = a[j][i];
		}
	}

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			printf ("%d ",b[i][j]);
		}
		printf ("\n");
	}
	return 0;
}
*/



