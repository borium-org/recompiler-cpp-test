#pragma once

#include "org__borium__javarecompiler__classfile__instruction__InstructionWithLocalVariableIndex.h"

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class InstructionWithLocalVariableIndex;
}

using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionDLOAD : public InstructionWithLocalVariableIndex
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:

		static void __ClassInit();
		InstructionDLOAD(Pointer<ByteInputStream> in, bool wide);
		InstructionDLOAD(int index);
		virtual int getStackDepthChange();
	};

}
