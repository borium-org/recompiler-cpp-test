#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ACMPEQ.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionIF_ACMPEQ::__thisClassStatic;

	void InstructionIF_ACMPEQ::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionIF_ACMPEQ",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__ClassInit();
	}

	InstructionIF_ACMPEQ::InstructionIF_ACMPEQ(Pointer<ByteInputStream> in) :
		InstructionWithLabel(in) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionIF_ACMPEQ::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -2;
	}

}
