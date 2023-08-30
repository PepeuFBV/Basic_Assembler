#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Registers.h"
#include "Converter.h"

using namespace std;

vector<string> RRL(string linha, unordered_map<string, int> labels, int nLinha, int tam) {
	string rs, rt;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	rs = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (rs[0] >= '0' && rs[0] <= '9') {
		rs = decimalParaBin(stoi(rs),tam); //passa o registrador em formato decimal para o binário
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
	string enderecoLabel = decimalParaBin((labels[label] - 1) - nLinha, 16); //converte o endereço da label para binário 16 bits

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

vector<string> RRI(string linha) {
	string rs, rt, imediato;

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

	indiceInicio = linha.find(' '); //encontra indice de ' '
	imediato = linha.substr(indiceInicio + 1, linha.length());
	imediato = decimalParaBin(stoi(imediato)); //passa o imediato em formato decimal para o binário
	vector<string> registradores = { rs, rt, imediato }; //retorna em um vector os binários dos registradores e do imediato
	return registradores;
}

vector<string> R(string linha) {
	string rd;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	rd = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (rd[0] >= '0' && rd[0] <= '9') {
		rd = decimalParaBin(stoi(rd)); //passa o registrador em formato decimal para o binário
	}
	else {
		rd = registradorParaBin(rd); //passa o registrador em formato string para o binário
	}

	vector<string> registradores = { rd }; //retorna em um vector o binário do registrador
	return registradores;
}

vector<string> RR(string linha) {
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

	vector<string> registradores = { rs, rt }; //retorna em um vector os binários dos registradores
	return registradores;
}

vector<string> RI(string linha) {
	string rt, imediato;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	rt = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (rt[0] >= '0' && rt[0] <= '9') {
		rt = decimalParaBin(stoi(rt)); //passa o registrador em formato decimal para o binário
	}
	else {
		rt = registradorParaBin(rt); //passa o registrador em formato string para o binário
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que já foi usado

	indiceInicio = linha.find(' '); //encontra indice de ' '
	imediato = linha.substr(indiceInicio + 1, linha.length());
	imediato = decimalParaBin(stoi(imediato)); //passa o imediato em formato decimal para o binário

	vector<string> registradores = { rt, imediato }; //retorna em um vector os binários dos registradores e do imediato
	return registradores;
}

vector<string> I(string linha) {
	vector<string> registradores = { decimalParaBin(stoi(linha)) }; //retorna em um vector o binário do imediato
	return registradores;
}

vector<string> RMI(string linha) { //servirá para lw e sw
	string rt, multiplier, rs;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	rt = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (rt[0] >= '0' && rt[0] <= '9') {
		rt = decimalParaBin(stoi(rt)); //passa o registrador em formato decimal para o binário
	}
	else {
		rt = registradorParaBin(rt); //passa o registrador em formato string para o binário
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que já foi usado

	multiplier = linha[0]; //pega o multiplier

	linha = linha.substr(1, linha.length()); //apaga o que já foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	rs = linha.substr(indiceInicio + 1, linha.length()-1); //pega o registrador até o fim da string - 1 ( o ')' ) é removido
	if (rs[0] >= '0' && rs[0] <= '9') {
		rs = decimalParaBin(stoi(rs)); //passa o registrador em formato decimal para o binário
	}
	else {
		rs = registradorParaBin(rs); //passa o registrador em formato string para o binário
	}

	vector<string> registradores = { rt, rs, multiplier }; //retorna em um vector os binários dos registradores e do imediato
	return registradores;
}