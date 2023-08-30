#include <iostream>
#include <string>
#include <unordered_map>
#include "Commands.h"
#include "Converter.h"

using namespace std;

string beq(string linha, unordered_map<string, int> labels) {
	string const opcode = "000100";
	string rs, rt, label;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	
	rs = linha.substr(indiceInicio+1,indiceFim-1);
	if (int(rs[0]) >= 48 && int(rs[0]) <= 57) { //se o primeiro caractere for um número
		rs = decimalParaBin(stoi(rs));
	}
	else {
		rs = registradorParaBin(rs);
	}


	linha = linha.substr(indiceFim+1,linha.length()); //apaga o que já foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	rt = linha.substr(indiceInicio+1,indiceFim-2);
	if (int(rs[0]) <= 48 && int(rs[0]) >= 57) { //se o primeiro caractere não for um número
		rt = registradorParaBin(rs);
	}
	else {
		rt = decimalParaBin(stoi(rs));
	}

	linha = linha.substr(indiceFim+1,linha.length()); //apaga o que já foi usado

	indiceInicio = linha.find(' '); //encontra indice de ' '
	label = linha.substr(indiceInicio+1,linha.length());
	string enderecoLabel = decimalParaBin(labels[label]); //passa para decimal a linha do label encontrado
	cout << enderecoLabel << endl; //parei aqui, consertar endereco label para binário !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	linha = opcode + rs + rt + enderecoLabel;
	return linha;
}