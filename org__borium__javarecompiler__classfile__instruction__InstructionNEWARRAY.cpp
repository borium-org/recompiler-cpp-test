#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionNEWARRAY.h"
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

	Pointer<Class> InstructionNEWARRAY::__thisClassStatic;

	Pointer<JavaArray<String>> InstructionNEWARRAY::elementTypes;

	void InstructionNEWARRAY::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionNEWARRAY",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		Pointer<JavaArray<String>> temp_0002;
		Instruction::__ClassInit();
		temp_0002 = new JavaArray<String>(12);
		temp_0002->assign(0, createString("0"));
		temp_0002->assign(1, createString("1"));
		temp_0002->assign(2, createString("2"));
		temp_0002->assign(3, createString("3"));
		temp_0002->assign(4, createString("bool"));
		temp_0002->assign(5, createString("char"));
		temp_0002->assign(6, createString("float"));
		temp_0002->assign(7, createString("double"));
		temp_0002->assign(8, createString("byte"));
		temp_0002->assign(9, createString("short"));
		temp_0002->assign(10, createString("int"));
		temp_0002->assign(11, createString("INT64"));
		InstructionNEWARRAY::elementTypes = temp_0002;
		return;
	}

	InstructionNEWARRAY::InstructionNEWARRAY(Pointer<ByteInputStream> in) :
		Instruction() //
		, atype(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->atype = in->u1();
		return;
	}

	void InstructionNEWARRAY::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		InstructionNEWARRAY::__ClassInit();
		stream->iprintln(temp_0019->append(createString(" "))->append(InstructionNEWARRAY::elementTypes->get(this->atype))->toString());
		return;
	}

	Pointer<String> InstructionNEWARRAY::getElementType()
	{
		UsageCounterMaintainer maintainer(this, true);

		InstructionNEWARRAY::__ClassInit();
		return InstructionNEWARRAY::elementTypes->get(this->atype);
	}

	int InstructionNEWARRAY::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

	int InstructionNEWARRAY::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 2;
	}

}
