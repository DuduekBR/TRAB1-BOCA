#ifndef _TRAPEZIO
#define _TRAPEZIO
#include "terreno.h"
typedef struct Trap {
    tGround ter;
    float base1;
    float base2;
    float altura;
} tTrap;
void read_trap(tTrap *, float*, float*, FILE*);
char ponte_tagTP(tTrap *);
#endif