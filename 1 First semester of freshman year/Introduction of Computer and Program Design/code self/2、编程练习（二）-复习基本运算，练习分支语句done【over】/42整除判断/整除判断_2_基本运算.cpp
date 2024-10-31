# include<stdio.h>

int main(void)
{
    int a, b;
    int c, d;

    scanf("%d%d", &a, &b);

    if (a%b == 0)
        printf("yes");
    else
    {
        c = a/b;
        d = a%b;
        printf("%d %d", c, d);
    }

    return 0;
}
