#ifndef _CASA
#define _CASA
typedef struct {
    int nQuarto, nVagas, nPavimentos;
    int pM2AP, pM2AL;
    float AreaP, AreaL;
} tCasa;
int ret_nQuarto(tCasa *);
void read_Casa(tCasa *, FILE*, float*, float*);
#endif