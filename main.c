#include <stdio.h>
#include <inttypes.h>

int main(int argc, char* argv[])
{
    register uint64_t x17 __asm("x17") = 0x123467;
    register uint64_t x16 __asm("x16") = 0x55aa00ff;

    asm volatile("hint 0x8" : "+r"(x17) : "r"(x16)); // pacia1716
    uint64_t checkValue = x17;
    printf("pac %llx\n", x17);
    asm volatile ("hint  0xc" // autia1716
                  : "+r"(x17)
                  : "r"(x16)
                  :);

    printf("auth %llx\n", x17);


    asm volatile ("mov   x30, %[checkValue]     \r\n" \
                  "hint  0x7                    \r\n" \
                  "mov   %[checkValue], x30     \r\n" \
        : [checkValue] "+r"(checkValue)
        :
        : "x30");
    printf("checkValue %llx\n", checkValue);
    return 0;
}
