#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDCONST.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Double.h"
#include "java__lang__String.h"

using namespace java::lang;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionDCONST::__thisClassStatic;

	void InstructionDCONST::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionDCONST",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionDCONST::InstructionDCONST(double value) :
		Instruction() //
		, value(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->value = value;
		return;
	}

	int InstructionDCONST::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

	Pointer<String> InstructionDCONST::getValue()
	{
		UsageCounterMaintainer maintainer(this, true);

		Double::__ClassInit();
		return Double::toString(this->value);
	}

}
