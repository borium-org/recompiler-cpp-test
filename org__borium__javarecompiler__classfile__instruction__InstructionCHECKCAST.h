#pragma once

#include "org__borium__javarecompiler__classfile__instruction__InstructionWithTypeIndex.h"

namespace java::lang
{
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
	class ConstantPool;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class InstructionWithTypeIndex;
}

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionCHECKCAST : public InstructionWithTypeIndex
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:

		static void __ClassInit();
		InstructionCHECKCAST(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
		virtual int getStackDepthChange();
		virtual void convertArray();
	};

}
