#include <stdio.h>

bool f(int i)
{
    if (i >= 1 && i <= 5)
        return true;
    else
        return false;
}

int main(void)
{
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);///分别是星期， 雾霾指数，车牌号
    c %= 10;

    //下面是判断:分别为 星期、指数、车牌号
    if (f(a))
    {
        if (b < 200)
            printf("%d no", c);
        else if (b >= 200 && b <= 400)
        {
            if (a==1&&(c==1||c==6))
                printf("%d yes", c);
            else if (a==2&&(c==2||c==7))
                printf("%d yes", c);
            else if (a==3&&(c==3||c==8))
                printf("%d yes", c);
            else if (a==4&&(c==4||c==9))
                printf("%d yes", c);
            else if (a==5&&(c==5||c==0))
                printf("%d yes", c);
            else
                printf("%d no", c);
        }
        else
        {
            if ((a==1||a==3||a==5)&&(c==1||c==3||c==5||c==7||c==9))
                printf("%d yes", c);
            else if ((a==2||a==4)&&(c==0||c==2||c==4||c==6||c==8))
                printf("%d yes", c);
            else
                printf("%d no", c); //每次条件分析都要考虑到“else”这个地方
        }

    }
    else
        printf("%d no", c);

    return 0;
}
