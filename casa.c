#include <stdio.h>
#include "casa.h"
// (2.13.1)
float price_Casa(tCasa *x) {
    return (x->pM2AP * x->AreaP * x->nPavimentos)+(x->pM2AL * x->AreaL);
}
// (2.13.2)
float area_House(tCasa *x) {
    return x->AreaP * x->nPavimentos;
}
// (2.14)
// (2.14.1)
int ret_nQuarto(tCasa *x) {
    return x->nQuarto;
}
// (2.13)
void read_Casa(tCasa *x, FILE* file, float *area, float *preco) {
    fscanf(file, "%d%d%d", &x->nQuarto, &x->nVagas, &x->nPavimentos);
    fscanf(file, "%f%d%f%d%*c", &x->AreaP, &x ->pM2AP, &x->AreaL, &x->pM2AL);
    *area = area_House(x);
    *preco = price_Casa(x);
}
/*
tCasa  (1.5){
	2.13) read_Casa:
		-Lê os dados específicos do imóvel do tipo Casa, calcula seu preço e sua área;
		2.13.1) price_Casa:
			- Calcula o preço da casa;
		2.13.2) area_House:
			-Calcula a área da casa;
	2.14) Funções genéricas de retorno:
		2.14.1) ret_nQuarto:
			- Função que retorna o número de quartos de uma casa especifica, para a ordenação do vetor de casas, para o arquivo saida.txt;
}
*/