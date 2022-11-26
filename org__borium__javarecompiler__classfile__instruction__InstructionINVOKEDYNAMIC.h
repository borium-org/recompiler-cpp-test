#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class Class;
	class ClassFormatError;
	class Object;
	class RuntimeException;
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

	class InstructionINVOKEDYNAMIC : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int index;
		int zero;

		static void __ClassInit();
		InstructionINVOKEDYNAMIC(Pointer<ByteInputStream> in);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual int getStackDepthChange();
		virtual int length();
	};

}
