#include <stdio.h>
#include <string.h>
#include "imobiliaria.h"
#include "saida.h"
int main() {
    tImobiliaria x;
    tSaida saida;
  	FILE* input;
	char rota[150];
	scanf("%s", rota);
    input = fopen(rota, "r");
    read_ImobiliariaInicio(&x, input);
	scanf("%s", rota);
    input = fopen(rota, "r");
    read_ImobiliariaAtual(&x, input);
	scanf("%s", rota);
    input = fopen(rota, "r");
    read_ImobiliariaEspec(&x, input);
    fclose(input);
    printa_Saida(&saida, &x);
    return 0;
}
/* ** GUIA DO PROGRAMA **
1) TAD's utilizados:
	1.1) tImobiliaria (Struct):
		- Struct que serve para armazenar todas as informações dos imóveis, e tambem do arquivo espec.txt, especificando assim a saída;
	1.2) tImovel (Struct):
		- Struct que serve para armazenar a informação do Imóvel, sendo eles área, preço, identificador, nome do proprietário e entre outros aspectos que todos os imoveis tem em comum;
	1.3) tProperty (Union):
		- Union feita para dividir os processos de obtenção de dado entre terreno (Triangular, Retangular e Trapezoidal), casa e Apto ( Casa e Apto fora de uma struct específica por motivo de serem muito diferente uma das outras);
	1.4) tApto (Struct):
		- Struct que serve para armazenar as informaçoes caracteristicas de cada Apartamento;
	1.5) tCasa (Struct):
		- Struct que serve para armazenar as informaçoes caracteristicas de cada Casa;
	1.6) tForma (Union):
		- Union que serve para dividir o processo entre os 3 tipos de forma existentes;
	1.7) tTrap (Struct):
		- Struct que serve para armazenar os dados de terrenos trapezoidais;
	1.8) tRetangle (Struct):
		- Struct que serve para armazenar os dados de terrenos retangulares;
	1.9) tTriangle (Struct):
		- Struct que serve para armazenar os dados de terrenos triangulares;
	1.10) tGround (Struct):
		- Struct que serve para armazenar dados genéricos de casa terreno;
	1.11) tSaida (Struct):
		- Struct dedicada para o output do trabalho. Guarda informações para os print's na saida;
*/
