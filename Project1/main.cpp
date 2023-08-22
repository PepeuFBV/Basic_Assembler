#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

string verificaRegistrador(void); //retorna registrador em bin�rio
void organizaRegistradores(string opcode, string function, string rd, string rs, string rt); //recebe binario em string e junta no arquivo destino

//passar lendo a primeira vez encontrando os labels (com : no final)
//ler uma segunda vez apenas o c�digo e se label for referenciado olhar a array e definir

int main() {

    ifstream file("entrada.asm");
    if (!file.is_open() && !file.bad()) {
        cerr << "Arquivo n�o pode ser aberto\n"; //exibe a mensagem de erro
        return 1;
    }

    string linhaAtual;
    unordered_map<string, int> labels;
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


    file.open("entrada.asm"); //abre o arquivo pela segunda vez para ai realmente transformar em bin�rio
    if (!file.is_open() && !file.bad()) {
        cerr << "Arquivo n�o pode ser aberto\n"; //exibe a mensagem de erro
        return 1;
    }

    while (getline(file, linhaAtual)) { //loop que l� de linha em linha

        size_t indice = linhaAtual.find(':'); //encontra indice de ':'
        if (indice != string::npos) { //verifica se ':' foi encontrado, se n�o, apenas seguir lendo as linhas
            //cria uma nova substring cortando a partir do fim do label at� o final da string completa
            linhaAtual = linhaAtual.substr(indice+2, linhaAtual.length());
        }
        cout << linhaAtual;
        //temos que ver ainda a quest�o de remover os /t das strings ap�s a remo��o dos labels
        //em sequencia ver qual � a instru��o, seguindo para um switch para cada tipo de instru��o
    }
    





    return 0;
}
