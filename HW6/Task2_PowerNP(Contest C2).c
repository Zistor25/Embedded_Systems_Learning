
#include <stdio.h>
#include <inttypes.h>

int32_t  power (int32_t  number, int32_t  p)
{
    int32_t nP;
    if (p==0)
    nP = 1;
else
    nP = number;

for(int i=1; i<p; i++)
    {
        nP *= number;
    }
    return nP;
}

int main(int argc, char **argv)
{
    int32_t number;
    int32_t p;
    scanf("%" SCNd32 " %" SCNd32, &number, &p);
    printf("%" PRId32, power(number, p));
    return 0;
}
