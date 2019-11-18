#include <stdio.h>
#include "imobiliaria.h"
#include "saida.h"
// (*2.26.4)
void org_vetorSaida(int v[TAM_houses], int* qntd, float percent) {
    int i;
    for (i = 0; i<*qntd*percent; i++) {
        v[i] = v[i + *qntd - (int) (*qntd * percent)];
    }
}
//(2.26.3)
void vetor_Casas(tImobiliaria *x, tSaida *j ) {
    int i, a = 1, cont = 1, aux = 0;
    org_Imobiliaria(x, cmp_nQuartos);
    cont = 1;
    for (i = 0, aux = 0; i < x->qnt_Houses; i++) {
        if (a == x->k && cont && ret_area(&x->house[i]) > x->area_lim && ret_preco(&x->house[i]) < x->preco_lim && ret_type(&x->house[i]) == 4) {
            j->soma += ret_ident(&x->house[i]);
            a = 1;
            cont--;
        }
        if (ret_type(&x->house[i]) == 4) {
            if (ret_area(&x->house[i]) > x->area_lim && ret_preco(&x->house[i]) < x->preco_lim){
                j->casas[aux] = ret_ident(&x->house[i]);
                aux++;
                if (cont)
                    a++;
            }

        }
    }
    j->qntd_casas = aux;
}
//(2.26.2)
void vetor_Argila(tImobiliaria *x, tSaida *j ) {
    int i, a = 1, cont = 1, aux = 0;
    org_Imobiliaria(x, cmp_AreaDecrescente);
    for (i = 0, aux = 0; i < x->qnt_Houses; i++) {
        if (type_Terreno(&x->house[i]) == 'G') {
            j->argilosas[aux] = ret_ident(&x->house[i]);
            aux++;
        }
    }
    j->qntd_argilosas = aux;
    org_vetorSaida(j->argilosas, &j->qntd_argilosas, x->percent_Argila);
    j->qntd_argilosas *= x->percent_Argila;
    if(x->j - 1 <= aux && x->j - 1 >= 0)
    j->soma += j->argilosas[x->j - 1];
    else{
        j->soma += 0;
    }
}
// (2.26.1)
void vetor_Caras(tImobiliaria *x, tSaida *j ) {
    int i, a = 1, cont = 1, aux = 0;
    org_Imobiliaria(x, cmp_PrecoCrescente);
    for (i = 0; i < x->qnt_Houses; i++, aux++) {
        j->caras[aux] = ret_ident(&x->house[i]);
    }
    j->qntd_caras = aux;
    org_vetorSaida(j->caras, &j->qntd_caras, x->percent_caro);
    j->qntd_caras *= x->percent_caro;
    if(x->i - 1 <= aux && x->i -1 >= 0)
    j->soma += j->caras[x->i - 1];
    else{
        j->soma +=0;
    }
}
// (2.26)
int vetor_Imobiliaria(tImobiliaria *x, tSaida *j ) {
    int i, a = 1, cont = 1, aux = 0;
    j->soma = 0;
	if(x->qnt_Houses == 0){
		return 0;
	}
    vetor_Caras(x, j);
    vetor_Argila(x, j);
    vetor_Casas(x, j);
	return 0;
}
// (2.27.1)
void type_printSaida(int b, int v[TAM_houses]) {
    int i;
    for (i = 0; i < b; i++) {
        printf("%d",v[i]);
        if (i != b - 1)
            printf(", ");
    }
}
// (2.27)
void printa_Saida(tSaida *x, tImobiliaria*y) {
    int i;
    vetor_Imobiliaria(y, x);
    printf("%d\n", x->soma);
	if(y->qnt_Houses != 0 || y->qnt_Houses > 0){
        if(x->qntd_caras != 0)
    type_printSaida(x->qntd_caras, x->caras );
    printf("\n");
        if(x->qntd_argilosas != 0)
    type_printSaida(x->qntd_argilosas, x->argilosas );
    printf("\n");
        if(x->qntd_casas != 0)
    type_printSaida(x->qntd_casas, x->casas );
    printf("\n");
	}
}
/*
tSaida (1.11){
	2.26) vetor_Imobiliaria:
	- Função que gera vetores com os identificadores para serem printados na saída;
		2.26.1) vetor_Caras:
			- Função que ordena o vetor de imoveis da imobiliaria, de forma a eles ficarem crescente em preço, coloca os determinados identificadores dentro de um vetor auxiliar da struct tSaida, para ser printado na saída (caras);
		2.26.2) vetor_Argila:
			- Função que ordena o vetor de imoveis da imobiliaria, de forma a eles ficarem decrescente em área, e se for um terreno argiloso, coloca o identificador do terreno dentro de um vetor auxiliar da struct tSaida (argilosas);
		2.26.3) vetor_Casas:
			- Função que ordena o vetor de imoveis da imobiliaria, de forma a eles ficarem decrescente em número de quartosa, e se for uma casa, coloca o identificador da casa dentro de um vetor auxiliar da struct tSaida (casas);
		*2.26.4) org_vetorSaida:
			- Função que restringe o vetor a somente a porcentagem definida no arquivo espec.txt, fazendo com que somente a procentagem de casas caras e de terrenos argilosos sejam mostrados. Ela funciona de forma que ela irá sobrescrever o dado que não será utilizado, sendo definido um criterio de parada que é igual ao número de casas ou de terrenos argilosos lidos, e assim sobrescevendo os dados que não serão utilizados, dependendo da porcentagem calculada na função [read_ImobiliariaEspec];
	2.27) printa_Saida:
		-Função que organiza qual a ordem de print dependendo do vetor passado como parametro;
		2.27.1) type_printSaida:
			-Saida formatada;
}
*/
