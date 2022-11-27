#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIFNONNULL.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionIFNONNULL::__thisClassStatic;

	void InstructionIFNONNULL::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionIFNONNULL",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__ClassInit();
	}

	InstructionIFNONNULL::InstructionIFNONNULL(Pointer<ByteInputStream> in) :
		InstructionWithLabel(in) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionIFNONNULL::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

}
