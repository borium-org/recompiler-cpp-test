#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionPOP2.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionPOP2::__thisClassStatic;

	void InstructionPOP2::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionPOP2",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionPOP2::InstructionPOP2() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionPOP2::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -2;
	}

}
