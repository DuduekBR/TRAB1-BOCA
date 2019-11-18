#ifndef _RETANGULO
#define _RETANGULO
#include "terreno.h"
typedef struct Retangle {
    tGround ter;
    float l1;
    float l2;
} tRetangle;
void read_retangle(tRetangle*, float*, float*, FILE*);
char ponte_tagR(tRetangle *);
#endif