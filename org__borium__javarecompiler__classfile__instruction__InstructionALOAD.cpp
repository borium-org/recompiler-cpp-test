#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionALOAD.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionALOAD::__thisClassStatic;

	void InstructionALOAD::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionALOAD",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex::__ClassInit();
	}

	InstructionALOAD::InstructionALOAD(Pointer<ByteInputStream> in, bool wide) :
		InstructionWithLocalVariableIndex(in, wide) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	InstructionALOAD::InstructionALOAD(int index) :
		InstructionWithLocalVariableIndex(index) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionALOAD::getIndex()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->index;
	}

	int InstructionALOAD::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

}
