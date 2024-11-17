
#include <stdio.h>

void rev_order_num(unsigned int n)
    {
    if (n > 0)
    {
        printf("%u ", n%10);
        rev_order_num(n/10);
    }
    return;
    }


int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%u", &n);
    (n==0) ? printf("0") : rev_order_num(n);
    return 0;
}
