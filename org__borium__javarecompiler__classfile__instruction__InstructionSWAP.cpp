#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionSWAP.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionSWAP::__thisClassStatic;

	void InstructionSWAP::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionSWAP",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionSWAP::InstructionSWAP() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionSWAP::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

}
