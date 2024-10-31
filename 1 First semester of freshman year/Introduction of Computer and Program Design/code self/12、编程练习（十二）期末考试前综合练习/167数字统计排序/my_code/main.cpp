//second my code

#include <stdio.h>

struct number{
	int example;
	int sum;
};

int main(void)
{
	//定义初始数据，输入并计数 
	int n;
	scanf("%d", &n);
	
	//只记录相应次数 
	int num; //存数字
	int sum[1001] = {0}; //存数字出现次数 
	for(int i=0; i<n; i++)
	{
		scanf("%d", &num[i]);
		sum[num[i]]++;
	}
	
	//记录	 
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(num[i].sum < num[j].sum)
			{
				struct number temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
			if(num[i].sum == num[j].sum)
			{
				if(num[i].example > num[i].example)
				{
					struct number temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				} 
			}	
		}
	} 
	
	/*
	//先将1-1000赋值给相应的位置 
	int num_0[1000] = {0};
	for(int i=0; i<1000; i++)
	{
		num_0[i] = i;
	} 
	
	//输入相应的值 
	int num_1[1000] = {0}; 
	for(int i=0; i<n; i++)
	{
		scanf("%d", &num_1[i]);
	}
	
	//将1000位以内的数字放入另一个数组中，同时利用结构体来记录相对应的次数 
	struct number num[1000] = {0, 0}; 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<1000; j++)
		{
			if(num_0[j] == num_1[i])
				num[i].sum++;		
		}
	}
	
	//排序
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(num[i].sum < num[j].sum)
			{
				struct number temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
			if(num[i].sum == num[j].sum)
			{
				if(num[i].example > num[i].example)
				{
					struct number temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				} 
			}	
		}
	} 
	
	for(int i=0; i<1000; i++)
	{
		printf("%d %d\n", num[i].example, num[i].sum);
	}	
	*/
	
	return 0;
}

















//first my code

/*
#include <stdio.h>

struct number{
	int example;
	int sum;
};

int main(void)
{
	//定义初始数据，输入并计数 
	int n;
	scanf("%d", &n);
	
	//先将1-1000赋值给相应的位置 
	int num_0[1000] = {0};
	for(int i=0; i<1000; i++)
	{
		num_0[i] = i;
	} 
	
	//输入相应的值 
	int num_1[1000] = {0}; 
	for(int i=0; i<n; i++)
	{
		scanf("%d", &num_1[i]);
	}
	
	//将1000位以内的数字放入另一个数组中，同时利用结构体来记录相对应的次数 
	struct number num[1000] = {0, 0}; 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<1000; j++)
		{
			if(num_0[j] == num_1[i])
				num[i].sum++;		
		}
	}
	
	//排序
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(num[i].sum < num[j].sum)
			{
				struct number temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
			if(num[i].sum == num[j].sum)
			{
				if(num[i].example > num[i].example)
				{
					struct number temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				} 
			}	
		}
	} 
	
	for(int i=0; i<1000; i++)
	{
		printf("%d %d\n", num[i].example, num[i].sum);
	}	
	
	return 0;
}
*/







