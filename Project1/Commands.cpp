#include <iostream>
#include <string>
#include <unordered_map>
#include "Instructions.h"
#include "Commands.h"

using namespace std;

string comandoAtual(string linhaSemComando, string comando, unordered_map<string, int> labels, int nLinha) {
    string binario;
    if (comando.compare("beq") == 0) {
        binario = beq(linhaSemComando, labels, nLinha);
    }
    else if (comando.compare("bne") == 0) {
        binario = bne(linhaSemComando, labels, nLinha);
    }
    else if (comando.compare("addi") == 0) {
        binario = addi(linhaSemComando);
    }
    else if (comando.compare("addiu") == 0) {
        binario = addiu(linhaSemComando);
    }
    else if (comando.compare("slti") == 0) {
        binario = slti(linhaSemComando);
    }
    else if (comando.compare("andi") == 0) {
        binario = andi(linhaSemComando);
    }
    else if (comando.compare("ori") == 0) {
        binario = ori(linhaSemComando);
    }
    else if (comando.compare("lui") == 0) {
        binario = lui(linhaSemComando);
    }
    else if (comando.compare("lw") == 0) {
        binario = lw(linhaSemComando);
    }
    else if (comando.compare("sw") == 0) {
        binario = sw(linhaSemComando);
    }
}