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

//Funcao que valida os numeros I, X e C, que so podem aparecer ate 3 vezes
//retorna 0 caso seja valido e -1 caso contrario
int ValidaI_X_C(int *vetorNumeroRom, int tamanhoVetor){
	int contaI = 0, contaX = 0, contaC = 0; // contadores para a quantidade de Is, Xs e Cs que tem no numero romano
	int i = 0;

	//vai percorrer o vetor e realizar as contagens
	for(i = 0; i < tamanhoVetor; i++){
		if(vetorNumeroRom[i] == 1){
			contaI++;
		}
		if(vetorNumeroRom[i] == 10){
			contaX++;
		}
		if(vetorNumeroRom[i] == 100){
			contaC++;
		}
	}

	//se qualquer um dos contadores for maior que 3, quer dizer que houve erro
	if((contaI > 3) || (contaX > 3) || (contaC > 3)){
		return ERRO;
	}

	return 0;
}

//Funcao que valida os numeros V, L e D, que so podem aparecer uma vez
//retorna 0 caso seja valido e -1 caso contrario
int ValidaV_L_D(int *vetorNumeroRom, int tamanhoVetor){
	int contaV = 0, contaL = 0, contaD = 0; //contadores para a quantidade de Vs, Ls e Ds que tem no numero romano
	int i = 0;

	//vai percorrer o vetor e realizar as contagens
	for(i = 0; i < tamanhoVetor; i++){
		if(vetorNumeroRom[i] == 5){
			contaV++;
		}
		if(vetorNumeroRom[i] == 50){
			contaL++;
		}
		if(vetorNumeroRom[i] == 500){
			contaD++;
		}
	}

	//se qualquer um dos contadores for maior que 1, quer dizer que houve um erro
	if((contaV > 1) || (contaL > 1) || (contaD > 1)){
		return ERRO;
	}

	return 0; 
}

//Funcao que vai criar um vetor com os valores numericos individuais dos numeros romanos validos
//Vai retornar 0 caso tenha criado com sucesso e -1 caso tenha ocorrido um erro
int CriaVetorNumerosArabicos(char const *numRomano, int *vetorNumeroRom){
	int i = 0, tamString = strlen(numRomano), numAuxiliar = 0;

	if(tamString > 30) return ERRO; // se o tamanho da string for maior que 30, retorna erro

	//loop que vai inserir os valores individuais convertidos no vetor
	for(i = 0; i < tamString; i++){
		numAuxiliar = ValorDecimalAlgRomano(numRomano[i]);
		if(numAuxiliar == -1){ 
			return ERRO;
		}
		vetorNumeroRom[i] = numAuxiliar;
	}

	return 0; 
}

//Funcao que vai converter, de fato, o numero romano passado para arabico
int ConverteNumeroRomano(char const *numRomano){
	int i = 0, tamString = strlen(numRomano), valorFinal = 0;
	int num1 = 0, num2 = 0; // receberao os numeros individuais convertidos de romano para arabico
	int vetorNumeroRom[30];

	i = 0;
	if(CriaVetorNumerosArabicos(numRomano, vetorNumeroRom) == ERRO){
		return ERRO;
	}
	// se tiver mais de um V, L ou D, ja retorna erro, porque o numero eh invalido
	if(ValidaV_L_D(vetorNumeroRom, tamString) == ERRO){
		return ERRO;
	}
	//a ideia eh percorrer a string, e:
	//1. Pega um numero, se o proximo eh maior, valor final recebe a subtracao do proximo e do atual
	//2. Se nao eh maior, valor final recebe o proprio valor
	while(i < tamString){
		if(i+1 < tamString){
			num2 = vetorNumeroRom[i + 1];
		}
		num1 = vetorNumeroRom[i];
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