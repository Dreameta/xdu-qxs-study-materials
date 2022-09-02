# include <stdio.h>

int main(void)
{
    int h, m;
    float t, T;

    scanf("%d%d", &h, &m);

    t = (float)h + m/60.0;
    T = 4*t*t/(t+2)-20;

    printf("%.2f", T);

    return 0;
}
