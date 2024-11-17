
#include <stdio.h>

void print_n_to_1(unsigned int n)
    {
    printf("%u ", n);
    if (n > 1)
        print_n_to_1(n-1);
    return;
    }


int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%u", &n);
    print_n_to_1(n);
    return 0;
}
