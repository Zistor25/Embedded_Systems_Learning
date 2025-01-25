
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t n, shift, res;
    uint32_t max = 0;
    uint32_t mask = 0xFFFFFFFF;
    scanf("%" SCNu32 " %" SCNu32, &n, &shift);
    mask >>= (32 - shift);
    for (int i = 0; i <= (32 - shift); i++)
    {
        res = n & mask;
        res > max ? max = res : max;
        n >>= 1;
    }
    printf("%" PRIu32, max);
    return 0;
}
