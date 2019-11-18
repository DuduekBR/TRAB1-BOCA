#include <stdio.h>
#include "terreno.h"
// (2.23)
void read_Ground(tGround *x, FILE* file) {
    fscanf(file, "%c %d%*c", &x->tag_Solo, &x->p_m2);
}
// (2.24)
float price_calc(tGround *x, float *area) {
    float a = 0.9;
    float b = 1.3;
    float c = 1.1;
    switch (x->tag_Solo) {
        case 'A':
            return (a * x->p_m2**area);
            break;
        case 'G':
            return (b**area * x->p_m2);
            break;
        case 'R':
            return (c**area * x->p_m2);
    }
    return 0;
}
// (2.25)
// (2.25.1)
char ret_tag(tGround *x) {
    return x->tag_Solo;
}
/*
tGround (1.10){
	2.23) read_Ground:
		- Função que lê dados especificos do tipo de imovel terreno, como preço por metro quadrado e seu tipo de solo;
	2.24) price_calc:
		- Calcula o preço de terrenos em geral;
	2.25) Funções genéricas de ponte de dados:]
		2.25.1) ret_tag:
			- Ponte de dados que serve para retorna o tipo do solo do terreno;
}
*/