#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKEINTERFACE.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInterfaceMethodrefInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantNameAndTypeInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionINVOKEINTERFACE::__thisClassStatic;

	void InstructionINVOKEINTERFACE::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionINVOKEINTERFACE",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionINVOKEINTERFACE::InstructionINVOKEINTERFACE(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		Instruction() //
		, index(0) //
		, count(0) //
		, zero(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<ConstantInterfaceMethodrefInfo> temp_0015;
		Pointer<ConstantClassInfo> temp_0027;
		Pointer<ConstantNameAndTypeInfo> temp_0039;
		this->index = in->u2();
		temp_0015 = (ConstantInterfaceMethodrefInfo*)((cp->get(this->index)).getValue());
		temp_0015->checkCast(ConstantInterfaceMethodrefInfo::__thisClassStatic);
		this->methodref = temp_0015.getValue();
		temp_0027 = (ConstantClassInfo*)((cp->get(this->methodref->classIndex)).getValue());
		temp_0027->checkCast(ConstantClassInfo::__thisClassStatic);
		this->classInfo = temp_0027.getValue();
		temp_0039 = (ConstantNameAndTypeInfo*)((cp->get(this->methodref->nameAndTypeIndex)).getValue());
		temp_0039->checkCast(ConstantNameAndTypeInfo::__thisClassStatic);
		this->nameType = temp_0039.getValue();
		this->count = in->u1();
		Statics::__ClassInit();
		Statics::Assert(((((this->count) != 0) ? (1) : (0))) != 0, createString("INVOKEINTERFACE: Count is zero"));
		this->zero = in->u1();
		Statics::__ClassInit();
		Statics::Assert(((((this->zero) == 0) ? (1) : (0))) != 0, createString("INVOKEINTERFACE: Zero is not zero"));
		this->methodClassName = cp->getString(this->classInfo->nameIndex)->replace('/', '.').getValue();
		this->methodName = this->nameType->getName().getValue();
		return;
	}

	void InstructionINVOKEINTERFACE::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->index)->append(createString(" "))->append(this->nameType->getName())->append(createString(" count "))->append(this->count)->toString());
		return;
	}

	int InstructionINVOKEINTERFACE::getCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->count;
	}

	Pointer<String> InstructionINVOKEINTERFACE::getMethodClassName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->methodClassName;
	}

	Pointer<String> InstructionINVOKEINTERFACE::getmethodDescriptor()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->nameType->getDescriptor();
	}

	Pointer<String> InstructionINVOKEINTERFACE::getMethodName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->methodName;
	}

	int InstructionINVOKEINTERFACE::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		int stackDepthChange_0002 = 0;
		stackDepthChange_0002 = 0;
		stackDepthChange_0002 += -1;
		stackDepthChange_0002 = (stackDepthChange_0002) - (this->nameType->getParameterCount());
		stackDepthChange_0002 = (stackDepthChange_0002) + (this->nameType->getReturnTypeCount());
		return stackDepthChange_0002;
	}

	int InstructionINVOKEINTERFACE::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 5;
	}

}
