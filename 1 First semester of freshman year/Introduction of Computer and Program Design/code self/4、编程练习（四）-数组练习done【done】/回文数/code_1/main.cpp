# include <stdio.h>

int f(int x)
{
    int b, sum, d;
    while (x)
    {
        d = x%10;
        sum = sum*10 + d;
        x = x/10;
    }
    if (x == sum)
        return sum;
}

/*
试数：
a=12321 b=12321
sum = 0*10 + 1 = 1
b = b/10 = 1232

b=1232
sum =  1*10 + 1232%10 = 12
b = b/10 = 123
*/

int main()
{
    int a, b; //a为输入的数字
    int sum; //作为回文数的结果输出
    int c[100]; //储存每位数；
    int d; //输入数字的每位数；

    scanf("%d", &a);

    sum = f(a);//若a为回文数，则赋值给sum

/*
    b = a;
    //纯判断是否为回文数；
    while (b)
    {
        d = b%10;
        sum = sum*10 + d;
        b = b/10;
    }
*/

    int i; //循环计数变量
    int e = 0; //回文数中每位数之和

    //下面是回文数与否的判断
    if (a == sum)
    {
        for(i=0;b!=0;i++)
        {
            d = d%10;
            c[i] = d;  //将每位数赋值给数组；

            b = b/10;

            e = e + c[i];

        }
        printf("%d", e); //若为回文数进而求和
    }
    else
        printf("no");

    return 0;
}
