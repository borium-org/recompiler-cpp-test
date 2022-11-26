#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLRETURN.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionLRETURN::__thisClassStatic;

	void InstructionLRETURN::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionLRETURN",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionLRETURN::InstructionLRETURN() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	bool InstructionLRETURN::fallsThrough()
	{
		return 0;
	}

	int InstructionLRETURN::getStackDepthChange()
	{
		return -1;
	}

}
