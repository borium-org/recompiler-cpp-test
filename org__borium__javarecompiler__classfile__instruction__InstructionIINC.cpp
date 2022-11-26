#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIINC.h"
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

	Pointer<Class> InstructionIINC::__thisClassStatic;

	void InstructionIINC::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionIINC",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionIINC::InstructionIINC(Pointer<ByteInputStream> in, bool wide) :
		Instruction() //
		, index(0) //
		, constant(0) //
		, wide(false) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		this->wide = wide;
		this->index = ((wide) ? (in->u2()) : (in->u1()));
		this->constant = ((wide) ? (in->s2()) : (in->s1()));
		return;
	}

	void InstructionIINC::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->index)->append(createString(" "))->append(this->constant)->toString());
		return;
	}

	int InstructionIINC::getIndex()
	{
		return this->index;
	}

	int InstructionIINC::getStackDepthChange()
	{
		return 0;
	}

	int InstructionIINC::getValue()
	{
		return this->constant;
	}

	int InstructionIINC::length()
	{
		return ((this->wide) ? (5) : (3));
	}

}
