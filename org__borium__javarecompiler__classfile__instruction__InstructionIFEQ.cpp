#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFEQ.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionIFEQ::__thisClassStatic;

	void InstructionIFEQ::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionIFEQ",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__ClassInit();
	}

	InstructionIFEQ::InstructionIFEQ(Pointer<ByteInputStream> in) :
		InstructionWithLabel(in) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionIFEQ::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

}
