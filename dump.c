#include <stdio.h>
#include "dump.h"

void dump(void* p, int n) {
    unsigned char* p1 = (unsigned char*)p;
    while (n--) {
       printf("p - %02x\n", p1, *p1);
       p1++;
    }
}
