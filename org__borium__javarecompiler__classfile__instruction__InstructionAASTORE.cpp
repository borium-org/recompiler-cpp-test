#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionAASTORE.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionAASTORE::__thisClassStatic;

	void InstructionAASTORE::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionAASTORE",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionAASTORE::InstructionAASTORE() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionAASTORE::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -3;
	}

}
