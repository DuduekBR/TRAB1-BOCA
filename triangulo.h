#ifndef _TRIANGULO
#define _TRIANGULO
#include "terreno.h"
typedef struct Triangle {
    tGround ter;
    float base;
    float altura;
} tTriangle;
void read_triangle(tTriangle*, float*, float*, FILE*);
char ponte_tagT(tTriangle*);
#endif