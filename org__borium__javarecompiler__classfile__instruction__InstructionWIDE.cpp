#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionWIDE.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__ClassFormatError.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionALOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDLOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDSTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFLOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFSTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIINC.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionILOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionISTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLLOAD.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLSTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionRET.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionWIDE::__thisClassStatic;

	void InstructionWIDE::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionWIDE",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionWIDE::InstructionWIDE(Pointer<ByteInputStream> in) :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		int opcode_0009 = 0;
		Pointer<InstructionILOAD> temp_007B;
		Pointer<InstructionFLOAD> temp_008B;
		Pointer<InstructionALOAD> temp_009B;
		Pointer<InstructionLLOAD> temp_00AB;
		Pointer<InstructionDLOAD> temp_00BB;
		Pointer<InstructionISTORE> temp_00CB;
		Pointer<InstructionFSTORE> temp_00DB;
		Pointer<InstructionASTORE> temp_00EB;
		Pointer<InstructionLSTORE> temp_00FB;
		Pointer<InstructionDSTORE> temp_010B;
		Pointer<InstructionRET> temp_011B;
		Pointer<InstructionIINC> temp_012B;
		Pointer<StringBuilder> temp_013E;
		Pointer<ClassFormatError> temp_014D;
		opcode_0009 = in->u1();
		switch (opcode_0009)
		{
		case (int)0x00000015:
			goto L0074;
		case (int)0x00000016:
			goto L00A4;
		case (int)0x00000017:
			goto L0084;
		case (int)0x00000018:
			goto L00B4;
		case (int)0x00000019:
			goto L0094;
		case (int)0x00000036:
			goto L00C4;
		case (int)0x00000037:
			goto L00F4;
		case (int)0x00000038:
			goto L00D4;
		case (int)0x00000039:
			goto L0104;
		case (int)0x0000003A:
			goto L00E4;
		case (int)0x00000084:
			goto L0124;
		case (int)0x000000A9:
			goto L0114;
		default:
			goto L0134;
		}
	L0074: //
		temp_007B = new InstructionILOAD(in, true);
		this->instruction = (Instruction*)temp_007B.getValue();
		goto L0151;
	L0084: //
		temp_008B = new InstructionFLOAD(in, true);
		this->instruction = (Instruction*)temp_008B.getValue();
		goto L0151;
	L0094: //
		temp_009B = new InstructionALOAD(in, true);
		this->instruction = (Instruction*)temp_009B.getValue();
		goto L0151;
	L00A4: //
		temp_00AB = new InstructionLLOAD(in, true);
		this->instruction = (Instruction*)temp_00AB.getValue();
		goto L0151;
	L00B4: //
		temp_00BB = new InstructionDLOAD(in, true);
		this->instruction = (Instruction*)temp_00BB.getValue();
		goto L0151;
	L00C4: //
		temp_00CB = new InstructionISTORE(in, true);
		this->instruction = (Instruction*)temp_00CB.getValue();
		goto L0151;
	L00D4: //
		temp_00DB = new InstructionFSTORE(in, true);
		this->instruction = (Instruction*)temp_00DB.getValue();
		goto L0151;
	L00E4: //
		temp_00EB = new InstructionASTORE(in, true);
		this->instruction = (Instruction*)temp_00EB.getValue();
		goto L0151;
	L00F4: //
		temp_00FB = new InstructionLSTORE(in, true);
		this->instruction = (Instruction*)temp_00FB.getValue();
		goto L0151;
	L0104: //
		temp_010B = new InstructionDSTORE(in, true);
		this->instruction = (Instruction*)temp_010B.getValue();
		goto L0151;
	L0114: //
		temp_011B = new InstructionRET(in, true);
		this->instruction = (Instruction*)temp_011B.getValue();
		goto L0151;
	L0124: //
		temp_012B = new InstructionIINC(in, true);
		this->instruction = (Instruction*)temp_012B.getValue();
		goto L0151;
	L0134: //
		temp_013E = new StringBuilder(createString("WIDE opcode "));
		temp_014D = new ClassFormatError(temp_013E->append(opcode_0009)->append(createString(" not supported"))->toString());
		throw temp_014D;
	L0151: //
		return;
	}

	Pointer<Instruction> InstructionWIDE::getNestedInstruction()
	{
		return this->instruction;
	}

	int InstructionWIDE::getStackDepthChange()
	{
		return this->instruction->getStackDepthChange();
	}

	int InstructionWIDE::length()
	{
		return (this->instruction->length()) + (1);
	}

	void InstructionWIDE::setAddress(int address)
	{
		this->address = address;
		this->instruction->address = address;
		return;
	}

}
