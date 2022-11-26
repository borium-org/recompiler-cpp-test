#pragma once

#include "org__borium__javarecompiler__classfile__instruction__InstructionWithFieldIndex.h"

namespace java::lang
{
	class String;
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
	class InstructionWithFieldIndex;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionGETSTATIC : public InstructionWithFieldIndex
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:

		static void __ClassInit();
		InstructionGETSTATIC(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
		virtual int getStackDepthChange();
	};

}
