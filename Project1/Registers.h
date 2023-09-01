#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> RRL(string linha, unordered_map<string, int> labels, int nLinha);
vector<string> RRR(string linha);
vector<string> RRI(string linha, bool isRfamily);
vector<string> RI(string linha);
vector<string> R(string linha);
vector<string> RR(string linha);
vector<string> I(string linha);
vector<string> RMI(string linha);
vector<string> L(string linha, unordered_map<string, int> labels, int nLinha);