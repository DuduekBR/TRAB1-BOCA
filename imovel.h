#ifndef _IMOVEL
#define _IMOVEL
#define TAM_name 41
#include "propriedade.h"
typedef struct Imovel {
    int tag;
    unsigned int ident;
    char nome[TAM_name];
    tProperty imovel;
    float preco;
    float area;
} tImovel;
int read_Imovel(tImovel*, FILE*);
void read_ImovelAtual(tImovel *, FILE*, char*, int);
int ret_ident(tImovel *);
int ret_type(tImovel *);
float ret_area(tImovel *);
float ret_preco(tImovel *);
char type_Terreno(tImovel *);
int cmp_PrecoCrescente(tImovel *, tImovel *);
int cmp_AreaDecrescente(tImovel *, tImovel *);
int cmp_nQuartos(tImovel *, tImovel *);
#endif