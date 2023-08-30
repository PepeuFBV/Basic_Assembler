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