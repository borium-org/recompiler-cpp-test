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

	class InstructionNEWARRAY : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		static Pointer<JavaArray<String>> elementTypes;
		int atype;

		static void __ClassInit();
		InstructionNEWARRAY(Pointer<ByteInputStream> in);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<String> getElementType();
		virtual int getStackDepthChange();
		virtual int length();
	};

}
