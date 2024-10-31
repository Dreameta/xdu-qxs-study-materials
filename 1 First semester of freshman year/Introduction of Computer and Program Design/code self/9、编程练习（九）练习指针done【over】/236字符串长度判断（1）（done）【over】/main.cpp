# include <stdio.h>

int Calculate_the_length_of_the_string(char* p){
	
	int sum = 0;
	while(*p != '\0'){
		sum++;
		p++;
	}
	
	return sum;
}

int main(void)
{
	/*ÊäÈëÊı¾İ*/
	char str[100]={0};
	char*p = str;
	gets(p);	
	
	printf("%d", Calculate_the_length_of_the_string(str));
	
	return 0;
}
