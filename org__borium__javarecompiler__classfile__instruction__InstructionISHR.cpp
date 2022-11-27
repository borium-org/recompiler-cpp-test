#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionISHR.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionISHR::__thisClassStatic;

	void InstructionISHR::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionISHR",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionISHR::InstructionISHR() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionISHR::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

}
