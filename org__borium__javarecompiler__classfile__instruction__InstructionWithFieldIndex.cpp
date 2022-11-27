#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionWithFieldIndex.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantFieldrefInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantNameAndTypeInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionWithFieldIndex::__thisClassStatic;

	void InstructionWithFieldIndex::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionWithFieldIndex",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionWithFieldIndex::InstructionWithFieldIndex(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		Instruction() //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<ConstantFieldrefInfo> temp_0015;
		Pointer<ConstantNameAndTypeInfo> temp_0027;
		this->index = in->u2();
		temp_0015 = (ConstantFieldrefInfo*)((cp->get(this->index)).getValue());
		temp_0015->checkCast(ConstantFieldrefInfo::__thisClassStatic);
		this->fieldref = temp_0015.getValue();
		temp_0027 = (ConstantNameAndTypeInfo*)((cp->get(this->fieldref->nameAndTypeIndex)).getValue());
		temp_0027->checkCast(ConstantNameAndTypeInfo::__thisClassStatic);
		this->nameType = temp_0027.getValue();
		this->fieldName = this->nameType->getName().getValue();
		this->fieldType = this->nameType->getDescriptor().getValue();
		return;
	}

	void InstructionWithFieldIndex::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->fieldName)->append(createString(" "))->append(this->fieldType)->toString());
		return;
	}

	Pointer<String> InstructionWithFieldIndex::getClassName()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0006;
		temp_0006 = new StringBuilder(createString("L"));
		return temp_0006->append(this->fieldref->getClassName())->append(createString(";"))->toString();
	}

	Pointer<String> InstructionWithFieldIndex::getFieldName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->fieldName;
	}

	Pointer<String> InstructionWithFieldIndex::getFieldType()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->fieldType;
	}

	int InstructionWithFieldIndex::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 3;
	}

}
