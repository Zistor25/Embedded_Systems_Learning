

#include <stdio.h>

void rec_print_num(int n)
    {
    if (n > 1)
        rec_print_num(n - 1);
    printf("%d ", n);
        }


int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    rec_print_num(n);
    return 0;
}

