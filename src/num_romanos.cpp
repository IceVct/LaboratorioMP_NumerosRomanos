#include "num_romanos.hpp"

//Trabalho MP conversao numeros romanos para algarismos arabicos - 1/2017
//Victor Araujo Vieira - 14/0032801

//Funcao que vai converter o algarismo romano para seu equivalente em arabico
int ValorDecimalAlgRomano(char romano){
	int valorRetorno = 0;

	//I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
	//se nao estiver entre esses, retorna -1, oq indica erro
	switch(romano){
		case 'I': valorRetorno = 1; break;
		case 'V': valorRetorno = 5; break;
		case 'X': valorRetorno = 10; break;
		case 'L': valorRetorno = 50; break;
		case 'C': valorRetorno = 100; break;
		case 'D': valorRetorno = 500; break;
		case 'M': valorRetorno = 1000; break;
		default: valorRetorno = -1;
	}

	return valorRetorno;
}

//Funcao que vai converter, de fato, o numero romano passado para arabico
/*int ConverteNumeroRomano(char *numRomano){


}*/