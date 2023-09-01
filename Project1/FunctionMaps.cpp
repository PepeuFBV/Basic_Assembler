#include <iostream>
#include <string>
#include <unordered_map>
#include "Instructions.h"
#include "functionMaps.h"

void declarandoMaps(void) {

	func["sll"] = sll;
	func["srl"] = srl;
	func["jr"] = jr;
	func["mfhi"] = mfhi;
	func["mflo"] = mflo;
	func["mult"] = mult;
	func["multu"] = multu;
	func["div"] = divF; //plvr reservada
	func["divu"] = divu;
	func["add"] = add;
	func["addu"] = addu;
	func["sub"] = sub;
	func["subu"] = subu;
	func["and"] = andF; //plvr reservada
	func["or"] = orF; //plvr reservada
	func["slt"] = slt;
	func["sltu"] = sltu;
	func["mul"] = mul;
	funcComLabel["beq"] = beq;
	funcComLabel["bne"] = bne;
	func["addi"] = addi;
	func["addiu"] = addiu;
	func["slti"] = slti;
	func["sltiu"] = sltiu;
	func["andi"] = andi;
	func["ori"] = ori;
	func["lui"] = lui;
	func["lw"] = lw;
	func["sw"] = sw;
	funcComLabel["j"] = j;
	funcComLabel["jal"] = jal;
}