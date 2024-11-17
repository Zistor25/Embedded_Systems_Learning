
#include <stdio.h>

int rec_power(int n, int p)
    {
        if (p==0)
        return 1;
        
        else if (p>1)
        return n * rec_power(n, p-1);
    }

int main(int argc, char **argv)
{
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%d", rec_power(n, p));
    return 0;
}

