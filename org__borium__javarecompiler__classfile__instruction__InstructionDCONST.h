#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class Double;
	class String;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionDCONST : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		double value;

		static void __ClassInit();
		InstructionDCONST(double value);
		virtual int getStackDepthChange();
		virtual Pointer<String> getValue();
	};

}
