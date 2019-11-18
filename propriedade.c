#include <stdio.h>
#include "forma.h"
#include "casa.h"
#include "apto.h"
typedef union {
    tForma f;
    tCasa c;
    tApto a;
} tProperty;
// (2.10)
void data_Property(tProperty *x, int *tag, float *area, float *preco, FILE* file) {
    if (*tag == 1 || *tag == 2 || *tag == 3) {
        read_Forma(&x->f, tag, area, preco, file);
    }
    if (*tag == 4) {
        read_Casa(&x->c, file, area, preco);
    }
    if (*tag == 5) {
        read_Apto(&x->a, file, area, preco);
    }
}
// (2.11)
// (2.11.1)
char ponte_TipoTerreno(tProperty *x, int *tag) {
    return ponte_Formatag(&x->f, tag);
}
// (2.11.2)
int ponte_nQuartos(tProperty *x) {
    return ret_nQuarto(&x->c);
}
/*
tProperty  (1.3){
	2.9) Funções genéricas de ponte de dados:
		2.9.1) type_Terreno:
			- Ponte de dados, do tipo de solo de cada terreno, para o verificar se é argiloso no arquivo saida.txt;
	2.10) data_Property:
		- Função que serve para dividir a leitura de cada aspecto especifico de imovel, sendo eles escolhidos de acordo com o int caracteristico;
	2.11) Funções genéricas de ponte de dados:
		2.11.1) ponte_TipoTerreno:
			- Ponte de dados, do tipo de solo de cada terreno, para o verificar se é argiloso no arquivo saida.txt;
		2.11.2) ponte_nQuartos:
			- Ponte de dados, da quantidade de quartos de cada casa, para o arquivo saida.txt;
}
*/