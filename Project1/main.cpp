#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string verificaRegistrador(void); //retorna registrador em binário
void organizaRegistradores(string opcode, string function, string rd, string rs, string rt); //recebe binario em string e junta no arquivo destino

//passar lendo a primeira vez encontrando os labels (com : no final)
//ler uma segunda vez apenas o código e se label for referenciado olhar a array e definir

int main() {
    ifstream file("entrada.asm");
    if (!file.is_open() && !file.bad()) {
        cerr << "Could not open the file.\n";
        return 1;
    }

    string linha;
    vector<string> labels;

    while (getline(file, linha)) { //le a linha atual
        size_t pos = linha.find(':'); //encontra o ':' na linha
        if (pos != string::npos) {
            string label = linha.substr(0, pos); //obtem o label sem o resto da string
            labels.push_back(label); //coloca a label 
        }
    }

    file.close();

    // Print the extracted labels
    cout << "Extracted labels:\n";
    for (const string& label : labels) {
        cout << label << endl;
    }








    





    return 0;
}
