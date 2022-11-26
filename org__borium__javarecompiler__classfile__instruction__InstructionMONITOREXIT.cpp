#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionMONITOREXIT.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionMONITOREXIT::__thisClassStatic;

	void InstructionMONITOREXIT::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionMONITOREXIT",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionMONITOREXIT::InstructionMONITOREXIT() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionMONITOREXIT::getStackDepthChange()
	{
		return -1;
	}

}
