#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class Class;
	class Object;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler
{
	class Statics;
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
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionWithLabel : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int offset;

		static void __ClassInit();
		InstructionWithLabel(Pointer<ByteInputStream> in);
		virtual void addLabel(int address, Pointer<JavaRawArray<bool>> labels);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual int getTargetAddress(int index);
		virtual int getTargetCount();
		virtual Pointer<String> getTargetLabel();
		virtual int length();
	};

}
