#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionWithLabel.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionWithLabel::__thisClassStatic;

	void InstructionWithLabel::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionWithLabel",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionWithLabel::InstructionWithLabel(Pointer<ByteInputStream> in) :
		Instruction() //
		, offset(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->offset = in->s2();
		return;
	}

	void InstructionWithLabel::addLabel(int address, Pointer<JavaRawArray<bool>> labels)
	{
		UsageCounterMaintainer maintainer(this, true);

		labels->assign((address) + (this->offset), (1) & 1);
		return;
	}

	void InstructionWithLabel::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprint(temp_0019->append(createString(" L"))->toString());
		stream->printHex((this->address) + (this->offset), 4);
		stream->println();
		return;
	}

	int InstructionWithLabel::getTargetAddress(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		Statics::__ClassInit();
		Statics::Assert(((((index) == 0) ? (1) : (0))) != 0, createString("InstructionWithLabel: Bad target index"));
		return (this->address) + (this->offset);
	}

	int InstructionWithLabel::getTargetCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

	Pointer<String> InstructionWithLabel::getTargetLabel()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0006;
		temp_0006 = new StringBuilder(createString("L"));
		Statics::__ClassInit();
		return temp_0006->append(Statics::hexString((this->address) + (this->offset), 4))->toString();
	}

	int InstructionWithLabel::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 3;
	}

}
