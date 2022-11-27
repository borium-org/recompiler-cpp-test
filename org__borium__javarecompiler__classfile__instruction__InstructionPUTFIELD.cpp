#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionPUTFIELD.h"
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

	Pointer<Class> InstructionPUTFIELD::__thisClassStatic;

	void InstructionPUTFIELD::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionPUTFIELD",
			org::borium::javarecompiler::classfile::instruction::InstructionWithFieldIndex::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithFieldIndex::__ClassInit();
	}

	InstructionPUTFIELD::InstructionPUTFIELD(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		InstructionWithFieldIndex(in, cp) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	int InstructionPUTFIELD::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -2;
	}

}
