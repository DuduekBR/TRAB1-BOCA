#include <stdio.h>
#include <string.h>
#include "imovel.h"
#include "propriedade.h"
#define TAM_tag 7
// (2.5.1)
void define_Tag(tImovel *x, char type[TAM_tag], FILE* file) {
    if (strcmp(type, "triang") == 0)
        x->tag = 1;
    if (strcmp(type, "retang") == 0)
        x->tag = 2;
    if (strcmp(type, "trapez") == 0)
        x->tag = 3;
    if (strcmp(type, "casa") == 0)
        x->tag = 4;
    if (strcmp(type, "apto") == 0)
        x->tag = 5;
}
// (2.5)
int read_Imovel(tImovel *x, FILE* file) {
    int i, err;
    char type[TAM_tag];
    fscanf(file, "%s", type);
    define_Tag(x, type, file);
    err = fscanf(file, "%u%*c", &x->ident);
	if(err == -1)
	return 0;
    fscanf(file, "%[^\n]%*c", x->nome);
    data_Property(&x->imovel, &x->tag, &x->area, &x->preco, file);
	return 1;
}
// (2.6)
void read_ImovelAtual(tImovel *x, FILE* file, char type[TAM_tag], int ident) {
    int i;
    define_Tag(x, type, file);
    x->ident = ident;
    fscanf(file, "%[^\n]%*c", x->nome);
    data_Property(&x->imovel, &x->tag, &x->area, &x->preco, file);
}
//(2.7)
//(2.7.1)
int ret_ident(tImovel *x1) {
    return x1->ident;
}
// (2.7.2)
int ret_type(tImovel *x) {
    return x->tag;
}
// (2.7.3)
float ret_area(tImovel *x) {
    return x->area;
}
// (2.7.4)
float ret_preco(tImovel *x) {
    return x->preco;
}
// (2.9)
char type_Terreno(tImovel *x) {
    return ponte_TipoTerreno(&x->imovel, &x->tag);
}
// (2.8)
// (2.8.1)
int cmp_IdentCrescente(tImovel *x1, tImovel *x2) {
    return x1->ident > x2->ident;
}
// (2.8.2)
int cmp_IdentDecrescente(tImovel *x1, tImovel *x2) {
    return x1->ident < x2->ident;
}
// (2.8.3)
int cmp_PrecoCrescente(tImovel *x1, tImovel *x2) {
    if(x1->preco > x2->preco){
			return 1;
		}
		if(x1->preco == x2->preco){
			return cmp_IdentCrescente(x1, x2);
		}
		else{
			return 0;
		}
}
// (2.8.4)
int cmp_AreaDecrescente(tImovel *x1, tImovel *x2) {
    if(x1->area < x2->area)
		return 1;
		if(x1->area == x2->area)
		return cmp_IdentDecrescente(x1,x2);
		else
		return 0;
}
// (2.8.5)
int cmp_nQuartos(tImovel *x1, tImovel *x2) {
    if (x1->tag == 4 && x2->tag == 4) {
        if(ponte_nQuartos(&x1->imovel) < ponte_nQuartos(&x2->imovel))
				return 1;
				if(ponte_nQuartos(&x1->imovel) == ponte_nQuartos(&x2->imovel))
				return cmp_IdentDecrescente(x1,x2);
    }
    return 0;
}
/*
tImovel  (1.2){
	2.5) read_Imovel:
		- Função que lê dados abragentes de cada imovel, como identificador, nome do proprietário, identificador;
		2.5.1) define_Tag:
			- Função que serve para caracterizar cada imovel com um int especifico, dependendo de qual tipo ele é;
	2.6) read_ImovelAtual:
		- Função que lê dados expecificos da operação de alteraração (2.2.2), de forma especial;
	2.7) Funções genéricas de retorno:
		2.7.1) ret_ident:
			- Retorna o identificador do imovel;
		2.7.2) ret_type:
			-Retorna o tipo do imovel em forma de int;
		2.7.3) ret_area:
			-Retorna a área do imovel;
		2.7.4) ret_preco:
			-Retorna o preço do imóvel;
	2.8) Funções genéricas de comparação:
		2.8.1) cmp_IdentCrescente:
			-Compara o identificador, de forma que o se o 1º for maior troca, usada como critério de desempate;
		2.8.2) cmp_IdentDecrescente:
			-Compara o identificador, de forma que o se o 2º for maior troca, usada como critério de desempate;
		2.8.3) cmp_PrecoCrescente:
			-Compara o Preço de dois imoveis diferentes, para o arquivo saida.txt;
		2.8.4) cmp_AreaDecrescente:
			-Compara o Preço de dois imoveis diferentes, para o arquivo saida.txt;
		2.8.5) cmp_nQuartos:
			-Se for uma casa (identificado pelo int caracteristico), ele compara o numero dos quartos deles, de forma decrescente, para o arquivo saida.txt;
}
*/