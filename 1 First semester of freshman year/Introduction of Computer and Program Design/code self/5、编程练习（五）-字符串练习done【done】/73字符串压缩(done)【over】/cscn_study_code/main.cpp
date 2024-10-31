#include<stdio.h>
#include<ctype.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char a[50],ch;
	int i,j,count;
	count = 0;
	scanf("%s",a);
	
	/******************************************************************************/
	for(i = 0; i < strlen(a); i++){
		
		if(isalpha(a[i])){
			ch = a[i];
			printf("%c",ch);
			
		}else
		{
			count = count * 10 + (a[i] - '0');
			if(isdigit(a[i+1]))
				continue;
			else{
				for(j=0; j<count-1;j++)//前面以及输出了一个字母所以要减去1 
					printf("%c",ch);
					count = 0;
			}
		}
	}
	/******************************************************************************/
	
	return 0;
}

