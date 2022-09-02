# include <stdio.h>

int main(void)
{
    int a, b;
    int sum, dif, pro, quo;

    scanf("%d %d", &a, &b);

    sum = a + b;
    dif = a - b;
    pro = a*b;
    quo = a/b;

    printf("%d\n %d\n %d\n %d\n", sum, dif, pro, quo);

    return 0;
}
