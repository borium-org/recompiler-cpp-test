#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFRETURN.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionFRETURN::__thisClassStatic;

	void InstructionFRETURN::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionFRETURN",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionFRETURN::InstructionFRETURN() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	bool InstructionFRETURN::fallsThrough()
	{
		return 0;
	}

	int InstructionFRETURN::getStackDepthChange()
	{
		return -1;
	}

}
