#ifndef _PROPRIEDADE
#define _PROPRIEDADE
#include "forma.h"
#include "apto.h"
#include "casa.h"
typedef union {
    tForma f;
    tCasa c;
    tApto a;
} tProperty;
void data_Property(tProperty*, int*, float*, float*, FILE*);
char ponte_TipoTerreno(tProperty*, int*);
int ponte_nQuartos(tProperty*);
#endif