#include <stdio.h>
#include <inttypes.h>

int main(int argc, char* argv[])
{
    uint64_t modifier = 2;
    uint64_t data_ia = 0x12345678;
    uint64_t data_ib = 0x12345678;
    uint64_t data_da = 0x12345678;
    uint64_t data_db = 0x12345678;

    printf("PACIA             PACIB             PACDA             PACDB\n");
    printf("%016" PRIX64 "  %016" PRIX64 "  %016" PRIX64 "  %016" PRIX64 "\n", data_ia, data_ib, data_da, data_db);

    asm volatile("pacia %[reg], %[mod]" : [reg] "+r" (data_ia) : [mod] "r" (modifier) : );
    asm volatile("pacib %[reg], %[mod]" : [reg] "+r" (data_ib) : [mod] "r" (modifier) : );
    asm volatile("pacda %[reg], %[mod]" : [reg] "+r" (data_da) : [mod] "r" (modifier) : );
    asm volatile("pacdb %[reg], %[mod]" : [reg] "+r" (data_db) : [mod] "r" (modifier) : );

    printf("%016" PRIX64 "  %016" PRIX64 "  %016" PRIX64 "  %016" PRIX64 "\n", data_ia, data_ib, data_da, data_db);

    asm volatile("autia %[reg], %[mod]" : [reg] "+r" (data_ia) : [mod] "r" (modifier) : );
    asm volatile("autib %[reg], %[mod]" : [reg] "+r" (data_ib) : [mod] "r" (modifier) : );
    asm volatile("autda %[reg], %[mod]" : [reg] "+r" (data_da) : [mod] "r" (modifier) : );
    asm volatile("autdb %[reg], %[mod]" : [reg] "+r" (data_db) : [mod] "r" (modifier) : );

    printf("%016" PRIX64 "  %016" PRIX64 "  %016" PRIX64 "  %016" PRIX64 "\n", data_ia, data_ib, data_da, data_db);
    return 0;
}
