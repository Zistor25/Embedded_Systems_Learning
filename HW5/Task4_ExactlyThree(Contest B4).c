
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    int number;
    scanf("%d", &number);

    int n = 0;
    while (number>0)
    {
        number /= 10;
        n +=1;
    }
    
    
    if (n==3)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}

