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

//Funcao que valida os numeros I, X e C, que so podem aparecer ate 3 vezes seguidas
//retorna 0 caso seja valido e -1 caso contrario
int ValidaI_X_C(int *vetorNumeroRom, int tamanhoVetor){
	int contaI = 0, contaX = 0, contaC = 0; // contadores para a quantidade de Is, Xs e Cs que tem no numero romano
	int invalidaI = 0, invalidaX = 0, invalidaC = 0; // sao as variaveis que vao invalidar I, X e C
	int i = 0, j = 0;


	for(i = 0; i < tamanhoVetor; i++){
		if(vetorNumeroRom[i] == 1){
			contaI = 1; // contador eh inicializado como 1
			if(i+1 < tamanhoVetor){
				j = i + 1;
				while(vetorNumeroRom[j] == 1 && j < tamanhoVetor){
					contaI++;
					j++;
				}
				if(contaI > 3) invalidaI = 1;
			}
		}

		if(vetorNumeroRom[i] == 10){
			contaX = 1; // contador eh inicializado como 1
			if(i+1 < tamanhoVetor){
				j = i + 1;
				while(vetorNumeroRom[j] == 10 && j < tamanhoVetor){
					contaX++;
					j++;
				}
				if(contaX > 3) invalidaX = 1;
			}
		}

		if(vetorNumeroRom[i] == 1){
			contaC = 1; // contador eh inicializado como 1
			if(i+1 < tamanhoVetor){
				j = i + 1;
				while(vetorNumeroRom[j] == 100 && j < tamanhoVetor){
					contaC++;
					j++;
				}
				if(contaC > 3) invalidaC = 1;
			}
		}
	}

	//se qualquer um dos numeros for invalidado, retorna erro
	if((invalidaI == 1) || (invalidaX == 1) || (invalidaC == 1)){
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

//Funcao que valida subtracoes combinadas, ou seja, casos em que um dado valor eh menor que o proximo
//retorna 0 caso seja valido e -1 caso contrario
int ValidaSubstracoesCombinadas(int *vetorNumeroRom, int tamanhoVetor){
	int num1 = 0, num2 = 0, subtraido = 0;
	int i = 0, contaNumConv = 0;
	int vetorAuxiliar[30]; // vai receber os valores ja convertidos
	float divisaoMenMaior = 0; // variavel que vai receber a divisao do menor numero pelo maior e comparar

	//loop que vai percorrer o vetor e fazer as validacoes
	contaNumConv = 0;
	while(i < tamanhoVetor){
		if(i + 1 < tamanhoVetor){
			num2 = vetorNumeroRom[i + 1];
		}
		num1 = vetorNumeroRom[i];
		if(num1 >= subtraido && subtraido > 0){
			return ERRO; //se o proximo valor for maior ou igual ao ultimo valor subtraido, retorna erro
		}
		if(num1 < num2 && i+1 < tamanhoVetor){
			subtraido = num1;
			vetorAuxiliar[contaNumConv] = num2 - num1;
			divisaoMenMaior = (float)num1/num2;
			if(divisaoMenMaior < 0.1){
				return ERRO; // se a divisao entre o menor numero e o maior for menor que 1/10, significa que eh invalido
			}
			if(subtraido != 1 && subtraido != 10 && subtraido != 100){
				return ERRO; // se o valor que vai ser subtraido for 5, 50 ou 500, retorna erro
			}
			i += 2;	
		}else{
			vetorAuxiliar[contaNumConv] = num1;
			i++;
		}
		contaNumConv++;
	}

	for(i = 1; i < contaNumConv; i++){
		if(vetorAuxiliar[i] > vetorAuxiliar[0]){
			return ERRO; //se qualquer um dos numeros convertidos depois do primeiro for maior que o primeiro, retorna erro!
		}
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
	// se tiver mais de 3 I, X OU C, ja retorna erro, poruqe o numero eh invalido
	// se tiver algum erro relacionado a subtracoes combinadas, retorna erro
	if(ValidaV_L_D(vetorNumeroRom, tamString) == ERRO || ValidaI_X_C(vetorNumeroRom, tamString) == ERRO
	   || ValidaSubstracoesCombinadas(vetorNumeroRom, tamString) == ERRO){
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