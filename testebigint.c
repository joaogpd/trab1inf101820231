#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bigint.h"
#include "dump.h"

int main(void) {
    /* Caso 1.a) */
    BigInt caso_1_a;
    big_val(caso_1_a, -5);
    dump(caso_1_a, 16);
    printf("\n");
    /* Caso 1.b) */
    BigInt caso_1_b;
    big_val(caso_1_b, 3);
    dump(caso_1_b, 16);
    printf("\n");
    /* Caso 1.c) */
    BigInt caso_1_c;
    big_val(caso_1_c, 3);
    dump(caso_1_c, 16);
    printf("\n");
    /* Caso 1.d) */
    BigInt caso_1_d;
    big_val(caso_1_d, -2);
    dump(caso_1_d, 16);
    printf("\n");
    /* Caso 1.e) */
    BigInt caso_1_e;
    big_val(caso_1_e, LONG_MAX);
    dump(caso_1_e, 16);
    printf("\n");
    /* Caso 1.f) */
    BigInt caso_1_f;
    big_val(caso_1_f, LONG_MIN);
    dump(caso_1_f, 16);
    printf("\n");
    /* Caso 1.g) */
    BigInt caso_1_g;
    big_val(caso_1_a, 0);
    dump(caso_1_g, 16);
    printf("\n");


    return 0;
}
