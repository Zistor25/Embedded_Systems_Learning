
#include <stdio.h>

int main(int argc, char **argv)
{
    char c;
    int shift = 0;

    while ((c = getchar()) != '.')
    {
        if (c >= '0' && c <= '9')
        {
            shift = 10 * shift + c - '0';
        }
        else
        {
            if (c >= 'a' && c <= 'z')
            {
                c = 'a' + ((c - 'a') + shift) % 26;
            }
            if (c >= 'A' && c <= 'Z')
            {
                c = 'A' + ((c - 'A') + shift) % 26;
            }
            printf("%c", c);
        }
    }
    printf(".");
    return 0;
}
