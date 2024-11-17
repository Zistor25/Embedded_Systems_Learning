
#include <stdio.h>

int rec_sum(int n)
    {
    if (n <= 1)
        return 1;
    int sum = n + rec_sum(n-1);
    return sum;
    }


int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    printf("%d", rec_sum(n));
    return 0;
}

