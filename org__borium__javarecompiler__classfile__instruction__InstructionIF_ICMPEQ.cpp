#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ICMPEQ.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionIF_ICMPEQ::__thisClassStatic;

	void InstructionIF_ICMPEQ::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionIF_ICMPEQ",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__ClassInit();
	}

	InstructionIF_ICMPEQ::InstructionIF_ICMPEQ(Pointer<ByteInputStream> in) :
		InstructionWithLabel(in) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionIF_ICMPEQ::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -2;
	}

}
