# include <stdio.h>

int main(void)
{
    char ch1, ch2;

    scanf("%c", &ch1);

    if (ch1 >= 65 && ch1 <= 90 )
    {
        ch2 = ch1 + 32;
        printf("%c\n", ch2);
    }
    else if (ch1 >= 97 && ch1 <= 122)
    {
        ch2 = ch1 - 32;
        printf("%c\n", ch2);
    }
    else
        printf("%c\n", ch1);

    return 0;
}
