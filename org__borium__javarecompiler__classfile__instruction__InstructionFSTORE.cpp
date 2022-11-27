#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFSTORE.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionFSTORE::__thisClassStatic;

	void InstructionFSTORE::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionFSTORE",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex::__ClassInit();
	}

	InstructionFSTORE::InstructionFSTORE(Pointer<ByteInputStream> in, bool wide) :
		InstructionWithLocalVariableIndex(in, wide) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	InstructionFSTORE::InstructionFSTORE(int index) :
		InstructionWithLocalVariableIndex(index) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionFSTORE::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

	bool InstructionFSTORE::isXStore()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

}
