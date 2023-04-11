#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bigint.h"
#include "dump.h"

int main(void) {
    /* Caso 1.a) */
    BigInt caso_1_a;
    big_val(caso_1_a, -567754);
    dump(caso_1_a);
    /* Caso 1.b) */
    BigInt caso_1_b;
    big_val(caso_1_b, 3534654);
    dump(caso_1_b);
    /* Caso 1.c) */
    BigInt caso_1_c;
    big_val(caso_1_c, 3);
    dump(caso_1_c);
    /* Caso 1.d) */
    BigInt caso_1_d;
    big_val(caso_1_d, -22);
    dump(caso_1_d);
    /* Caso 1.e) */
    BigInt caso_1_e;
    big_val(caso_1_e, LONG_MAX);
    dump(caso_1_e);
    /* Caso 1.f) */
    BigInt caso_1_f;
    big_val(caso_1_f, LONG_MIN);
    dump(caso_1_f);
    /* Caso 1.g) */
    BigInt caso_1_g;
    big_val(caso_1_a, 0);
    dump(caso_1_g);


    return 0;
}
