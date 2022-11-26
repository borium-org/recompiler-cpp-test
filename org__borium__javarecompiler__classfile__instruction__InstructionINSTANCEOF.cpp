#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINSTANCEOF.h"
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

	Pointer<Class> InstructionINSTANCEOF::__thisClassStatic;

	void InstructionINSTANCEOF::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionINSTANCEOF",
			org::borium::javarecompiler::classfile::instruction::InstructionWithTypeIndex::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithTypeIndex::__ClassInit();
	}

	InstructionINSTANCEOF::InstructionINSTANCEOF(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		InstructionWithTypeIndex(in, cp) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	int InstructionINSTANCEOF::getStackDepthChange()
	{
		return 0;
	}

}
