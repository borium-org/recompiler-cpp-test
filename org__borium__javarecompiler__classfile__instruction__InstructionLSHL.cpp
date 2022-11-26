#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLSHL.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionLSHL::__thisClassStatic;

	void InstructionLSHL::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionLSHL",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionLSHL::InstructionLSHL() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionLSHL::getStackDepthChange()
	{
		return -1;
	}

}
