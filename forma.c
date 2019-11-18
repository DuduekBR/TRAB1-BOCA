#include <stdio.h>
#include "retangulo.h"
#include "trapezio.h"
#include "triangulo.h"
#include "forma.h"
// (2.15)
void read_Forma(tForma *x, int *tag, float *area, float*preco, FILE* file) {
    float price;
    switch (*tag) {
        case 1:
            read_triangle(&x->t, area, preco, file);
            break;
        case 2:
            read_retangle(&x->r, area, preco, file);
            break;
        case 3:
            read_trap(&x->tp, area, preco, file);
    }
}
// (2.16)
// (2.16.1)
char ponte_Formatag(tForma *x, int *tag) {
    switch (*tag) {
        case 1:
            return ponte_tagT(&x->t);
            break;
        case 2:
            return ponte_tagR(&x->r);
            break;
        case 3:
            return ponte_tagTP(&x->tp);
    }
    return 0;
}
/*
tForma  (1.6){
	2.15) read_Forma:
		- Lê o int caracteristico de cada terreno, e distribui a leitura de dados especificios de cada terreno;
	2.16) Funções genéricas de ponte de dados:
		2.16.1) ponte_Formatag:
			- Ponte de dados, que retorna o tipo de solo que o terreno apresenta, usada para verificar se é um terreno argiloso no arquivo saida.txt;
}
*/