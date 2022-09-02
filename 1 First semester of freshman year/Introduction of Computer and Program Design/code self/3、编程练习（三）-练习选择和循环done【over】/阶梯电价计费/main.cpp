# include <stdio.h>

int main (void)
{
    float a; //电度数
    float b; //电价

    scanf("%f", &a);

    //判断属于哪个区间
    if (a > 0 && a <= 110)
        b = 0.5 * a;

    else if (a > 100 && a <= 210)
        b = 55 + 0.55*(a - 110);

    else
        b = 110 + 0.7*(a - 210);

    printf("%.2f\n", b);

    return 0;
}
