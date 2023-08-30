#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "Commands.h"

using namespace std;


//TODO
//possibilidade de corre��o para linhasSemLabel n�o terminarem em \n


int main() {

    string operacao;
    ifstream file("entrada.asm");
    if (!file.is_open() && !file.bad()) {
        cerr << "Arquivo n�o pode ser aberto\n"; //exibe a mensagem de erro
        return 1;
    }

    string linhaAtual;
    unordered_map<string, int> labels; //map que guarda os labels e suas linhas
    int nLinha = 0;

    while (getline(file, linhaAtual)) { //loop que l� de linha em linha
        nLinha++;

        size_t indice = linhaAtual.find(':'); //encontra indice de ':'
        if (indice != string::npos) { //verifica se ':' foi encontrado, se n�o, apenas seguir lendo as linhas
            string label = linhaAtual.substr(0, indice); //cria uma nova substring cortando a partir do in�cio at� o �ndice - 1
            labels[label] = nLinha; //salva no map com o label e linha (virar� endere�o) do comando
        }

    }

    file.close(); //le o arquivo pela primeira vez pegando os labels

    //criando o arquivo bin�rio
    cout << "Qual o nome do seu projeto?";
    string nomeProjeto;
    cin >> nomeProjeto;
    ofstream bin(nomeProjeto + ".bin"); //cria um arquivo bin�rio com o nome do projeto
    ofstream hex(nomeProjeto + ".hex"); //cria um arquivo hexadecimal com o nome do projeto


    file.open("entrada.asm"); //abre o arquivo pela segunda vez para ai realmente transformar em bin�rio
    if (!file.is_open() && !file.bad()) {
        cerr << "Arquivo n�o pode ser aberto\n"; //exibe a mensagem de erro
        return 1;
    }

    char tabulacao = '\t'; nLinha = 0;
    while (getline(file, linhaAtual)) { //loop que l� de linha em linha

        size_t indice = linhaAtual.find(':'); //encontra indice de ':'
        if (indice != string::npos) { //verifica se ':' foi encontrado, se n�o, apenas seguir lendo as linhas
            //cria uma nova substring cortando a partir do fim do label at� o final da string completa
            linhaAtual = linhaAtual.substr(indice + 2, linhaAtual.length());
        }
        //remove as ocorrencias de '/t'
        linhaAtual.erase(remove(linhaAtual.begin(), linhaAtual.end(), tabulacao), linhaAtual.end());


        indice = linhaAtual.find(' '); //encontra indice de ' '    
        string comando = linhaAtual.substr(0, indice); //obtem apenas o comando da linha atual


        indice = comando.size() + 1; //indice recebe o tamanho do comando + 1 para pular o espa�o
        string linhaSemComando = linhaAtual.substr(indice, linhaAtual.length());
        //cria uma nova substring cortando a partir do fim do comando at� o final da string completa
  

        //comparando o comando atual com os poss�veis comandos para chamar respectivas fun��es
        string binario;
        if (comando.compare("beq") == 0) { 
            binario = beq(linhaSemComando, labels, nLinha);
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
        
        bin << binario << '\n'; //escreve no arquivo bin�rio e pula uma linha
        hex << hexadecimal << '\n'; //escreve no arquivo hexadecimal e pula uma linha

        
        nLinha++;
    }

    file.close(); //fecha o arquivo de entrada
    bin.close(); //fecha o arquivo bin�rio
    hex.close(); //fecha o arquivo hexadecimal

    return 0;
}