#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class Class;
	class Object;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionLCONST : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		INT64 value;

		static void __ClassInit();
		InstructionLCONST(INT64 value);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual int getStackDepthChange();
		virtual Pointer<String> getValue();
	};

}
