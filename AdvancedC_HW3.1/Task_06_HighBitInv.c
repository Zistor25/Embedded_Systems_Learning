#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t n, res;
    uint32_t mask = 0xFF000000;
    scanf("%" SCNu32, &n);
    res = (~n & mask) | (n & ~mask);
    printf("%" PRIu32, res);
    return 0;
}
