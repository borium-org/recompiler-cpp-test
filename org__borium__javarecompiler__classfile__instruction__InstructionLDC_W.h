#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class Class;
	class Object;
	class RuntimeException;
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

namespace org::borium::javarecompiler::classfile::constants
{
	class Constant;
	class ConstantClassInfo;
	class ConstantInteger;
	class ConstantPool;
	class ConstantStringInfo;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionLDC_W : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int index;
		Pointer<Constant> c;
		Pointer<String> value;

		static void __ClassInit();
		InstructionLDC_W(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<Constant> getConstant();
		virtual int getStackDepthChange();
		virtual int length();
	};

}
