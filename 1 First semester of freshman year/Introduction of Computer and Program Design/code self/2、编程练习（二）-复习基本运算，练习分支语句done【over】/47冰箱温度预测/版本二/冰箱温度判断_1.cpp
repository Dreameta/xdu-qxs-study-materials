# include <stdio.h>

int main(void)
{
    float T, t;
    int h, m;

    scanf("%d%d", &h, &m);
    t = h + (float)m/60;
    T = (4*t*t)/(t+2) - 20;

    printf("%.2f", T);

    return 0;

}

