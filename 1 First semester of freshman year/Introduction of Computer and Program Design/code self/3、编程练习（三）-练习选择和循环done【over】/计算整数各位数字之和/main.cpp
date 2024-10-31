# include <stdio.h>

int main(void)
{
    int a; //定义输入的正整数；
    int b; //作为每位数的变量；
    int sum = 0; //定义所求的和；

    scanf("%d", &a);

    //下面是求整数中各位数的和：运用取余和除法
    int i; //定义循环中间变量
    for (i=1; a>0; i++)
    {
        b = a % 10;
        sum = sum +b;
        a = a / 10;
    }

    printf("%d\n", sum);

    return 0;
}
