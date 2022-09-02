# include <stdio.h>

int main(void)
{
    int a, b; //定义所需范围的区间

    scanf("%d%d", &a, &b);

    int i; //循环计数变量1；
    int j; //循环计数变量2；
    int sum = 0; //
    for(i=a; i<=b; i++) //第一层循环：找出a，b之间所有的数
    {
        for(j=1; j<i; j++) //判断哪些数是因子：一个数一个数的试；
        {
            if (i % j == 0)
                sum = sum + j;
        }

        if(sum == i) //判断这些因子的和与原来的数字是否一样；
            printf("%d\n", sum);
        sum = 0; //初始化：赋值之后重新赋值为0，进行下一个数的判断
    }

    return 0;
}
