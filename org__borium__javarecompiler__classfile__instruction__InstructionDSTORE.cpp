#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDSTORE.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionDSTORE::__thisClassStatic;

	void InstructionDSTORE::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionDSTORE",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex::__ClassInit();
	}

	InstructionDSTORE::InstructionDSTORE(Pointer<ByteInputStream> in, bool wide) :
		InstructionWithLocalVariableIndex(in, wide) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	InstructionDSTORE::InstructionDSTORE(int index) :
		InstructionWithLocalVariableIndex(index) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionDSTORE::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

	bool InstructionDSTORE::isXStore()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

}
