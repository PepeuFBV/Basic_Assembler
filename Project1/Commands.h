#include <string>
#include <unordered_map>

using namespace std;

string add(string linhaAtual);



string beq(string linhaAtual, unordered_map<string, int> labels, int nLinha);
string bne(string linhaAtual, unordered_map<string, int> labels, int nLinha);
string addi(string linhaAtual);
string addiu(string linhaAtual);
string slti(string linhaAtual);
string sltiu(string linhaAtual);
string andi(string linhaAtual);
string ori(string linhaAtual);
string lui(string linhaAtual);
string lw(string linhaAtual);
string sw(string linhaAtual);