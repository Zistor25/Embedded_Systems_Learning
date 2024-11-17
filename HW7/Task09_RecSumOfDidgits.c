
#include <stdio.h>

int sum_didgits(int n)
    {
    if (n>0)
        {
            int sum = n%10 + sum_didgits(n/10);
            return sum;
        }
    return 0;
    }


int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    printf("%d", sum_didgits(n));
    return 0;
}
