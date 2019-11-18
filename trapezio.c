#include <stdio.h>
#include "terreno.h"
#include "trapezio.h"
// (2.17.2)
float area_Trapez(tTrap *x) {
    return ((x->base1 + x->base2) * x->altura) / (float) 2;
}
// (2.17.1)
float price_Trapezoid(tTrap *x, float *area) {
    return price_calc(&x->ter, area);
}
// (2.17)
void read_trap(tTrap *x, float *area, float*preco, FILE* file) {
    read_Ground(&x->ter, file);
    fscanf(file, "%f %f %f%*c", &x->base1, &x->base2, &x->altura);
    *area = area_Trapez(x);
    *preco = price_Trapezoid(x, area);
}
// (2.18)
// (2.18.1)
char ponte_tagTP(tTrap *x) {
    return ret_tag(&x->ter);
}
/*
tTrap (1.7){
	2.17) read_trap:
		- Lê os dados especificos de cada trapezio, calcula seu preço e sua área;
		2.17.1) price_Trapezoid:
			- Calcula o preço do trapézio;
		2.17.2) area_Trapez:
			- Calcula a área do trapézio;
	2.18) Funções genéricas de ponte de dados:
		2.18.1) ponte_tagTP:
			- Ponte de dados que serve para retornar o tipo de solo que o terreno trapezoidal apresenta;
}
*/