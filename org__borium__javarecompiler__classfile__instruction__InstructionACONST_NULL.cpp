#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionACONST_NULL.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionACONST_NULL::__thisClassStatic;

	void InstructionACONST_NULL::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionACONST_NULL",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionACONST_NULL::InstructionACONST_NULL() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionACONST_NULL::getStackDepthChange()
	{
		return 1;
	}

}
