#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionWithTypeIndex.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionWithTypeIndex::__thisClassStatic;

	void InstructionWithTypeIndex::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionWithTypeIndex",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionWithTypeIndex::InstructionWithTypeIndex(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		Instruction() //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<ConstantClassInfo> temp_0015;
		this->index = in->u2();
		temp_0015 = (ConstantClassInfo*)((cp->get(this->index)).getValue());
		temp_0015->checkCast(ConstantClassInfo::__thisClassStatic);
		this->classInfo = temp_0015.getValue();
		this->className = cp->getString(this->classInfo->nameIndex)->replace('/', '.').getValue();
		return;
	}

	void InstructionWithTypeIndex::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<String> instructionClassName_0010;
		Pointer<StringBuilder> temp_0019;
		instructionClassName_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(instructionClassName_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->className)->toString());
		return;
	}

	Pointer<String> InstructionWithTypeIndex::getClassName()
	{
		return this->className;
	}

	int InstructionWithTypeIndex::length()
	{
		return 3;
	}

}
