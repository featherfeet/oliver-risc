#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t thirtytwo = 0;
    uint8_t eight = 255;
    thirtytwo |= eight;
    thirtytwo = thirtytwo << 8;
    printf("%d\n", thirtytwo);
    return 0;
}
