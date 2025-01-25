
#include <stdio.h>

int main(int argc, char **argv)
{
    char c;
    int counter_max;
    int counter = 0;
    long number = 0;
    long max;
    int neg = 1;
    do
    {
        c = getchar();
        if (c == ' ' || c == '\n')
        {
            number = neg * number;
            if (counter == 1)
            {
                max = number;
                counter_max = 1;
            }
            else if (number > max && counter > 1)
            {
                max = number;
                counter_max = 1;
            }
            else if (number == max && counter_max > 0)
            {
                counter_max++;
            }
        }
        number = 0;
        neg = 1;
        counter++;

        if (c == '-')
        {
            neg = -1;
        }
        if (c >= '0' && c <= '9')
        {
            number = 10 * number + c - '0';
        }
    } while (c != '\n');
    printf("%d\n", counter_max);
    return 0;
}
