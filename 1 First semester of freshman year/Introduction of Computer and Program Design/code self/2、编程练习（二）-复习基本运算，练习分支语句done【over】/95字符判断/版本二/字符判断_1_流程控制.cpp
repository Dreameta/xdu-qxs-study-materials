# include <stdio.h>

int main(void)
{
    char ch;

    scanf("%c", &ch);

    if (ch>=a && ch<='z')
    {
        ch -= 32;
        printf("%c", ch);
    }

    else if (ch>='A' && ch<='Z')
    {
        ch += 32;
        printf("%c", ch);
    }

    else
        printf("%c", ch);

    return 0;
}
