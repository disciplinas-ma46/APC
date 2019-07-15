# include <stdio.h>

int main(void)
{
    int i;

    for (i = 32; i <= 126; i++)
    {
        printf("%c [%d]\n", i, i);
    }

    return 0;
}
