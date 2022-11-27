#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLDC2_W.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantDouble.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantLong.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionLDC2_W::__thisClassStatic;

	void InstructionLDC2_W::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionLDC2_W",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionLDC2_W::InstructionLDC2_W(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		Instruction() //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->index = in->u2();
		this->constant = cp->get(this->index).getValue();
		return;
	}

	void InstructionLDC2_W::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0010;
		Pointer<ConstantLong> constantLong_0022;
		Pointer<ConstantDouble> constantDouble_0061;
		Pointer<ConstantLong> temp_001E;
		Pointer<StringBuilder> temp_002B;
		Pointer<ConstantDouble> temp_005D;
		Pointer<StringBuilder> temp_006A;
		Pointer<StringBuilder> temp_0097;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		if (!(this->constant->instanceOf(ConstantLong::__thisClassStatic)))
			goto L004F;
		temp_001E = (ConstantLong*)((this->constant).getValue());
		temp_001E->checkCast(ConstantLong::__thisClassStatic);
		constantLong_0022 = temp_001E;
		String::__ClassInit();
		temp_002B = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_002B->append(createString(" "))->append(this->index)->append(createString(" "))->append(constantLong_0022->value)->toString());
		goto L00BE;
	L004F: //
		if (!(this->constant->instanceOf(ConstantDouble::__thisClassStatic)))
			goto L008E;
		temp_005D = (ConstantDouble*)((this->constant).getValue());
		temp_005D->checkCast(ConstantDouble::__thisClassStatic);
		constantDouble_0061 = temp_005D;
		String::__ClassInit();
		temp_006A = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_006A->append(createString(" "))->append(this->index)->append(createString(" "))->append(constantDouble_0061->value)->toString());
		goto L00BE;
	L008E: //
		String::__ClassInit();
		temp_0097 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0097->append(createString(" "))->append(this->index)->append(createString(" "))->append(this->constant->getClass()->getSimpleName())->toString());
	L00BE: //
		return;
	}

	Pointer<Constant> InstructionLDC2_W::getConstant()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->constant;
	}

	int InstructionLDC2_W::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 1;
	}

	int InstructionLDC2_W::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 3;
	}

}
