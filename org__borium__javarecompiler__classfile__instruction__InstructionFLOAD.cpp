#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFLOAD.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionFLOAD::__thisClassStatic;

	void InstructionFLOAD::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionFLOAD",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex::__ClassInit();
	}

	InstructionFLOAD::InstructionFLOAD(Pointer<ByteInputStream> in, bool wide) :
		InstructionWithLocalVariableIndex(in, wide) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	InstructionFLOAD::InstructionFLOAD(int index) :
		InstructionWithLocalVariableIndex(index) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionFLOAD::getStackDepthChange()
	{
		return 1;
	}

}
