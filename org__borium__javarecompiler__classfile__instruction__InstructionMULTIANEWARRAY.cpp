#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionMULTIANEWARRAY.h"
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

	Pointer<Class> InstructionMULTIANEWARRAY::__thisClassStatic;

	void InstructionMULTIANEWARRAY::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionMULTIANEWARRAY",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionMULTIANEWARRAY::InstructionMULTIANEWARRAY(Pointer<ByteInputStream> in) :
		Instruction() //
		, index(0) //
		, dimensions(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		this->index = in->u2();
		this->dimensions = in->u1();
		return;
	}

	void InstructionMULTIANEWARRAY::detailedDump(Pointer<IndentedOutputStream> stream)
	{
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

	int InstructionMULTIANEWARRAY::getStackDepthChange()
	{
		Pointer<String> name_000D;
		Pointer<StringBuilder> temp_0019;
		Pointer<RuntimeException> temp_0024;
		name_000D = this->getClass()->getSimpleName()->substring(11);
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(name_000D.getValue()));
		temp_0024 = new RuntimeException(temp_0019->append(createString(" stack depth change not implemented"))->toString());
		throw temp_0024;
	}

	int InstructionMULTIANEWARRAY::length()
	{
		return 4;
	}

}
