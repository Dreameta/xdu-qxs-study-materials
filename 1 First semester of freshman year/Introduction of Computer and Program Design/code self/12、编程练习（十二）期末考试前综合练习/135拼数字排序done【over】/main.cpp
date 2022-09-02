
//studycode
/*
#include<stdio.h>
#include<string.h>

int my_pow(int n)
{
    int i;
    int sum=1;
  	for(i=1; i<=n-1; i++)
  	{
      	sum*=10;
  	}
    return sum;
}

void swap (int *x , int *y)
{
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

int main(void)
{
   	char x[101];
   	gets(x);
   	int len = strlen(x);
   	int i,j;
  	int zx[100]={0}; //储存数字 
   	int k=0;
   	int a=0;       //记录完整数字段个数 
   	
  	for (i=0; i<=len-1; i++)
  	{
      	if (x[i]>='0' && x[i]<='9')
      	{	
         	a++;            
          	int tempi=i;
         	int templen=0;    //记录该数字的字面长度
          	while (x[tempi]>='0' && x[tempi]<='9')  //第一遍扫描字面长度
          	{
              	templen++;
              	tempi++;
          	}
           	tempi=i;
           	
           	i+=templen;  //在这里就要让i往后走了
          	while (x[tempi]>='0' && x[tempi]<='9')  //第二遍扫描数字，转成整形
          	{
              	zx[k] += (x[tempi]-'0') * my_pow(templen);
              	templen--;
              	tempi++;
          	}
           	k++;
      	}
  	}
	
	//排序 
	for (i=0; i<a-1; i++)
  	{
       	for (j=0; j<a-1-i; j++)
       	{
           	if (zx[j]<zx[j+1])
           	{
            	swap(zx+j,zx+j+1);
           	}
       }
   	}
	
	//输出 
   	for (i=0; i<=a-1; i++)
   	{
       	printf("%d ",zx[i]);
   	}

    return 0;
}
*/

//mycode
 
#include <stdio.h>
#include <string.h> 

int main(void)
{
	char str[100] = {'\0'};
	gets(str);
	
	int str_nub_sum = 0; //统计共有多少节数字
	int str_save[100] = {0}; 
	
	/*☆从字符串中取超过两位数字的方法*/
	for(int i=0; i<strlen(str); i++)
	{
		//总思路：先记录数字字符串长度，然后按长度进行整型赋值
		 
		if(str[i] >= '0' && str[i] <= '9')
		{
			//STEP1：依次往后扫描对应字符串，记录每小节数字长度
			int str_nub_len = 0;
			for(int j=i; (str[j] >= '0' && str[j] <= '9'); j++)
			{
				str_nub_len++;
			}
			
			//STEP2:把这个长度的数字“扣”下来，赋值给一个数组储存 
			for(int k=i; k<i+str_nub_len; k++)
			{
				str_save[str_nub_sum] = str_save[str_nub_sum] * 10 + str[k] - '0';
			}
			
			//STEP3：记录数字的节数
			str_nub_sum++;
			
			//恢复i的扫描位数 
			i = i + (str_nub_len-1);
		}
	}
	
	/*选择排序*/
	for(int i=0; i<str_nub_sum; i++)
	{
		for(int j=i+1; j<str_nub_sum; j++)
		{
			if(str_save[i] < str_save[j])
			{
				int temp = str_save[i];
				str_save[i] = str_save[j];
				str_save[j] = temp;
			}
		}
	}
	
	/*输出*/
	for(int i=0; i<str_nub_sum; i++) 
	{
		printf("%d ", str_save[i]);
	}
	
	return 0;
}






