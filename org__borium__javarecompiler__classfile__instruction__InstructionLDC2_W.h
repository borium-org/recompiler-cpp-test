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

namespace org::borium::javarecompiler::classfile::constants
{
	class Constant;
	class ConstantDouble;
	class ConstantLong;
	class ConstantPool;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionLDC2_W : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int index;
		Pointer<Constant> constant;

		static void __ClassInit();
		InstructionLDC2_W(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<Constant> getConstant();
		virtual int getStackDepthChange();
		virtual int length();
	};

}
