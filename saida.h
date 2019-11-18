#ifndef _SAIDA
#define _SAIDA
#define TAM_houses 301
typedef struct {
    int caras[TAM_houses];
    int argilosas[TAM_houses];
    int casas[TAM_houses];
    int soma, qntd_caras, qntd_argilosas, qntd_casas;
} tSaida;
void org_vetorSaida(int* , int* , float );
void vetor_Casas(tImobiliaria *, tSaida *);
void vetor_Argila(tImobiliaria *, tSaida *);
void vetor_Caras(tImobiliaria *, tSaida *);
int vetor_Imobiliaria(tImobiliaria *, tSaida *);
void type_printSaida(int, int*);
void printa_Saida(tSaida *, tImobiliaria*);
#endif