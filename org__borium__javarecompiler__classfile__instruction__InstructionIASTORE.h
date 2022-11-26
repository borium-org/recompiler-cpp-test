#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionIASTORE : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:

		static void __ClassInit();
		InstructionIASTORE();
		virtual int getStackDepthChange();
	};

}
