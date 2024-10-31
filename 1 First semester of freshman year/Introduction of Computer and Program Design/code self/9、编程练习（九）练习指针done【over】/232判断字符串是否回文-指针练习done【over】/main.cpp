# include <stdio.h>
# include <string.h>

int main(void)
{
	bool judgement_Palindrome_string(char* p);

	char x[50];
	gets(x);
	
	char* p = x; //将数组地址转换成指针
	
	if (judgement_Palindrome_string(p))
		printf("yes");
	else
		printf("no");
	
	return 0;
}

bool judgement_Palindrome_string(char* p)
{
	//step1：需要记录该指针对应的数组的长度，以便之后知道循序终止的界限 
		//方法一：调用计算字符串长度的函数
		/*
		int sum;
		sum = strlen(p);
	 	*/
		//方法二：直接编写对应步骤
		
		int sum = 0; 
		char *m = p; //在计算长度的过程中，避免指针被改变 
		while(*m != '\0')
		{
			sum++;
			m++;
		}
		
		//for(sum = 0; *p != '\0'; sum++){}
		
	//step2：判断是否为回文。主要思想是利用前后对应位置是否一致 
	for(int i = 0; i <= sum; i++){
		if(p[i] == p[sum-1]) //注意指针加下标可以作为数组使用；
			 sum--; 
		else
			return false;
	} 
	return true;
}


