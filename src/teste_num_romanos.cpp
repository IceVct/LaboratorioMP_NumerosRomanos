#include "num_romanos.hpp"
#include "../include/catch.hpp"

//Test case vai testar as duas funcoes implementadas no programa
TEST_CASE("Numeros romanos para arabicos", "[romanos_arabicos]"){

	//essa secao testa a funcao ValorDecimalAlgRomano
	SECTION("Testando a funcao que retorna o algarismo arabico correspondente"){
		REQUIRE(ValorDecimalAlgRomano('I') == 1);
		REQUIRE(ValorDecimalAlgRomano('V') == 5);
		REQUIRE(ValorDecimalAlgRomano('X') == 10);
		REQUIRE(ValorDecimalAlgRomano('L') == 50);
		REQUIRE(ValorDecimalAlgRomano('C') == 100);
		REQUIRE(ValorDecimalAlgRomano('D') == 500);
		REQUIRE(ValorDecimalAlgRomano('M') == 1000);
		REQUIRE(ValorDecimalAlgRomano('s') == -1);
		REQUIRE(ValorDecimalAlgRomano('-') == -1);
		REQUIRE(ValorDecimalAlgRomano('i') == -1);
	}

	int vetor[30];
	SECTION("Testando a funcao que cria um vetor com os numeros ja convertidos para arabico"){
		REQUIRE(CriaVetorNumerosArabicos("XXX", vetor) == 0);
		REQUIRE(CriaVetorNumerosArabicos("IV", vetor) == 0);
		REQUIRE(CriaVetorNumerosArabicos("zs", vetor) == ERRO);
		REQUIRE(CriaVetorNumerosArabicos("02", vetor) == ERRO);
		REQUIRE(CriaVetorNumerosArabicos("MMMI", vetor) == 0);
		REQUIRE(CriaVetorNumerosArabicos("MCDEA", vetor) == ERRO);
	}

	SECTION("Testando a funcao que valida a quantidade de V, L e D que existem no numero romano"){
		int vetor[] = {10, 5, 1};
		REQUIRE(ValidaV_L_D(vetor, 3) == 0);
		int vetor1[] = {10, 5, 5};
		REQUIRE(ValidaV_L_D(vetor1, 3) == ERRO);
		int vetor2[] = {10, 5, 1, 5};
		REQUIRE(ValidaV_L_D(vetor2, 4) == ERRO);
		int vetor3[] = {5, 50, 50, 5};
		REQUIRE(ValidaV_L_D(vetor3, 4) == ERRO);
		int vetor4[] = {100, 50, 1};
		REQUIRE(ValidaV_L_D(vetor4, 3) == 0);
		int vetor5[] = {100, 500, 500};
		REQUIRE(ValidaV_L_D(vetor5, 3) == ERRO);
	}

	SECTION("Testando a funcao que valida a quantidade de I, X e C que existem no numero romano"){
		int vetor[] = {10, 10, 10};
		REQUIRE(ValidaI_X_C(vetor, 3) == 0);
		int vetor1[] = {1, 1, 1};
		REQUIRE(ValidaI_X_C(vetor1, 3) == 0);
		int vetor2[] = {10, 10, 10, 10};
		REQUIRE(ValidaI_X_C(vetor2, 4) == ERRO);
		int vetor3[] = {1, 1, 1, 1};
		REQUIRE(ValidaI_X_C(vetor3, 4) == ERRO);
		int vetor4[] = {100, 50, 100, 100, 100};
		REQUIRE(ValidaI_X_C(vetor4, 5) == ERRO);
		int vetor5[] = {100, 100, 100};
		REQUIRE(ValidaI_X_C(vetor5, 3) == 0);
	}

	SECTION("Testando a funcao que valida a as subtracoes combinadas"){
		int vetor[] = {1, 9, 10};
		REQUIRE(ValidaSubstracoesCombinadas(vetor, 3) == ERRO);
		int vetor1[] = {1, 1, 1};
		REQUIRE(ValidaSubstracoesCombinadas(vetor1, 3) == 0);
		int vetor2[] = {100, 10, 50, 10};
		REQUIRE(ValidaSubstracoesCombinadas(vetor2, 4) == ERRO);
		int vetor3[] = {100, 1, 50, 100};
		REQUIRE(ValidaSubstracoesCombinadas(vetor3, 4) == ERRO);
		int vetor4[] = {100, 10, 50, 1, 10};
		REQUIRE(ValidaSubstracoesCombinadas(vetor4, 5) == 0);
		int vetor5[] = {10, 100, 1, 10};
		REQUIRE(ValidaSubstracoesCombinadas(vetor5, 4) == 0);
		int vetor6[] = {1, 1, 10};
		REQUIRE(ValidaSubstracoesCombinadas(vetor6, 3) == ERRO);
		int vetor7[] = {5, 10};
		REQUIRE(ValidaSubstracoesCombinadas(vetor7, 2) == ERRO);
		int vetor8[] = {1, 10, 10};
		REQUIRE(ValidaSubstracoesCombinadas(vetor8, 3) == ERRO);
		int vetor9[] = {1000, 1000, 100, 1000, 10, 100, 1, 10};
		REQUIRE(ValidaSubstracoesCombinadas(vetor9, 8) == 0);
	}

	//essa secao testa a funcao ConverteNumeroRomano
	// ERRO vale -1
	SECTION("Testando a funcao que retorna a conversao de romano para arabico"){
		REQUIRE(ConverteNumeroRomano("I") == 1);
		REQUIRE(ConverteNumeroRomano("IV") == 4);	
		REQUIRE(ConverteNumeroRomano("X") == 10);
		REQUIRE(ConverteNumeroRomano("XIX") == 19);
		REQUIRE(ConverteNumeroRomano("CXLIX") == 149);
		REQUIRE(ConverteNumeroRomano("CCCLXXXVIII") == 388);
		REQUIRE(ConverteNumeroRomano("CDLXXIV") == 474);
		REQUIRE(ConverteNumeroRomano("CMVIII") == 908);
		REQUIRE(ConverteNumeroRomano("MCDXXXVIII") == 1438);
		REQUIRE(ConverteNumeroRomano("MDCCCLVII") == 1857);
		REQUIRE(ConverteNumeroRomano("MMCCLXVI") == 2266);
		REQUIRE(ConverteNumeroRomano("MMDCCCXCIX") == 2899);
		REQUIRE(ConverteNumeroRomano("MMCMXCVIII") == 2998);
		REQUIRE(ConverteNumeroRomano("MMM") == 3000);
		REQUIRE(ConverteNumeroRomano("MMvS") == ERRO);
		REQUIRE(ConverteNumeroRomano("IiV") == ERRO);
		REQUIRE(ConverteNumeroRomano("DL2") == ERRO);
		REQUIRE(ConverteNumeroRomano("MMZMx") == ERRO);
		REQUIRE(ConverteNumeroRomano("MMMMM") == ERRO);
		REQUIRE(ConverteNumeroRomano("MDD") == ERRO);
		REQUIRE(ConverteNumeroRomano("VXV") == ERRO);
		REQUIRE(ConverteNumeroRomano("MMMI") == ERRO);
	}
}