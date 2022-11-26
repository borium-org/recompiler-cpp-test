#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class ClassFormatError;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
	class InstructionALOAD;
	class InstructionASTORE;
	class InstructionDLOAD;
	class InstructionDSTORE;
	class InstructionFLOAD;
	class InstructionFSTORE;
	class InstructionIINC;
	class InstructionILOAD;
	class InstructionISTORE;
	class InstructionLLOAD;
	class InstructionLSTORE;
	class InstructionRET;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionWIDE : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<Instruction> instruction;

		static void __ClassInit();
		InstructionWIDE(Pointer<ByteInputStream> in);
		virtual Pointer<Instruction> getNestedInstruction();
		virtual int getStackDepthChange();
		virtual int length();
		virtual void setAddress(int address);
	};

}
