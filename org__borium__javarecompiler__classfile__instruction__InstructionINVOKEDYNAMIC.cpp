#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKEDYNAMIC.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__ClassFormatError.h"
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

	Pointer<Class> InstructionINVOKEDYNAMIC::__thisClassStatic;

	void InstructionINVOKEDYNAMIC::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionINVOKEDYNAMIC",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionINVOKEDYNAMIC::InstructionINVOKEDYNAMIC(Pointer<ByteInputStream> in) :
		Instruction() //
		, index(0) //
		, zero(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<ClassFormatError> temp_0021;
		this->index = in->u2();
		this->zero = in->u2();
		if ((this->zero) == 0)
			goto L0025;
		temp_0021 = new ClassFormatError(createString("INVOKEDYNAMIC non-zero"));
		throw temp_0021;
	L0025: //
		return;
	}

	void InstructionINVOKEDYNAMIC::detailedDump(Pointer<IndentedOutputStream> stream)
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

	int InstructionINVOKEDYNAMIC::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> name_000D;
		Pointer<StringBuilder> temp_0019;
		Pointer<RuntimeException> temp_0024;
		name_000D = this->getClass()->getSimpleName()->substring(11);
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(name_000D.getValue()));
		temp_0024 = new RuntimeException(temp_0019->append(createString(" stack depth change not implemented"))->toString());
		throw temp_0024;
	}

	int InstructionINVOKEDYNAMIC::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 5;
	}

}
