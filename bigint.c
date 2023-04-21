#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
void big_comp2(BigInt res, BigInt a) {
    long part1 = 0;
    long part2 = 0;

    unsigned char* part1_dump = (unsigned char*)&part1;
    unsigned char* part2_dump = (unsigned char*)&part2;

    if (*(part1_dump) == LONG_MIN || *(part2_dump) == LONG_MIN) {
        printf("LONG_MIN\n"); 
        return;
    }


    for (int i = 0; i < 8; i++) {
        *(part1_dump + i) = *(a + i);
    }
    for (int i = 0; i < 8; i++) {
        *(part2_dump + i) = *(a + 8 + i);
    }

    if (part1 == 0 && part2 == 0) goto atr;

    part1 = ~part1 + 1;
    if (part1 > LONG_MAX) {
        part2 = ~part2 + 1;
    } else
        part2 = ~part2;

atr:
    for (int i = 0; i < 8; i++) {
        *(res + i) = *part1_dump;
	part1_dump++;
    }
    for (int i = 8; i < 16; i++) {
        *(res + i) = *part2_dump;
	part2_dump++;
    }
}

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b) {
    unsigned char excedente = 0;
    int temp = 0;
    for (int i = 0; i < 16; i++) {
        temp = a[i] + b[i];
        res[i] = excedente;
        if (temp + excedente > 0xFF) {
            excedente = (temp + excedente) % 0xFF;
            res[i] += (unsigned char)(temp - excedente);
        } else {
            res[i] += (unsigned char)temp;
        }          
    }
}


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

