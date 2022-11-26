#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionARETURN.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionARETURN::__thisClassStatic;

	void InstructionARETURN::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionARETURN",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionARETURN::InstructionARETURN() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	bool InstructionARETURN::fallsThrough()
	{
		return 0;
	}

	int InstructionARETURN::getStackDepthChange()
	{
		return -1;
	}

}
