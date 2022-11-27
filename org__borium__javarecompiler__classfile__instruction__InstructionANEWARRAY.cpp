#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionANEWARRAY.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionANEWARRAY::__thisClassStatic;

	void InstructionANEWARRAY::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionANEWARRAY",
			org::borium::javarecompiler::classfile::instruction::InstructionWithTypeIndex::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithTypeIndex::__ClassInit();
	}

	InstructionANEWARRAY::InstructionANEWARRAY(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		InstructionWithTypeIndex(in, cp) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionANEWARRAY::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

}
