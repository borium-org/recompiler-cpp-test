#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKESTATIC.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantMethodrefInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantNameAndTypeInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionINVOKESTATIC::__thisClassStatic;

	void InstructionINVOKESTATIC::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionINVOKESTATIC",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionINVOKESTATIC::InstructionINVOKESTATIC(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		Instruction() //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<ConstantMethodrefInfo> temp_0015;
		Pointer<ConstantClassInfo> temp_0027;
		Pointer<ConstantNameAndTypeInfo> temp_0039;
		this->index = in->u2();
		temp_0015 = (ConstantMethodrefInfo*)((cp->get(this->index)).getValue());
		temp_0015->checkCast(ConstantMethodrefInfo::__thisClassStatic);
		this->methodref = temp_0015.getValue();
		temp_0027 = (ConstantClassInfo*)((cp->get(this->methodref->classIndex)).getValue());
		temp_0027->checkCast(ConstantClassInfo::__thisClassStatic);
		this->classInfo = temp_0027.getValue();
		temp_0039 = (ConstantNameAndTypeInfo*)((cp->get(this->methodref->nameAndTypeIndex)).getValue());
		temp_0039->checkCast(ConstantNameAndTypeInfo::__thisClassStatic);
		this->nameType = temp_0039.getValue();
		this->methodClassName = cp->getString(this->classInfo->nameIndex)->replace('/', '.').getValue();
		this->methodName = this->nameType->getName().getValue();
		return;
	}

	void InstructionINVOKESTATIC::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->methodClassName)->append(createString("."))->append(this->methodName)->toString());
		return;
	}

	Pointer<String> InstructionINVOKESTATIC::getMethodClassName()
	{
		return this->methodClassName;
	}

	Pointer<String> InstructionINVOKESTATIC::getmethodDescriptor()
	{
		return this->nameType->getDescriptor();
	}

	Pointer<String> InstructionINVOKESTATIC::getMethodName()
	{
		return this->methodName;
	}

	int InstructionINVOKESTATIC::getStackDepthChange()
	{
		int stackDepthChange_0002 = 0;
		stackDepthChange_0002 = 0;
		stackDepthChange_0002 = (stackDepthChange_0002) - (this->nameType->getParameterCount());
		stackDepthChange_0002 = (stackDepthChange_0002) + (this->nameType->getReturnTypeCount());
		return stackDepthChange_0002;
	}

	int InstructionINVOKESTATIC::length()
	{
		return 3;
	}

}
