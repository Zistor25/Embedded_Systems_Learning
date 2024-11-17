
#include <stdio.h>

void from_a_to_b(int a, int b)
    {
    if (a<b)
    {
        printf("%d ", a);
        from_a_to_b(a+1, b);
    }
    
    if (a>b)
    {
        from_a_to_b(a, b+1);
        printf("%d ", b);
    }
        
    
    if(a==b)
    {
    printf("%d ", a);
    return;
    }

    }


int main(int argc, char **argv)
{
    unsigned int a, b;
    scanf("%d %d", &a, &b);
    from_a_to_b(a, b);
    return 0;
}
