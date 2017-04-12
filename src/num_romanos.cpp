#include "num_romanos.hpp"

//Trabalho MP conversao numeros romanos para algarismos arabicos - 1/2017
//Victor Araujo Vieira - 14/0032801

//Funcao que vai converter o algarismo romano para seu equivalente em arabico, individualmente
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
		default: valorRetorno = ERRO;
	}

	return valorRetorno;
}

//Funcao que vai converter, de fato, o numero romano passado para arabico
int ConverteNumeroRomano(char const *numRomano){
	int i = 0, tamString = strlen(numRomano), valorFinal = 0;
	int num1 = 0, num2 = 0; // receberao os numeros individuais convertidos de romano para arabico

	if(tamString > 30) return ERRO; // se o tamanho da string for maior que 30, retorna erro

	i = 0;
	//a ideia eh percorrer a string, e:
	//1. Pega um numero, se o proximo eh maior, valor final recebe a subtracao do proximo e do atual
	//2. Se nao eh maior, valor final recebe o proprio valor
	while(i < tamString){
		if(i+1 < tamString){
			num2 = ValorDecimalAlgRomano(numRomano[i + 1]);
		}
		num1 = ValorDecimalAlgRomano(numRomano[i]);
		if(num2 == -1 || num1 == -1){
			return ERRO; // se qualquer um dos numeros for invalido, retorna -1
		}
		if(num1 < num2 && i+1 < tamString){
			valorFinal += num2 - num1;
			i += 2;
		}else{
			valorFinal += num1;
			i++;
		}
	}
	if(valorFinal > 3000) return ERRO; // se o valor final for maior que 3000, retorna erro

	return valorFinal;
}