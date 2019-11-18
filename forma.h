#ifndef _FORMA
#define _FORMA
#include "retangulo.h"
#include "trapezio.h"
#include "triangulo.h"
typedef union {
    tTriangle t;
    tRetangle r;
    tTrap tp;
} tForma;
void read_Forma(tForma*, int*, float*, float*, FILE*);
char ponte_Formatag(tForma*, int*);
#endif