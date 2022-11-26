#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionARRAYLENGTH.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionARRAYLENGTH::__thisClassStatic;

	void InstructionARRAYLENGTH::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionARRAYLENGTH",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionARRAYLENGTH::InstructionARRAYLENGTH() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionARRAYLENGTH::getStackDepthChange()
	{
		return 0;
	}

}
