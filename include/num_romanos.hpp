#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Trabalho MP conversao numeros romanos para algarismos arabicos - 1/2017
//Victor Araujo Vieira - 14/0032801

//Arquivo header do laboratorio de conversao de numeros romanos
#define ERRO -1

/*Assinatura das funcoes que serao implementadas*/
int ValorDecimalAlgRomano(char romano);
int CriaVetorNumerosArabicos(char const *numRomano, int *vetorNumeroRom);
int ConverteNumeroRomano(char const *numRomano);
