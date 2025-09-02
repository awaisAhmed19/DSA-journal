
#include <limits.h>  // for INT_MAX and INT_MIN
#include <stdio.h>

int main() {
    int x = 1;
    int shift31, shift32;

    // Safe shift to the highest bit
    shift31 = x << 30;
    printf("1 << 31 = %d (hex: 0x%X)\n", shift31, shift31);

    // Shift by 32 (undefined behavior)
    shift32 = x << 29;
    printf("1 << 32 = %d (hex: 0x%X) !\n", shift32, shift32);

    return 0;
}
