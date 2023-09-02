#include <string>
#include <unordered_map>

using namespace std;

typedef string(*ptrFunc)(string);
typedef string(*ptrFuncComLabel)(string, unordered_map<string, int>, int);

unordered_map<string, ptrFunc> declarandoMaps(void);
unordered_map<string, ptrFuncComLabel> declarandoMaps2(void);

string sll(string linhaAtual);
string srl(string linhaAtual);
string jr(string linhaAtual);
string mfhi(string linhaAtual);
string mflo(string linhaAtual);
string mult(string linhaAtual);
string multu(string linhaAtual);
string divF(string linhaAtual);
string divu(string linhaAtual);
string add(string linhaAtual);
string addu(string linhaAtual);
string sub(string linhaAtual);
string subu(string linhaAtual);
string andF(string linhaAtual);
string orF(string linhaAtual);
string slt(string linhaAtual);
string sltu(string linhaAtual);
string mul(string linhaAtual);

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

string j(string linhaAtual, unordered_map<string, int> labels, int nLinha);
string jal(string linhaAtual, unordered_map<string, int> labels, int nLinha);