#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLCONST.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionLCONST::__thisClassStatic;

	void InstructionLCONST::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionLCONST",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionLCONST::InstructionLCONST(INT64 value) :
		Instruction() //
		, value(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->value = value;
		return;
	}

	void InstructionLCONST::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->value)->toString());
		return;
	}

	int InstructionLCONST::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

	Pointer<String> InstructionLCONST::getValue()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_000B;
		String::__ClassInit();
		temp_000B = new StringBuilder(String::valueOf(this->value));
		return temp_000B->append(createString("LL"))->toString();
	}

}
