
#include <stdio.h>
#include <inttypes.h>

uint32_t right_shift(uint32_t n, uint32_t shift)
{
    return (n >> shift) | (n << (32 - shift));
}

int main(int argc, char **argv)
{
    uint32_t n, shift;
    scanf("%" SCNu32 " %" SCNu32, &n, &shift);
    printf("%" PRIu32, right_shift(n, shift));
    return 0;
}
