#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Instructions.h"
#include "Registers.h"
#include "Converter.h"

using namespace std;

unordered_map<string, ptrFunc> declarandoMaps(void) {

	unordered_map<string, ptrFunc> func;
	
	func["sll"] = sll;
	func["srl"] = srl;
	func["jr"] = jr;
	func["mfhi"] = mfhi;
	func["mflo"] = mflo;
	func["mult"] = mult;
	func["multu"] = multu;
	func["div"] = divF; //plvr reservada
	func["divu"] = divu;
	func["add"] = add;
	func["addu"] = addu;
	func["sub"] = sub;
	func["subu"] = subu;
	func["and"] = andF; //plvr reservada
	func["or"] = orF; //plvr reservada
	func["slt"] = slt;
	func["sltu"] = sltu;
	func["mul"] = mul;

	func["addi"] = addi;
	func["addiu"] = addiu;
	func["slti"] = slti;
	func["sltiu"] = sltiu;
	func["andi"] = andi;
	func["ori"] = ori;
	func["lui"] = lui;
	func["lw"] = lw;
	func["sw"] = sw;

	return func;
}

unordered_map<string, ptrFuncComLabel> declarandoMaps2(void) {

	unordered_map<string, ptrFuncComLabel> funcComLabel;
	
	funcComLabel["beq"] = beq;
	funcComLabel["bne"] = bne;

	funcComLabel["j"] = j;
	funcComLabel["jal"] = jal;

	return funcComLabel;
}

string sll(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(0, 6);
	string rt = decimalParaBin(0, 5);
	vector<string> dados = RRI(linhaAtual, true);
	string resultado = opcode + dados[1] + rt + dados[0] + dados[2] + function;
	return resultado;
}

string srl(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(2, 6);
	string rt = decimalParaBin(0, 5);
	vector<string> dados = RRI(linhaAtual, true);
	string resultado = opcode + dados[1] + rt + dados[0] + dados[2] + function;
	return resultado;
}

string jr(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(8, 6);
	string shamt = decimalParaBin(0, 5);
	string rt = decimalParaBin(0, 5);
	string rd = decimalParaBin(0, 5);
	vector<string> dados = R(linhaAtual);
	string resultado = opcode + dados[0] + rt + rd + shamt + function;
	return resultado;
}

string mfhi(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(16, 6);
	string shamt = decimalParaBin(0, 5);
	string rs = decimalParaBin(0, 5);
	string rt = decimalParaBin(0, 5);
	vector<string> dados = R(linhaAtual);
	string resultado = opcode + rs + rt + dados[0] + shamt + function;
	return resultado;
}

string mflo(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(18, 6);
	string shamt = decimalParaBin(0, 5);
	string rs = decimalParaBin(0, 5);
	string rt = decimalParaBin(0, 5);
	vector<string> dados = R(linhaAtual);
	string resultado = opcode + rs + rt + dados[0] + shamt + function;
	return resultado;
}

string mult(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(24, 6);
	string shamt = decimalParaBin(0, 5);
	string rd = decimalParaBin(0, 5);
	vector<string> dados = RR(linhaAtual);
	string resultado = opcode + dados[0] + dados[1] + rd + shamt + function;
	return resultado;
}

string multu(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(25, 6);
	string shamt = decimalParaBin(0, 5);
	string rd = decimalParaBin(0, 5);
	vector<string> dados = RR(linhaAtual);
	string resultado = opcode + dados[0] + dados[1] + rd + shamt + function;
	return resultado;
}

string divF(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(26, 6);
	string shamt = decimalParaBin(0, 5);
	string rd = decimalParaBin(0, 5);
	vector<string> dados = RR(linhaAtual);
	string resultado = opcode + dados[0] + dados[1] + rd + shamt + function;
	return resultado;
}

string divu(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(27, 6);
	string shamt = decimalParaBin(0, 5);
	string rd = decimalParaBin(0, 5);
	vector<string> dados = RR(linhaAtual);
	string resultado = opcode + dados[0] + dados[1] + rd + shamt + function;
	return resultado;
}

string add(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(32, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;
	return resultado;
}

string addu(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(33, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;

	return resultado;
}

string sub(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(34, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;

	return resultado;
}

string subu(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(35, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;
	return resultado;
}

string andF(string linhaAtual) { // não tenho certeza se é "andf" no seu
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(36, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;
	return resultado;
}

string orF(string linhaAtual) { // não tenho certeza se é "orf" no seu
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(37, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;
	return resultado;
}

string slt(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(42, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;
	return resultado;
}

string sltu(string linhaAtual) {
	string opcode = decimalParaBin(0, 6);
	string function = decimalParaBin(43, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;
	return resultado;
}

string mul(string linhaAtual) {
	string opcode = decimalParaBin(28, 6);
	string function = decimalParaBin(2, 6);
	string shamt = decimalParaBin(0, 5);
	vector<string> dados = RRR(linhaAtual);
	string resultado = opcode + dados[1] + dados[2] + dados[0] + shamt + function;
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
	string opcode = decimalParaBin(2, 6);
	vector<string> dados = L(linha, labels, nLinha);
	string resultado = opcode + dados[0];
	return resultado;
}

string jal(string linha, unordered_map<string, int> labels, int nLinha) {
	string opcode = decimalParaBin(3, 6);
	vector<string> dados = L(linha, labels, nLinha);
	string resultado = opcode + dados[0];
	return resultado;
}