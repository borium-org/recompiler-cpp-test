#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionI2S.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionI2S::__thisClassStatic;

	void InstructionI2S::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionI2S",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionI2S::InstructionI2S() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionI2S::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

}
