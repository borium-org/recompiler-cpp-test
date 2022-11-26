#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDRETURN.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionDRETURN::__thisClassStatic;

	void InstructionDRETURN::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionDRETURN",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionDRETURN::InstructionDRETURN() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	bool InstructionDRETURN::fallsThrough()
	{
		return 0;
	}

	int InstructionDRETURN::getStackDepthChange()
	{
		return -1;
	}

}
