#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLSHR.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionLSHR::__thisClassStatic;

	void InstructionLSHR::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionLSHR",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionLSHR::InstructionLSHR() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionLSHR::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

}
