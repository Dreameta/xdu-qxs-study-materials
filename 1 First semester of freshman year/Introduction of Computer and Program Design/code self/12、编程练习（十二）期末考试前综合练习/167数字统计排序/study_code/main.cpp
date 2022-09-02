//study code 1
/*
	study point
	(1)直接利用循环计数从而进行排序筛选 
*/ 
/*
#include <stdio.h>
int main() 
{ 
	//输入数据，并对部分数据进行统计 
  	int n;
  	scanf("%d", &n);
  	
  	int a[1005]={0}; //初始化每个数字出现的次数为0 
	int num;
	for(int i=1; i<=n; i++)
	{ 
		scanf("%d", &num);
		a[num]++;	//边输入边统计数字出现的次数 
	} 
	
	//处理数据 
	for(int i=1000; i>0; i--)  //i代表的是出现的次数 最大为1000。直接对出现的次数由多到少进行了排序 
		for(int j=0; j<=1000; j++) //从数字0开始向上搜索。直接从大到小进行排序。 
			if(a[j] == i)	//若存在一个数字的出现次数为i 
				printf("%d %d\n", j, a[j]);
				
	return 0;
}
*/
//study code 2
 
#include <stdio.h>

struct sort{
	int num;
	int times;
};
/**************************函数参数********************************************
*all					总数字 
*num[all],xnum[all]		储存原值和储存合并好的值
*i,j,k,l 				临时变量 
*struct sort{
	int num;			数字 
	int times;			次数 
};
*******************************************************************************/
int main()
{

	/*输入参数1*/ 
	int all;
	scanf("%d",&all);
	
	/*输入参数2 定义【仅支持C99以后】*/
	struct sort num[all],xnum[all];
	for(int i=0;i<all;i++)
 		scanf("%d", &num[i].num);
	
	/*初始化：每个数字出现的次数，均为1*/
	int l=0;
	for(int i=0; i<all; i++)
		num[i].times=1;
	
	/*合并*/ 
	for(int i=0; i<all; i++)
 		for(int j=i+1; j<all; j++)			  			  
			if(num[i].num == num[j].num)
			{
				num[j].times = num[j].times + num[i].times;
				num[i].num = -1;
				break;
			}	
	
	/*整理转存*/	
	for(int i=0; i<all; i++)
		if(num[i].num >= 0)
		{
			xnum[l].num = num[i].num;
			xnum[l].times = num[i].times;
			l++;
		}

	/*排序*/	
	for(int i=0; i<l-1; i++)
		for(int j=i; j<l; j++){
			if(xnum[i].times < xnum[j].times)
			{
				int k=xnum[i].times;
				xnum[i].times=xnum[j].times;
				xnum[j].times=k;
				
				k=xnum[i].num;
				xnum[i].num=xnum[j].num;
				xnum[j].num=k;
			}
			else if(xnum[i].times==xnum[j].times){
				if(xnum[i].num>xnum[j].num){
					int k=xnum[i].num;
					xnum[i].num=xnum[j].num;
					xnum[j].num=k;
				}
			}
		}	
	
	/*打印*/
	for(int i=0;i<l;i++)
		printf("%d %d\n",xnum[i].num,xnum[i].times);
		
	return 0;									  				  			  
 } 




















