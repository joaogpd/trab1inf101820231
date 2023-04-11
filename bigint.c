#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"


/* Atribuição (com extensão) */
void big_val (BigInt res, long val) {
    unsigned char* p1 = (unsigned char*)&val;
    int n = sizeof(long);
    for (int i = 0; i < n; i++, p1++) {
        *(res + i) = *p1;
    }
    p1--;
    if ((*p1) & 0x80) {
        for (int i = 8; i < 16; i++)
	    *(res + i) = 0xFF;
    } else {
        for (int i = 8; i < 16; i++)
	    *(res + i) = 0x00;
    }
}

/* Operações Aritméticas */

/* res = -a */
void big_comp2(BigInt res, BigInt a);

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b);

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b);

/* res = a * b */
void big_mul(BigInt res, BigInt a, BigInt b);

/* Operações de Deslocamento */

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n);

/* res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n);

/* res = a >> n (aritmético)*/
void big_sar(BigInt res, BigInt a, int n);

