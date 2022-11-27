#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLASTORE.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionLASTORE::__thisClassStatic;

	void InstructionLASTORE::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionLASTORE",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionLASTORE::InstructionLASTORE() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionLASTORE::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -3;
	}

}
