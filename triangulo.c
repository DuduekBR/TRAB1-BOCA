#include <stdio.h>
#include "terreno.h"
#include "triangulo.h"
// (2.21.2)
float area_Triangle(tTriangle *x) {
    return (x->base * x->altura) / (float) 2;
}
// (2.21.1)
float price_Triangle(tTriangle *x, float *area) {
    return price_calc(&x->ter, area);
}
// (2.21)
void read_triangle(tTriangle *x, float *area, float*preco, FILE* file) {
    read_Ground(&x->ter, file);
    fscanf(file, "%f%f%*c", &x->base, &x->altura);
    *area = area_Triangle(x);
    *preco = price_Triangle(x, area);
}
//(2.22)
//(2.22.1)
char ponte_tagT(tTriangle *x) {
    return ret_tag(&x->ter);
}
/*
tTriangle (1.9){
	2.21) read_triangle:
		- Lê os dados especificos de cada triangulo, calcula seu preço e sua área;
		2.21.1) price_Triangle:
			- Calcula o preço do triangulo;
		2.21.2) area_Triangle:
			- Calcula a área do triangulo;
	2.22) Funções genéricas de ponte de dados:
		2.22.1) ponte_tagT:
			- Ponte de dados que serve para retornar o tipo de solo que o terreno triangular apresenta;
}
*/