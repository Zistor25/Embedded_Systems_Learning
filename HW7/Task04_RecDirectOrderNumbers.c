
#include <stdio.h>

void direct_order_num(unsigned int n)
    {
    if (n > 9)
    {
        direct_order_num(n/10);
    }
    printf("%u ", n%10);
    return;
    }


int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%u", &n);
    direct_order_num(n);
    return 0;
}
