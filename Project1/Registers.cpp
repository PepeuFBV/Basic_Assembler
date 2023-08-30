#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Registers.h"
#include "Converter.h"

using namespace std;

vector<string> RRL(string linha, unordered_map<string, int> labels, int nLinha) {
	string rs, rt;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	rs = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (rs[0] >= '0' && rs[0] <= '9') {
		rs = decimalParaBin(stoi(rs)); //passa o registrador em formato decimal para o binário
	}
	else {
		rs = registradorParaBin(rs); //passa o registrador em formato string para o binário
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que já foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	rt = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (rt[0] >= '0' && rt[0] <= '9') {
		rt = decimalParaBin(stoi(rt)); //passa o registrador em formato decimal para o binário
	}
	else {
		rt = registradorParaBin(rt); //passa o registrador em formato string para o binário
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que já foi usado

	indiceInicio = linha.find(' '); //encontra indice de ' '
	string label = linha.substr(indiceInicio + 1, linha.length());
	string enderecoLabel = decimalParaBin((labels[label] - 1) - nLinha); //converte o endereço da label para binário

	vector<string> registradores = { rs, rt, enderecoLabel }; //retorna em um vector os binários dos registradores e da label
	return registradores;
}

vector<string> RRR(string linha) { //checar
	string rs, rt, rd;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	rs = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (rs[0] >= '0' && rs[0] <= '9') {
		rs = decimalParaBin(stoi(rs)); //passa o registrador em formato decimal para o binário
	}
	else {
		rs = registradorParaBin(rs); //passa o registrador em formato string para o binário
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que já foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	rt = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (rt[0] >= '0' && rt[0] <= '9') {
		rt = decimalParaBin(stoi(rs)); //passa o registrador em formato decimal para o binário
	}
	else {
		rt = registradorParaBin(rt); //passa o registrador em formato string para o binário
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que já foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	rd = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (rd[0] >= '0' && rd[0] <= '9') {
		rd = decimalParaBin(stoi(rs)); //passa o registrador em formato decimal para o binário
	}
	else {
		rd = registradorParaBin(rt); //passa o registrador em formato string para o binário
	}

	vector<string> registradores = { rs, rt, rd }; //retorna em um vector os binários dos registradores
	return registradores;
}