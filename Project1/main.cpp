#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "Commands.h"
#include "Converter.h"

using namespace std;

int main() {

    string operacao;
    cout << "Qual o nome do seu projeto? ";
    string nomeProjeto;
    cin >> nomeProjeto;
    ifstream file(nomeProjeto + ".asm");
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

    file.close(); //l� o arquivo pela primeira vez pegando os labels

    //criando o arquivo bin�rio
    ofstream bin(nomeProjeto + ".bin"); //cria um arquivo bin�rio com o nome do projeto
    ofstream hex(nomeProjeto + ".hex"); //cria um arquivo hexadecimal com o nome do projeto
    hex << "v2.0 raw" << '\n';


    file.open(nomeProjeto + ".asm"); //abre o arquivo pela segunda vez para ai realmente transformar em bin�rio
    if (!file.is_open() && !file.bad()) {
        cerr << "Arquivo n�o pode ser aberto\n"; //exibe a mensagem de erro
        return 1;
    }

    nLinha = 0;
    while (getline(file, linhaAtual)) { //loop que l� de linha em linha

        size_t indice = linhaAtual.find(':'); //encontra indice de ':'
        if (indice != string::npos) { //verifica se ':' foi encontrado, se n�o, apenas seguir lendo as linhas
            //apaga a parte do label da linha atual
            linhaAtual = linhaAtual.erase(0, indice+1);
        }
        

        while (linhaAtual.find('\t') != string::npos) { //enquanto houver tabula��o na linha
			linhaAtual.erase(linhaAtual.find('\t'), 1); //remove o '\t' da linha atual
		}
        while (linhaAtual[0] == ' ') { //enquanto houver espa�o no in�cio da linha)
            linhaAtual.erase(0, 1); //remove o espa�o do in�cio da linha atual
        }


        indice = linhaAtual.find(' '); //encontra indice de ' ', pois a string est� como "comando regis1, regis2..."   
        string comando = linhaAtual.substr(0, indice); //obtem apenas o comando da linha atual
        string linhaSemComando = linhaAtual.substr(indice + 1, linhaAtual.length()); //nova substring cortando a partir do fim do comando at� o final da string completa
  
        
        //comparando o comando atual com os poss�veis comandos para chamar respectivas fun��es
        string binario, hexadecimal;
        binario = comandoAtual(linhaSemComando, comando, labels, nLinha);
        hexadecimal = binarioParaHexadecimal(binario);

        bin << binario << '\n';
        hex << hexadecimal;
        if ((nLinha+1) % 4 == 0) hex << endl;//pular linha no hexa a cada 4
        else hex << " ";       
        
        nLinha++;
    }

    cout << "Arquivos " << nomeProjeto << ".bin e " << nomeProjeto << ".hex foram criados com sucesso!\n";
    file.close();
    bin.close();
    hex.close();

    return 0;
}