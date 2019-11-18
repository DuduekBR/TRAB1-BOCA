#include <stdio.h>
#include "apto.h"
// (2.12.2)
float area_Apto(tApto *x) {
    return x->AreaC;
}
// (2.12.1)
float price_Apto(tApto *x) {
    if (x->Lazer == 'S')
        return x->pM2AC * x->AreaC * (0.9 + (float) (x->Andar / x->nAndares))*1.15;
    else
        return x->pM2AC * x->AreaC * (0.9 + (x->Andar / (float) x->nAndares))*1;
}
// (2.12)
void read_Apto(tApto *x, FILE* file, float *area, float *preco) {
    fscanf(file, "%d%d%d", &x->nQuarto, &x->nVagas, &x->Andar);
    fscanf(file, "%f%d%*c%c%d%*c", &x->AreaC, &x->pM2AC, &x->Lazer, &x->nAndares);
    *area = area_Apto(x);
    *preco = price_Apto(x);
}
/*
tApto  (1.4){
	2.12) read_Apto:
		-Lê os dados específicos do imóvel do tipo Apartamento, calcula seu preço e sua área;
		2.12.1) price_Apto:
			- Calcula o preço do apto;
		2.12.2) area_Apto:
			- Calcula a área do apto;
}
*/