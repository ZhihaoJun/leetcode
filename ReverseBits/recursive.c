#include <stdio.h>
#include <stdint.h>

uint32_t _reverseBits(uint32_t n, int bits) {
    int half = bits >> 1;
    if (bits == 1) return n;
    return (_reverseBits(n & ((1<<half)-1), half) << half) | _reverseBits(n >> half, half);
}

uint32_t reverseBits(uint32_t n) {
    return _reverseBits(n, 32);
}

int main() {
    printf("%d\n", reverseBits(43261596) == 964176192);
    printf("%d\n", reverseBits(964176192) == 43261596);
    printf("%d\n", reverseBits(0) == 0);
    printf("%d\n", reverseBits(1) == 2147483648);
    printf("%d\n", reverseBits(4294967295) == 4294967295);
    return 0;
}
