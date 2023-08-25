#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

int main() {

    ifstream file("entrada.asm");
    if (!file.is_open() && !file.bad()) {
        cerr << "Arquivo não pode ser aberto\n"; //exibe a mensagem de erro
        return 1;
    }

    string linhaAtual;
    unordered_map<string, int> labels; //map que guarda os labels e suas linhas
    int nLinha = 0;

    while (getline(file, linhaAtual)) { //loop que lê de linha em linha
        nLinha++;

        size_t indice = linhaAtual.find(':'); //encontra indice de ':'
        if (indice != string::npos) { //verifica se ':' foi encontrado, se não, apenas seguir lendo as linhas
            string label = linhaAtual.substr(0, indice); //cria uma nova substring cortando a partir do início até o índice - 1
            labels[label] = nLinha; //salva no map com o label e linha (virará endereço) do comando
        }

    }
    for (auto x : labels) {
        cout << x.first << " " <<
            x.second << endl;
    }

    file.close(); //le o arquivo pela primeira vez pegando os labels


    file.open("entrada.asm"); //abre o arquivo pela segunda vez para ai realmente transformar em binário
    if (!file.is_open() && !file.bad()) {
        cerr << "Arquivo não pode ser aberto\n"; //exibe a mensagem de erro
        return 1;
    }

    char tabulacao = '\t';
    while (getline(file, linhaAtual)) { //loop que lê de linha em linha

        size_t indice = linhaAtual.find(':'); //encontra indice de ':'
        if (indice != string::npos) { //verifica se ':' foi encontrado, se não, apenas seguir lendo as linhas
            //cria uma nova substring cortando a partir do fim do label até o final da string completa
            linhaAtual = linhaAtual.substr(indice+2, linhaAtual.length());
        }
        //remove as ocorrencias de '/t'
        linhaAtual.erase(remove(linhaAtual.begin(), linhaAtual.end(), tabulacao), linhaAtual.end());

        //montandoBinario(linhaAtual, labels); //coloca o binário no outro arquivo
       // montandoHexadecimal(); //coloca o hexadecimal no outro arquivo, a patir do arquivo binário criado

    }

    return 0;
}