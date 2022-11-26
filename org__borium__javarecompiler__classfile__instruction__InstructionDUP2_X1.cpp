#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDUP2_X1.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"

using namespace java::lang;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionDUP2_X1::__thisClassStatic;

	void InstructionDUP2_X1::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionDUP2_X1",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionDUP2_X1::InstructionDUP2_X1() :
		Instruction() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionDUP2_X1::getStackDepthChange()
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

}
