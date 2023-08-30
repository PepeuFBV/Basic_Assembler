#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Commands.h"
#include "Registers.h"
#include "Converter.h"

using namespace std;

string add(string linhaAtual) {
	

	return "000";
} //consertar



string beq(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin(4);
	vector<string> dados = RRL(linha, labels, nLinha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];

	return resultado;
}

string bne(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin(5);
	vector<string> dados = RRL(linha, labels, nLinha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string addi(string linha) {
	string opcode = decimalParaBin(8);
	vector<string> dados = RRI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string addiu(string linha) {
	string opcode = decimalParaBin(9);
	vector<string> dados = RRI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string slti(string linha) {
	string opcode = decimalParaBin(10);
	vector<string> dados = RRI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string sltiu(string linha) {
	string opcode = decimalParaBin(11);
	vector<string> dados = RRI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string andi(string linha) {
	string opcode = decimalParaBin(12);
	vector<string> dados = RRI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string ori(string linha) {
	string opcode = decimalParaBin(13);
	vector<string> dados = RRI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string lui(string linha) {
	string opcode = decimalParaBin(15);
	vector<string> dados = RI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string lw(string linha) {
	string opcode = decimalParaBin(35);
	vector<string> dados = RMI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string sw(string linha) {
	string opcode = decimalParaBin(43);
	vector<string> dados = RMI(linha);
	string resultado = opcode + dados[0] + dados[1] + dados[2];
	return resultado;
}

string j(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin16b(2);
	vector<string> dados = I(linha);
	string resultado = opcode + dados[0] +  + dados[1];
	return resultado;
}

string jal(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin16b(3);
	vector<string> dados = I(linha);
	string resultado = opcode + dados[0];
	return resultado;
}