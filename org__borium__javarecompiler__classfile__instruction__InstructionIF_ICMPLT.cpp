#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIF_ICMPLT.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionIF_ICMPLT::__thisClassStatic;

	void InstructionIF_ICMPLT::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionIF_ICMPLT",
			org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithLabel::__ClassInit();
	}

	InstructionIF_ICMPLT::InstructionIF_ICMPLT(Pointer<ByteInputStream> in) :
		InstructionWithLabel(in) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionIF_ICMPLT::getStackDepthChange()
	{
		return -2;
	}

}
