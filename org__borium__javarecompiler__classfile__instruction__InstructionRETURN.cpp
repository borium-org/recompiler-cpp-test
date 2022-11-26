#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionRETURN.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionRETURN::__thisClassStatic;

	void InstructionRETURN::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionRETURN",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionRETURN::InstructionRETURN() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	bool InstructionRETURN::fallsThrough()
	{
		return 0;
	}

	int InstructionRETURN::getStackDepthChange()
	{
		return 0;
	}

}
