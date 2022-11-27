#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionRET.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionRET::__thisClassStatic;

	void InstructionRET::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionRET",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionRET::InstructionRET(Pointer<ByteInputStream> in, bool wide) :
		Instruction() //
		, index(0) //
		, wide(false) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->wide = wide;
		this->index = ((wide) ? (in->u2()) : (in->u1()));
		return;
	}

	void InstructionRET::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		Pointer<StringBuilder> temp_003A;
		Pointer<RuntimeException> temp_0045;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->index)->toString());
		String::__ClassInit();
		temp_003A = new StringBuilder(String::valueOf(className_0010.getValue()));
		temp_0045 = new RuntimeException(temp_003A->append(createString(": Dump not implemented"))->toString());
		throw temp_0045;
	}

	int InstructionRET::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

	int InstructionRET::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return ((this->wide) ? (3) : (2));
	}

}
