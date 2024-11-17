
#include <stdio.h>
#include <math.h>

void dec_to_bin(unsigned int n)
    {
    if (n > 1)
    {
        dec_to_bin(n/2);
    }
    printf("%u", n%2);
    }


int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%u", &n);
    dec_to_bin(n);
    return 0;
}
