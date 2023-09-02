#include <iostream>
#include <string>
#include <unordered_map>
#include "Instructions.h"
#include "Commands.h"

using namespace std;

string comandoAtual(string linhaSemComando, string comando, unordered_map<string, int> labels, int nLinha) {
    string binario; bool usesLabel;

    //erro está aqui
    if (comando.compare("beq") == 0 || comando.compare("bnq") == 0 || comando.compare("j") == 0 || comando.compare("jal") == 0) {
        usesLabel = true;
    }
    else {
        usesLabel = false;
    }

    unordered_map<string, ptrFunc> func = declarandoMaps();
    unordered_map<string, ptrFuncComLabel> funcComLabel = declarandoMaps2();
    if (!usesLabel) binario = func[comando](linhaSemComando);
    else binario = funcComLabel[comando](linhaSemComando, labels, nLinha);

    return binario;
}