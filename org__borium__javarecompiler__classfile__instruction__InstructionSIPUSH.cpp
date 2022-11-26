#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionSIPUSH.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionSIPUSH::__thisClassStatic;

	void InstructionSIPUSH::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionSIPUSH",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionSIPUSH::InstructionSIPUSH(Pointer<ByteInputStream> in) :
		Instruction() //
		, value(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		this->value = in->s2();
		return;
	}

	void InstructionSIPUSH::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->value)->toString());
		return;
	}

	int InstructionSIPUSH::getStackDepthChange()
	{
		return 1;
	}

	int InstructionSIPUSH::getValue()
	{
		return this->value;
	}

	int InstructionSIPUSH::length()
	{
		return 3;
	}

}
