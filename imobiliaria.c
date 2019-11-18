#include <stdio.h>
#include "imobiliaria.h"
#define TAM_tag 7
// (2.2.2)
void altera(tImobiliaria *x, int *p, int ident) {
    int i;
    int acont = 0;
    for (i = 0; i < x->qnt_Houses; i++) {
        if (ret_ident(&x->house[i]) == ident) {
            *p = i;
            acont++;
            break;
        }
    }
}
// (2.2.3)
void exclui(tImobiliaria *x, int ident) {
    int i, j;
    for (i = 0; i < x->qnt_Houses; i++) {
        if (ret_ident(&x->house[i]) == ident) {
            for (j = i; j < x->qnt_Houses - 1; j++) {
                x->house[j] = x->house[j + 1];
            }
            break;
        }
    }
}
// (2.4)
void org_Imobiliaria(tImobiliaria *x, int f(tImovel*, tImovel*)) {
    int i, n;
    tImovel aux;
    for (i = 0; i < x->qnt_Houses; i++) {
        for (n = i + 1; n < x->qnt_Houses; n++) {
            if (f(&x->house[i], &x->house[n])) {
                aux = x->house[i];
                x->house[i] = x->house[n];
                x->house[n] = aux;
            }
        }
    }
}
// (2.1)
void read_ImobiliariaInicio(tImobiliaria *x, FILE* file) {
    int i, cont;
    int fim_do_arquivo = feof(file);
    for (i = 0; i < 300; i++){
        fim_do_arquivo = feof(file);
        if(fim_do_arquivo != 0)
        break;
        cont = read_Imovel(&x->house[i], file);
        if(cont == 0)
        break;
        fscanf(file, "%*c");
    }
    x->qnt_Houses = i;
}
// (2.2)
void read_ImobiliariaAtual(tImobiliaria *x, FILE* file) {
    int i, p = 0, ident;
    char c, type[TAM_tag];
    int fim_do_arquivo = feof(file);
    for (i = 0; i < 300 && fim_do_arquivo == 0; i++, fim_do_arquivo = feof(file)) {
        if(fim_do_arquivo != 0)
        break;
        fscanf(file, "%c", &c);
        if (c == 'i') { // (2.2.1)
            read_Imovel(&x->house[x->qnt_Houses], file);
            x->qnt_Houses++;
        }
        if (c == 'a'){
            fscanf(file, "%*c%[^\n]", type);
            fscanf(file, "%d%*c", &ident);
            altera(x, &p, ident);
            read_ImovelAtual(&x->house[p], file, type, ident);
        }
        if (c == 'e') {
            fscanf(file, "%d%*c", &ident);
            exclui(x, ident);
            x->qnt_Houses--;
        }
        fscanf(file, "%*c");
    }
}
// (2.3)
int read_ImobiliariaEspec(tImobiliaria *x, FILE* file) {
    int porcento=0;
	int fim_do_arquivo = feof(file);
    if(fim_do_arquivo != 0)
    return 0;
    fscanf(file, "%d", &porcento);
    x->percent_caro = (float) porcento / 100;
    fscanf(file, "%d", &porcento);
    x->percent_Argila = (float) porcento / 100;
    fscanf(file, "%f", &x->area_lim);
    fscanf(file, "%f", &x->preco_lim);
    fscanf(file, "%d\n%d\n%d", &x->i, &x->j, &x->k);
	return 0;
}

/*tImobiliaria (1.1){
	2.1) read_ImobiliariaInicio:
		- Função que serve para a leitura do arquivo catalogo.txt, que por consequencia, faz operações de leitura ( com o scanf ), de atribuição ( que serve para trocar a string do tipo de imóvel por um int característico, ocupando assim menos memória ), e passando para a próxima função de leitura que lê características expecificas de cada tipo [data_Property];
	2.2) read_ImobiliariaAtual:
		- Função que lê um char que indica qual operação do arquivo atual.txt será utilizada, e dependendo do char que ele verificar, fara operações como:
			2.2.1) Inclusão:
				- Ele irá ler com a função [read_Imovel], novamente os dados, só que na posição final do vetor e adicionando 1 de tamanho a ele;
			2.2.2) Alterar:
				- Ele irá passar o identificador lido remotamente na função [read_ImobiliariaAtual], para verificar se existe algum outro identificador igual ao dele, se tiver, ele passa por um ponteiro a posição da memória dele, e é feito uma leitura dos dados com a função [read_ImovelAtual];
				2.2.3) Exclui:
				- Ele irá sobrescrever o espaço do vetor cujo o identificador é expecificado no arquivo, pelo espaço posterior a ele;
	2.3) read_ImobiliariaEspec:
		- Função que lê os dados do arquivo espec.txt e armazena-os na própria struct tImobiliaria (1.1);
	2.4) org_Imobiliaria:
		-Função que organiza os dados do vetor de casas da Imobiliaria, de acordo com a função auxiliar que for passada como parâmetro;
}*/