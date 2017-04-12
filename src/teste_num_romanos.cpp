#include "num_romanos.hpp"
#include "../include/catch.hpp"

TEST_CASE("Numeros romanos para arabicos", "[romanos_arabicos]"){

	SECTION("Testando a funcao que retorna o algarismo arabico correspondente"){
		printf("\nTestando a funcao que retorna o algarismo arabico correspondente");
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
}