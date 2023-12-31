#include <iostream>
#include <string>
#include <map>
#include "Converter.h"

using namespace std;

string decimalParaBin(int numero, int tam) {
	string binario;
	
	if (numero >= 0) {
		while (numero > 0) {
				binario = to_string(numero % 2) + binario; 
				numero /= 2;
		}
		while (binario.length() < tam) {
			binario = "0" + binario;
		}
	}
	else { //n�mero negativo
		numero = numero * -1;
		while (numero > 0) {
			if (numero % 2 == 0) binario = "1" + binario;
			else binario = "0" + binario;
			numero /= 2;
		}
		while (binario.length() < tam) {
			binario = "1" + binario;
		}
	}
	
	return binario;
}

string registradorParaBin(string registrador, int tam) {
	int equivalente;
	if (registrador.compare("zero") == 0) {
		equivalente = 0;
	}
	else if (registrador.compare("at") == 0) {
		equivalente = 1;
	}
	else if (registrador[0] == 'v') {
		if (registrador[1] == '0') {
			equivalente = 2;
		}
		else if (registrador[1] == '1') {
			equivalente = 3;
		}
	}
	else if (registrador[0] == 'a') {
		if (registrador[1] == '0') {
			equivalente = 4;
		}
		else if (registrador[1] == '1') {
			equivalente = 5;
		}
		else if (registrador[1] == '2') {
			equivalente = 6;
		}
		else if (registrador[1] == '3') {
			equivalente = 7;
		}
	}
	else if (registrador[0] == 't') {
		if (registrador[1] == '0') {
			equivalente = 8;
		}
		else if (registrador[1] == '1') {
			equivalente = 9;
		}
		else if (registrador[1] == '2') {
			equivalente = 10;
		}
		else if (registrador[1] == '3') {
			equivalente = 11;
		}
		else if (registrador[1] == '4') {
			equivalente = 12;
		}
		else if (registrador[1] == '5') {
			equivalente = 13;
		}
		else if (registrador[1] == '6') {
			equivalente = 14;
		}
		else if (registrador[1] == '7') {
			equivalente = 15;
		}
		else if (registrador[1] == '8') {
			equivalente = 24;
		}
		else if (registrador[1] == '9') {
			equivalente = 25;
		}
	}
	else if (registrador[0] == 's') {
		if (registrador[1] == '0') {
			equivalente = 16;
		}
		else if (registrador[1] == '1') {
			equivalente = 17;
		}
		else if (registrador[1] == '2') {
			equivalente = 18;
		}
		else if (registrador[1] == '3') {
			equivalente = 19;
		}
		else if (registrador[1] == '4') {
			equivalente = 20;
		}
		else if (registrador[1] == '5') {
			equivalente = 21;
		}
		else if (registrador[1] == '6') {
			equivalente = 22;
		}
		else if (registrador[1] == '7') {
			equivalente = 23;
		}
		else if (registrador[1] == '8') {
			equivalente = 30;
		}
	}
	else if (registrador[0] == 'k') {
		if (registrador[1] == '0') {
			equivalente = 26;
		}
		else if (registrador[1] == '1') {
			equivalente = 27;
		}
	}
	else if (registrador.compare("gp") == 0) {
		equivalente = 28;
	}
	else if (registrador.compare("sp") == 0) {
		equivalente = 29;
	}
	else if (registrador.compare("fp") == 0) {
		equivalente = 30;
	}
	else if (registrador.compare("ra") == 0) {
		equivalente = 31;
	}
	else {
		cerr << "Registrador n�o existe!";
		exit(0);
	}
	return decimalParaBin(equivalente,tam);
}

string binarioParaHexadecimal(string binario) { //tam = 32 caracteres //salvar da esquerda para direita
	string hexadecimal, bin;

	for (int k = 0; k < 31; k += 4) { //separa o binario em grupos de 4 caracteres (de 0-31)
		bin = binario.substr(k, 4);

		map<string, char> hexMap = { //as tradu��es possiveis
		{"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
		{"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
		{"1000", '8'}, {"1001", '9'}, {"1010", 'a'}, {"1011", 'b'},
		{"1100", 'c'}, {"1101", 'd'}, {"1110", 'e'}, {"1111", 'f'}
		};

		char hex = hexMap[bin];

		hexadecimal += hex;
	}

	while (hexadecimal.length() < 8) { //se o hexadecimal n�o tiver 8 caracteres, adiciona 0's no inicio
		hexadecimal.insert(0, "0");
	}

	return hexadecimal;
}