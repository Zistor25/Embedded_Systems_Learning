
#include <stdio.h>
#include <inttypes.h>

struct pack_array
{
    uint32_t array;      // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
} pack;

void array2struct(int array[], struct pack_array *)
{
    for (int i = 0; i <= 31; i++)
    {
        pack.array = (pack.array << 1) | array[i];
        (array[i] > 0) ? pack.count1++ : pack.count0++;
    }
}

int main()
{
    struct pack_array *ptr;
    ptr = &pack;
    int array[32];
    for (int i = 0; i <= 31; i++)
    {
        scanf("%d", &array[i]);
    }
    array2struct(array, ptr);

    printf("%u ", pack.array);
    printf("%u ", pack.count0);
    printf("%u\n", pack.count1);
    return 0;
}
