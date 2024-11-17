#include <stdio.h>

int dec_to_bin(unsigned int n)
    {
        if (n>0)
            return (n%2) + dec_to_bin(n/2);
        return 0;
    }


int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%u", &n);
    printf("%u", dec_to_bin(n));
    return 0;
}


