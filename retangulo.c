#include <stdio.h>
#include "terreno.h"
#include "retangulo.h"
// (2.19.2)
float area_Retangle(tRetangle *x) {
    return x->l1 * x->l2;
}
//  (2.19.1)
float price_Retangle(tRetangle *x, float *area) {
    return price_calc(&x->ter, area);
}
// (2.19)
void read_retangle(tRetangle *x, float *area, float*preco, FILE* file) {
    read_Ground(&x->ter, file);
    fscanf(file, "%f%f%*c", &x->l1, &x->l2);
    *area = area_Retangle(x);
    *preco = price_Retangle(x, area);
}
// (2.20)
// (2.20.1)
char ponte_tagR(tRetangle *x) {
    return ret_tag(&x->ter);
}
/*
tRetangle (1.8){
	2.19) read_retangle:
		- Lê os dados especificos de cada retângulo, calcula seu preço e sua área;
	2.19.1) price_Retangle:
		- Calcula o preço do retangulo;
	2.19.2) price_Retangle:
		- Calcula a área do retangulo;
	2.20) Funções genéricas de ponte de dados:
		2.20.1) ponte_tagR:
		- Ponte de dados que serve para retornar o tipo de solo que o terreno retangular apresenta;
}
*/