
#include <stdio.h>

void print_didgits(int n)
    {
        if (n>0)
        {
            print_didgits(n/10);
            printf("%d ", n%10);
        }
    }



int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    print_didgits(n);
    return 0;
}

