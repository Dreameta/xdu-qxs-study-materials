# include <stdio.h>

int main(void)
{
    int a, b, c;
    int s;

    scanf("%d%d%d", &a, &b, &c);

    if (a*a + b*b == c*c)
        {
            s = a*b;
            printf("%d\n", s);
        }
    else
        printf("no");

    return 0;
}
