# include <stdio.h>

int main()
{
    int m, n;
    int c[100][100]; //分别定义行数、列数及其各部分内容；

    scanf("%d%d", &m, &n);

    int i, j; //定义二重数组的循环变量；
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }

    int a; //作为中间赋值点,找出每行的最小值；
    int x, y; //定义储存位置变量；
    for (i = 0; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
                a = c[i][0];
            if (c[i][j] < c[i][0])
                a = c[i][j];
                x = i;
                y = j;
        }
    }

    int b; //作为中间赋值变量，找出每行的最大值；
    for (j = 0; j < m; j++)
    {
        for (i = 1; i < n; i++)
        {
        b = c[0][j];
        if (c[i][j] > c[0][j])
            b = c[i][j];
        }
    }

    if (a == b)
        printf("%c %c %d", x, y, b);
    else
        printf("no\n");

    return 0;
}

