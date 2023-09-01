#include <iostream>
#include <string>
#include <unordered_map>
#include "Instructions.h"
#include "Commands.h"
#include "FunctionMaps.h"

using namespace std;

string comandoAtual(string linhaSemComando, string comando, unordered_map<string, int> labels, int nLinha) {
    string binario; bool usesLabel;

    if (comando.compare("beq") || comando.compare("bne") || comando.compare("j") || comando.compare("jal")) usesLabel = true;
	else usesLabel = false;

    if (!usesLabel) binario = func[comando](linhaSemComando);
    else binario = funcComLabel[comando](linhaSemComando, labels, nLinha);

    return binario;
}