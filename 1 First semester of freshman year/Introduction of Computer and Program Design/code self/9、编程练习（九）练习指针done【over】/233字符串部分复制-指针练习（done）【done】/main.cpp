# include <stdio.h>
# include <string.h>

int main(void)
{
	/*初始化函数*/
	void copystr(char* p, int m);
	
	/*输入数据额*/
	char str[50];
	gets(str);
	char *p = str;
	
	int m;
	scanf("%d", &m);
	
	copystr(p, m);
	
	return 0;
}


/*
	@relief 从第m项截断并赋值，并进行输出； 
*/
void copystr(char* p, int m)
{
	char str1[50] = {0};
	
	for(int i = 0; i<strlen(p); i++){
		str1[i] = p[m-1+i];
	}
	
	if(m > strlen(p))
		printf("error");
	else{
		for(int i = 0; i<(strlen(p))-m+1; i++){
			printf("%c", str1[i]);
		}
	}
}

/*
	小结：其实这道题不用指针也是可以的，这里没有涉及到指针的相关运算。
	而且这道题其实感觉没有写的很好，只是两端数组的截断赋值。
	但也算是完成了任务，今后要把精力放在一些更重要且经典的一些算法上面。 
*/



