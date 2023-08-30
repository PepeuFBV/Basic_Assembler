#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "Commands.h"

using namespace std;

int main() {

    string operacao;
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
            linhaAtual = linhaAtual.substr(indice + 2, linhaAtual.length());
        }
        //remove as ocorrencias de '/t'
        linhaAtual.erase(remove(linhaAtual.begin(), linhaAtual.end(), tabulacao), linhaAtual.end());


        size_t pos = linhaAtual.find(' '); // ler a string até o espaço

        indice = linhaAtual.find(' '); //encontra indice de ' '    
        string comando = linhaAtual.substr(0, indice); //obtem apenas o comando da linha atual


        indice = comando.size() + 1; //indice recebe o tamanho do comando + 1 para pular o espaço
        string linhaSemComando = linhaAtual.substr(indice, linhaAtual.length());
        //cria uma nova substring cortando a partir do fim do comando até o final da string completa
  
       

        //comparando o comando atual com os possíveis comandos para chamar respectivas funções
        string binario;
        if (comando.compare("beq") == 0) { 
            binario = beq(linhaSemComando, labels);
        }
        else if (comando.compare("bne") == 0){
            //bne(linhaSemComando, labels);
        }
        else if (comando.compare("addi") == 0) {

        }
        else if (comando.compare("addiu") == 0) {

        }
        else if (comando.compare("slti") == 0) {

        }
        else if (comando.compare("andi") == 0) {

        }
        else if (comando.compare("ori") == 0) {

        }
        else if (comando.compare("lui") == 0) {

        }
        else if (comando.compare("lw") == 0) {

        }
        else if (comando.compare("sw") == 0) {

        }
        
        

    }


    return 0;
}

