#ifndef _IMOBILIARIA
#define _IMOBILIARIA
#include "imovel.h"
#define TAM_houses 301
typedef struct Imobiliaria{
    tImovel house[TAM_houses];
    int qnt_Houses;
    float percent_caro,
    percent_Argila;
    float area_lim,
    preco_lim;
    int i, j, k;
} tImobiliaria;
void org_Imobiliaria(tImobiliaria *, int f(tImovel*, tImovel*));
void read_ImobiliariaInicio(tImobiliaria *, FILE*);
void read_ImobiliariaAtual(tImobiliaria *, FILE*);
int read_ImobiliariaEspec(tImobiliaria *, FILE*);
#endif