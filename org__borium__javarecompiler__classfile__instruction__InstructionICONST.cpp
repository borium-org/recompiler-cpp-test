#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionICONST.h"
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

	Pointer<Class> InstructionICONST::__thisClassStatic;

	void InstructionICONST::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionICONST",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionICONST::InstructionICONST(int value) :
		Instruction() //
		, value(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->value = value;
		return;
	}

	void InstructionICONST::detailedDump(Pointer<IndentedOutputStream> stream)
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

	int InstructionICONST::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

	int InstructionICONST::getValue()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->value;
	}

}
