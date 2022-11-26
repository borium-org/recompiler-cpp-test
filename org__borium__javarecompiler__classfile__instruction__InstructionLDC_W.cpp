#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLDC_W.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInteger.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantStringInfo.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionLDC_W::__thisClassStatic;

	void InstructionLDC_W::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionLDC_W",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionLDC_W::InstructionLDC_W(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		Instruction() //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<ConstantStringInfo> stringValue_002A;
		Pointer<ConstantClassInfo> classInfo_0048;
		Pointer<ConstantStringInfo> temp_0026;
		Pointer<ConstantClassInfo> temp_0044;
		this->index = in->u2();
		this->c = cp->get(this->index).getValue();
		if (!(this->c->instanceOf(ConstantStringInfo::__thisClassStatic)))
			goto L0036;
		temp_0026 = (ConstantStringInfo*)((this->c).getValue());
		temp_0026->checkCast(ConstantStringInfo::__thisClassStatic);
		stringValue_002A = temp_0026;
		this->value = stringValue_002A->getValue(cp).getValue();
		goto L0050;
	L0036: //
		if (!(this->c->instanceOf(ConstantClassInfo::__thisClassStatic)))
			goto L0050;
		temp_0044 = (ConstantClassInfo*)((this->c).getValue());
		temp_0044->checkCast(ConstantClassInfo::__thisClassStatic);
		classInfo_0048 = temp_0044;
		this->value = classInfo_0048->getName().getValue();
	L0050: //
		return;
	}

	void InstructionLDC_W::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<String> className_0010;
		Pointer<ConstantStringInfo> stringValue_0022;
		Pointer<ConstantInteger> intValue_005D;
		Pointer<ConstantClassInfo> classInfo_0090;
		Pointer<ConstantStringInfo> temp_001E;
		Pointer<StringBuilder> temp_002B;
		Pointer<ConstantInteger> temp_0059;
		Pointer<StringBuilder> temp_0066;
		Pointer<ConstantClassInfo> temp_008C;
		Pointer<StringBuilder> temp_0099;
		Pointer<StringBuilder> temp_00BF;
		Pointer<StringBuilder> temp_00E0;
		Pointer<RuntimeException> temp_00EB;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		if (!(this->c->instanceOf(ConstantStringInfo::__thisClassStatic)))
			goto L004B;
		temp_001E = (ConstantStringInfo*)((this->c).getValue());
		temp_001E->checkCast(ConstantStringInfo::__thisClassStatic);
		stringValue_0022 = temp_001E;
		String::__ClassInit();
		temp_002B = new StringBuilder(String::valueOf(className_0010.getValue()));
		Statics::__ClassInit();
		stream->iprintln(temp_002B->append(createString(" \""))->append(Statics::escapeCharacters(this->value))->append(createString("\""))->toString());
		goto L00EF;
	L004B: //
		if (!(this->c->instanceOf(ConstantInteger::__thisClassStatic)))
			goto L007E;
		temp_0059 = (ConstantInteger*)((this->c).getValue());
		temp_0059->checkCast(ConstantInteger::__thisClassStatic);
		intValue_005D = temp_0059;
		String::__ClassInit();
		temp_0066 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0066->append(createString(" "))->append(intValue_005D->getValue())->toString());
		goto L00EF;
	L007E: //
		if (!(this->c->instanceOf(ConstantClassInfo::__thisClassStatic)))
			goto L00B6;
		temp_008C = (ConstantClassInfo*)((this->c).getValue());
		temp_008C->checkCast(ConstantClassInfo::__thisClassStatic);
		classInfo_0090 = temp_008C;
		String::__ClassInit();
		temp_0099 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0099->append(createString(" "))->append(this->value)->append(createString(".class"))->toString());
		goto L00EF;
	L00B6: //
		String::__ClassInit();
		temp_00BF = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_00BF->append(createString(" "))->append(this->index)->toString());
		String::__ClassInit();
		temp_00E0 = new StringBuilder(String::valueOf(className_0010.getValue()));
		temp_00EB = new RuntimeException(temp_00E0->append(createString(": Dump not implemented"))->toString());
		throw temp_00EB;
	L00EF: //
		return;
	}

	Pointer<Constant> InstructionLDC_W::getConstant()
	{
		return this->c;
	}

	int InstructionLDC_W::getStackDepthChange()
	{
		return 1;
	}

	int InstructionLDC_W::length()
	{
		return 3;
	}

}
