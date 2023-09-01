#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Instructions.h"
#include "Registers.h"
#include "Converter.h"

using namespace std;

//todo
//adicionar as instruções restantes

string sll(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	vector<string> dados = RRI(linhaAtual, true);
	string resultado = opcode + dados[1] + decimalParaBin(0, 5) + dados[0] + dados[2] + decimalParaBin(0, 6);
	return resultado;
}

string srl(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	vector<string> dados = RRI(linhaAtual, true);
	string resultado = opcode + dados[1] + decimalParaBin(0, 5) + dados[0] + dados[2] + decimalParaBin(2, 6);
	return resultado;
}



string beq(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin(4, 6);
	vector<string> dados = RRL(linha, labels, nLinha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string bne(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin(5, 6);
	vector<string> dados = RRL(linha, labels, nLinha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string addi(string linha) {
	string opcode = decimalParaBin(8, 6);
	vector<string> dados = RRI(linha, false);
	string resultado = opcode + dados[1] + dados[0] + dados[2];
	return resultado;
}

string addiu(string linha) {
	string opcode = decimalParaBin(9, 6);
	vector<string> dados = RRI(linha, false);
	string resultado = opcode + dados[1] + dados[0] + dados[2];
	return resultado;
}

string slti(string linha) {
	string opcode = decimalParaBin(10, 6);
	vector<string> dados = RRI(linha, false);
	string resultado = opcode + dados[1] + dados[0] + dados[2];
	return resultado;
}

string sltiu(string linha) {
	string opcode = decimalParaBin(11, 6);
	vector<string> dados = RRI(linha, false);
	string resultado = opcode + dados[1] + dados[0] + dados[2];
	return resultado;
}

string andi(string linha) {
	string opcode = decimalParaBin(12, 6);
	vector<string> dados = RRI(linha, false);
	string resultado = opcode + dados[1] + dados[0] + dados[2];
	return resultado;
}

string ori(string linha) {
	string opcode = decimalParaBin(13, 6);
	vector<string> dados = RRI(linha, false);
	string resultado = opcode + dados[1] + dados[0] + dados[2];
	return resultado;
}

string lui(string linha) {
	string opcode = decimalParaBin(15, 6);
	vector<string> dados = RI(linha);
	string resultado = opcode + decimalParaBin(0, 5) + dados[0] + dados[1];
	return resultado;
}

string lw(string linha) {
	string opcode = decimalParaBin(35, 6);
	vector<string> dados = RMI(linha);
	string resultado = opcode + dados[1] + dados[0] + dados[2];
	return resultado;
}

string sw(string linha) {
	string opcode = decimalParaBin(43, 6);
	vector<string> dados = RMI(linha);
	string resultado = opcode + dados[1] + dados[0] + dados[2];
	return resultado;
}

string j(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin(2, 6); const string comecoDoProgama = decimalParaBin(1, 6);
	vector<string> dados = L(linha, labels, nLinha);
	string resultado = opcode + comecoDoProgama + dados[0];
	return resultado;
}

string jal(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin(3, 6);
	vector<string> dados = L(linha, labels, nLinha);
	string resultado = opcode + decimalParaBin(1, 6) + dados[0];
	return resultado;
}