
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t n;
    uint32_t mask = 0xFFFFFFFF;
    uint32_t shift;
    scanf("%" SCNu32 " %" SCNu32, &n, &shift);
    mask >>= (32-shift);
    printf("%" PRIu32, n & mask);
    return 0;
}
