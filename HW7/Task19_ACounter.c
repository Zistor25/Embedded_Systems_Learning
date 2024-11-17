
#include <stdio.h>

int a_counter(void)
{
    char c;
    c = getchar();
    if(c=='.')
        return 0;
    return (c=='a')+a_counter();
}

int main()
{
    
    printf("%d", a_counter());
    return 0;
}
 

