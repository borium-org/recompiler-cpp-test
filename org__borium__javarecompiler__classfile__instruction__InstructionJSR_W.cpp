#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionJSR_W.h"
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

	Pointer<Class> InstructionJSR_W::__thisClassStatic;

	void InstructionJSR_W::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionJSR_W",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionJSR_W::InstructionJSR_W(Pointer<ByteInputStream> in) :
		Instruction() //
		, offset(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->offset = in->s4();
		return;
	}

	void InstructionJSR_W::addLabel(int address, Pointer<JavaRawArray<bool>> labels)
	{
		UsageCounterMaintainer maintainer(this, true);

		labels->assign((address) + (this->offset), (1) & 1);
		return;
	}

	void InstructionJSR_W::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" L"))->append((this->address) + (this->offset))->toString());
		return;
	}

	int InstructionJSR_W::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

	int InstructionJSR_W::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 5;
	}

}
