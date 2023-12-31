#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Registers.h"
#include "Converter.h"

using namespace std;

vector<string> RRL(string linha, unordered_map<string, int> labels, int nLinha) {
	string r1, r2, label;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	r1 = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (r1[0] >= '0' && r1[0] <= '9') {
		r1 = decimalParaBin(stoi(r1), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r1 = registradorParaBin(r1, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	r2 = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (r2[0] >= '0' && r2[0] <= '9') {
		r2 = decimalParaBin(stoi(r2), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r2 = registradorParaBin(r2, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	indiceInicio = linha.find(' '); //encontra indice de ' '
	label = linha.substr(indiceInicio + 1, linha.length());
	string enderecoLabel = decimalParaBin((labels[label] - 1) - nLinha, 16); //converte o endere�o da label para bin�rio 16 bits

	vector<string> registradores = { r1, r2, enderecoLabel }; //retorna em um vector os bin�rios dos registradores e da label
	return registradores;
}

vector<string> RRR(string linha) { //checar
	string r1, r2, r3;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	r1 = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (r1[0] >= '0' && r1[0] <= '9') {
		r1 = decimalParaBin(stoi(r1), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r1 = registradorParaBin(r1, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	r2 = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (r2[0] >= '0' && r2[0] <= '9') {
		r2 = decimalParaBin(stoi(r2), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r2 = registradorParaBin(r2, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	r3 = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (r3[0] >= '0' && r3[0] <= '9') {
		r3 = decimalParaBin(stoi(r3), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r3 = registradorParaBin(r3, 5); //passa o registrador em formato string para o bin�rio
	}

	vector<string> registradores = { r1, r2, r3 }; //retorna em um vector os bin�rios dos registradores
	return registradores;
}

vector<string> RRI(string linha, bool isRfamily) {
	string r1, r2, imediato;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	r1 = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (r1[0] >= '0' && r1[0] <= '9') {
		r1 = decimalParaBin(stoi(r1), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r1 = registradorParaBin(r1, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	r2 = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (r2[0] >= '0' && r2[0] <= '9') {
		r2 = decimalParaBin(stoi(r2), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r2 = registradorParaBin(r2, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	indiceInicio = linha.find(' '); //encontra indice de ' '
	imediato = linha.substr(indiceInicio + 1, linha.length());

	if (isRfamily) imediato = decimalParaBin(stoi(imediato), 5); //passa o imediato em formato decimal para o bin�rio
	else imediato = decimalParaBin(stoi(imediato), 16); //passa o imediato em formato decimal para o bin�rio

	vector<string> registradores = { r1, r2, imediato }; //retorna em um vector os bin�rios dos registradores e do imediato
	return registradores;
}

vector<string> R(string linha) {
	string r;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	r = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (r[0] >= '0' && r[0] <= '9') {
		r = decimalParaBin(stoi(r), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r = registradorParaBin(r, 5); //passa o registrador em formato string para o bin�rio
	}

	vector<string> registradores = { r }; //retorna em um vector o bin�rio do registrador
	return registradores;
}

vector<string> RR(string linha) {
	string r1, r2;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	r1 = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (r1[0] >= '0' && r1[0] <= '9') {
		r1 = decimalParaBin(stoi(r1), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r1 = registradorParaBin(r1, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	indiceInicio = linha.find('$'); //encontra indice de '$'
	indiceFim = linha.find(','); //encontra indice de ','
	r2 = linha.substr(indiceInicio + 1, indiceFim - 2);
	if (r2[0] >= '0' && r2[0] <= '9') {
		r2 = decimalParaBin(stoi(r2), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r2 = registradorParaBin(r2, 5); //passa o registrador em formato string para o bin�rio
	}

	vector<string> registradores = { r1, r2 }; //retorna em um vector os bin�rios dos registradores
	return registradores;
}

vector<string> RI(string linha) {
	string r, imediato;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	r = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (r[0] >= '0' && r[0] <= '9') {
		r = decimalParaBin(stoi(r), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r = registradorParaBin(r, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	indiceInicio = linha.find(' '); //encontra indice de ' '
	imediato = linha.substr(indiceInicio + 1, linha.length());
	imediato = decimalParaBin(stoi(imediato), 16); //passa o imediato em formato decimal para o bin�rio

	vector<string> registradores = { r, imediato }; //retorna em um vector os bin�rios dos registradores e do imediato
	return registradores;
}

vector<string> I(string linha) {
	vector<string> registradores = { decimalParaBin(stoi(linha), 26) }; //retorna em um vector o bin�rio do imediato
	return registradores;
}

vector<string> RMI(string linha) { //servir� para lw e sw
	string r1, r2, multiplier;

	size_t indiceInicio = linha.find('$'); //encontra indice de '$'
	size_t indiceFim = linha.find(','); //encontra indice de ','
	r1 = linha.substr(indiceInicio + 1, indiceFim - 1);
	if (r1[0] >= '0' && r1[0] <= '9') {
		r1 = decimalParaBin(stoi(r1), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r1 = registradorParaBin(r1, 5); //passa o registrador em formato string para o bin�rio
	}

	linha = linha.substr(indiceFim + 1, linha.length()); //apaga o que j� foi usado

	//Apagar todos os espa�os da string
	linha.erase(remove(linha.begin(), linha.end(), ' '), linha.end());
	
	indiceFim = linha.find('(');
	multiplier = linha.substr(0, indiceFim);

	multiplier = decimalParaBin(stoi(multiplier), 16); //passa o multiplier em formato decimal para o bin�rio

	size_t inicioMultiplier = linha.find('(') + 1; //encontra indice de '('
	size_t fimMultiplier = linha.find(')'); //encontra indice de ')'
	r2 = linha.substr(inicioMultiplier, fimMultiplier - inicioMultiplier); //pega o registrador nos parenteses
	r2 = r2.erase(0, 1); //apaga o '$'
	if (r2[0] >= '0' && r2[0] <= '9') {
		r2 = decimalParaBin(stoi(r2), 5); //passa o registrador em formato decimal para o bin�rio
	}
	else {
		r2 = registradorParaBin(r2, 5); //passa o registrador em formato string para o bin�rio
	}

	vector<string> registradores = { r1, r2, multiplier }; //retorna em um vector os bin�rios dos registradores e do imediato
	return registradores;
}

vector<string> L(string linha, unordered_map<string, int> labels, int nLinha) {
	string label;
	
	label = linha.substr(0, linha.length()); //pega a label

	//precisamos de pegar em bin�rio ambos e fazer um OR (com strings n funciona)
	string enderecoLabel = decimalParaBin(labels[label] - 1, 26); //converte o endere�o da label para bin�rio 16 bits
	enderecoLabel[5] = '1'; //coloca o bit do come�o do programa como 4 milh�es

	vector<string> registradores = { enderecoLabel }; //retorna em um vector os bin�rios dos registradores e da label
	return registradores;
}