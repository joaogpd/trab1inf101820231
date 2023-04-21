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

/* Funcao para comparar se o valor apontado por test esta corretamente 
 * representado pelo valor apontado por res.
 */

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
    printf("Testagem funcao big_val(): \n");
    long temp = 0;
    /* Caso 1.a) */
    BigInt caso_1_a;
    temp = -5343253;
    big_val(caso_1_a, temp);

    compare(&caso_1_a, &temp);
    /* Caso 1.b) */
    BigInt caso_1_b;
    temp = 35345346;
    big_val(caso_1_b, temp);
    
    compare(&caso_1_b, &temp);
    /* Caso 1.c) */
    BigInt caso_1_c;
    temp = -22;
    big_val(caso_1_c, temp);

    compare(&caso_1_c, &temp);
    /* Caso 1.d) */
    BigInt caso_1_d;
    temp = 31;
    big_val(caso_1_d, temp);

    compare(&caso_1_d, &temp);
    /* Caso 1.e) */
    BigInt caso_1_e;
    temp = LONG_MAX;
    big_val(caso_1_e, temp);

    compare(&caso_1_e, &temp);
    /* Caso 1.f) */
    BigInt caso_1_f;
    temp = LONG_MIN;
    big_val(caso_1_f, temp);

    compare(&caso_1_f, &temp);
    /* Caso 1.g) */
    BigInt caso_1_g;
    temp = 0;
    big_val(caso_1_g, temp);

    compare(&caso_1_g, &temp);

    printf("Testagem funcao big_comp2(): \n");
    
    /* Caso 2.a) */
    BigInt caso_2_a;
    BigInt caso_2_a_aux;
    temp = -53435345634;
    big_val(caso_2_a, temp);
    big_comp2(caso_2_a_aux, caso_2_a);

    temp = 53435345634;
    big_val(caso_2_a, temp);
    compare(&caso_2_a_aux, &caso_2_a);
    /* Caso 2.b) */
    BigInt caso_2_b;
    BigInt caso_2_b_aux;
    temp = 345453453;
    big_val(caso_2_b, temp);
    big_comp2(caso_2_b_aux, caso_2_b);

    temp = -345453453;
    big_val(caso_2_b, temp);
    compare(&caso_2_b_aux, &caso_2_b);
    /* Caso 2.c) */
    BigInt caso_2_c;
    BigInt caso_2_c_aux;
    temp = -1;
    big_val(caso_2_c, temp);
    big_comp2(caso_2_c_aux, caso_2_c);

    temp = 1;
    big_val(caso_2_c, temp);
    compare(&caso_2_c_aux, &caso_2_c);
    /* Caso 2.d) */
    BigInt caso_2_d;
    BigInt caso_2_d_aux;
    temp = 1;
    big_val(caso_2_d, temp);
    big_comp2(caso_2_d_aux, caso_2_d);

    temp = -1;
    big_val(caso_2_d, temp);
    compare(&caso_2_d_aux, &caso_2_d);
    /* Caso 2.e) */
    BigInt caso_2_e;
    BigInt caso_2_e_aux;
    temp = LONG_MAX;
    big_val(caso_2_e, temp);
    big_comp2(caso_2_e_aux, caso_2_e);

    temp = -LONG_MAX;
    big_val(caso_2_e, temp);
    compare(&caso_2_e_aux, &caso_2_e);
    /* Caso 2.f) */
    BigInt caso_2_f;
    BigInt caso_2_f_aux;
    temp = LONG_MIN + 1;
    big_val(caso_2_f, temp);
    big_comp2(caso_2_f_aux, caso_2_f);
    
    temp = LONG_MAX;
    big_val(caso_2_f, temp);
    compare(&caso_2_f_aux, &caso_2_f);
    /* Caso 2.g) */
    BigInt caso_2_g;
    BigInt caso_2_g_aux;
    temp = 0;
    big_val(caso_2_g, temp);
    big_comp2(caso_2_g_aux, caso_2_g);

    temp = 0;
    big_val(caso_2_g, temp);
    compare(&caso_2_g_aux, &caso_2_g);

    printf("Testagem funcao big_sum(): \n");
    
    /* Caso 3.a) */
    BigInt caso_3_a;
    BigInt caso_3_a_2;
    BigInt caso_3_a_res;
    BigInt caso_3_a_aux;

    temp = 42354235353453;
    big_val(caso_3_a, temp);
    temp = 34235346474457;
    big_val(caso_3_a_2, temp); 
    temp = 42354235353453 + 34235346474457;
    big_val(caso_3_a_aux, temp);
    printf("first\n");
    dump(caso_3_a_aux, 16);

    big_sum(caso_3_a_res, caso_3_a, caso_3_a_2);
    printf("first\n");
    dump(caso_3_a_res, 16);

    compare(&caso_3_a_aux, &caso_3_a_res);
    /* Caso 3.b) */
    BigInt caso_3_b;
    BigInt caso_3_b_2;
    BigInt caso_3_b_res;
    BigInt caso_3_b_aux;

    temp = LONG_MAX;
    big_val(caso_3_b, temp);
    temp = 1;
    big_val(caso_3_b_2, temp); 
    // temp = 581809899;
    // big_val(caso_3_b_aux, temp);

    big_sum(caso_3_b_res, caso_3_b, caso_3_b_2);

    // printf("\nHardset\n");
    // dump(caso_3_b_aux, 16); 

  //  printf("\nfunc call\n");
//    dump(caso_3_b_res, 16); 

    // compare(&caso_3_a_aux, &caso_3_a_res);

    return 0;
}
