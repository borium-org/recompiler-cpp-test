#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionL2D.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionL2D::__thisClassStatic;

	void InstructionL2D::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionL2D",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionL2D::InstructionL2D() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionL2D::getStackDepthChange()
	{
		return 0;
	}

}
