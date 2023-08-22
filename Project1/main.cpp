#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

string verificaRegistrador(void); //retorna registrador em binário
void organizaRegistradores(string opcode, string function, string rd, string rs, string rt); //recebe binario em string e junta no arquivo destino

//passar lendo a primeira vez encontrando os labels (com : no final)
//ler uma segunda vez apenas o código e se label for referenciado olhar a array e definir

int main() {

    ifstream file("entrada.asm");
    if (!file.is_open() && !file.bad()) {
        cerr << "Arquivo não pode ser aberto\n"; //exibe a mensagem de erro
        return 1;
    }

    string linhaAtual;
    unordered_map<string, int> labels;
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

    while (getline(file, linhaAtual)) { //loop que lê de linha em linha

        size_t indice = linhaAtual.find(':'); //encontra indice de ':'
        if (indice != string::npos) { //verifica se ':' foi encontrado, se não, apenas seguir lendo as linhas
            //cria uma nova substring cortando a partir do fim do label até o final da string completa
            linhaAtual = linhaAtual.substr(indice+2, linhaAtual.length());
        }
        cout << linhaAtual;
        //temos que ver ainda a questão de remover os /t das strings após a remoção dos labels
        //em sequencia ver qual é a instrução, seguindo para um switch para cada tipo de instrução
    }
    





    return 0;
}
