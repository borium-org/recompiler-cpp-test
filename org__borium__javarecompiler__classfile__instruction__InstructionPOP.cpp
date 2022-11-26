#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionPOP.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionPOP::__thisClassStatic;

	void InstructionPOP::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionPOP",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionPOP::InstructionPOP() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionPOP::getStackDepthChange()
	{
		return -1;
	}

}
