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
	class ByteInputStream;
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

	class InstructionWithLocalVariableIndex : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int index;
		int indexConstantLength;

		static void __ClassInit();
		InstructionWithLocalVariableIndex(Pointer<ByteInputStream> in, bool wide);
		InstructionWithLocalVariableIndex(int index);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual int getIndex();
		virtual int length();
	};

}
