#ifndef _APTO
#define _APTO
typedef struct {
    int nQuarto, nVagas, Andar, nAndares;
    char Lazer;
    int pM2AC;
    float AreaC;
} tApto;
void read_Apto(tApto *, FILE*, float*, float*);
#endif