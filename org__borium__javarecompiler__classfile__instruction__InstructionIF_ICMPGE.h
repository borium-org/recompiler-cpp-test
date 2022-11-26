#pragma once

#include "org__borium__javarecompiler__classfile__instruction__InstructionWithLabel.h"

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class InstructionWithLabel;
}

using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionIF_ICMPGE : public InstructionWithLabel
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:

		static void __ClassInit();
		InstructionIF_ICMPGE(Pointer<ByteInputStream> in);
		virtual int getStackDepthChange();
	};

}
