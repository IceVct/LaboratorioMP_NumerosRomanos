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

	//essa secao testa a funcao ConverteNumeroRomano
	// ERRO vale -1
	SECTION("Testando a funcao que retorna a conversao de romano para arabico"){
		REQUIRE(ConverteNumeroRomano("I") == 1);
		REQUIRE(ConverteNumeroRomano("IV") == 4);
		REQUIRE(ConverteNumeroRomano("X") == 10);
		REQUIRE(ConverteNumeroRomano("XIX") == 19);
		REQUIRE(ConverteNumeroRomano("XLIX") == 49);
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
		REQUIRE(ConverteNumeroRomano("MMMI") == ERRO);
	}
}