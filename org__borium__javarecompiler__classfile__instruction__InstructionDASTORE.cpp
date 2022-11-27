#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDASTORE.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionDASTORE::__thisClassStatic;

	void InstructionDASTORE::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionDASTORE",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionDASTORE::InstructionDASTORE() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionDASTORE::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -3;
	}

}
