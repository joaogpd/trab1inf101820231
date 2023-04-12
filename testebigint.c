#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bigint.h"

void dump(void* p, int n) {
    unsigned char* p1 = (unsigned char*)p;
    while (n--) {
        printf("%p - %02x\n", p1, *p1);
	p1++;
    }
}

void compare(void* res, void* test) {
    unsigned char* res1 = (unsigned char*)res;    
    unsigned char* test1 = (unsigned char*)test;
    int n = 8;
    while (n--) {
        if (*res1 != *test1) {
	    printf("FAILED\n");
	    return;
	}
	res1++;
	test1++;
    }
    test1--;
    n = 8;
    if (*test1 & 0x80) {
        while (n < 16) {
            if (*res1 != 0xFF) {
	        printf("FAILED\n");
	        return;
 	    }
	    res1++;
	    n++;
	}
    } else {
        while (n < 16) {
            if (*res1 != 0x00) {
	        printf("FAILED\n");
	        return;
 	    }
	    res1++;
	    n++;
	}
    }
    printf("SUCCESS\n");
}

int main(void) {
    long temp = 0;
    /* Caso 1.a) */
    BigInt caso_1_a;
    temp = -5;
    big_val(caso_1_a, -5);

    compare(&caso_1_a, &temp);
    /* Caso 1.b) */
    BigInt caso_1_b;
    temp = 3;
    big_val(caso_1_b, 3);
    
    compare(&caso_1_b, &temp);
    /* Caso 1.c) */
    BigInt caso_1_c;
    temp = 3;
    big_val(caso_1_c, 3);

    compare(&caso_1_c, &temp);
    /* Caso 1.d) */
    BigInt caso_1_d;
    temp = -2;
    big_val(caso_1_d, -2);

    compare(&caso_1_d, &temp);
    /* Caso 1.e) */
    BigInt caso_1_e;
    temp = LONG_MAX;
    big_val(caso_1_e, LONG_MAX);

    compare(&caso_1_e, &temp);
    /* Caso 1.f) */
    BigInt caso_1_f;
    temp = LONG_MIN;
    big_val(caso_1_f, LONG_MIN);

    compare(&caso_1_f, &temp);
    /* Caso 1.g) */
    BigInt caso_1_g;
    temp = 0;
    big_val(caso_1_g, 0);

    compare(&caso_1_g, &temp);

    return 0;
}
