
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t n;
    uint32_t res = 0;
    uint32_t mask = 1;
    scanf("%" SCNu32, &n);
    for (int i = 0; i <= 31; i++)
    {
        res += n & mask;
        n >>= 1;
    }
    printf("%" PRIu32, res);
    return 0;
}
