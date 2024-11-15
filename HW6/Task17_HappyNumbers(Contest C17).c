#include <stdio.h>

int is_happy_number(int number)
{
    int sum=0, work=1;
    for(; number>0;)
    {
        sum += number%10;
        work *= number%10;
        number /= 10;
    }
    return sum==work;
}

int main(void)
{
    int number;
    scanf("%d", &number);
    printf(is_happy_number(number)==1 ? "YES" : "NO");
    return 0;
}

