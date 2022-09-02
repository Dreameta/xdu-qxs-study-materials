# include <stdio.h>

int main(void)
{
    int t;
    float j;

    scanf("%d", &t);

    j = ((float)t-32)*5/9;

    printf("%.2f\n", j);

    return 0;
}
