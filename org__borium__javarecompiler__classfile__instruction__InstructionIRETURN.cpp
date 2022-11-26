#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIRETURN.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionIRETURN::__thisClassStatic;

	void InstructionIRETURN::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionIRETURN",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionIRETURN::InstructionIRETURN() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	bool InstructionIRETURN::fallsThrough()
	{
		return 0;
	}

	int InstructionIRETURN::getStackDepthChange()
	{
		return -1;
	}

}
