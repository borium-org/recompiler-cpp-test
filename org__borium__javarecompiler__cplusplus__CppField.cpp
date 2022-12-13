#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__CppField.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ClassField.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeConstantValue.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInteger.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantStringInfo.h"
#include "org__borium__javarecompiler__cplusplus__JavaTypeConverter.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> CppField::__thisClassStatic;

	void CppField::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::CppField",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	CppField::CppField(Pointer<ClassField> javaField) :
		Object() //
		, accessFlags(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<String> javaType_0011;
		Pointer<AttributeConstantValue> temp_0020;
		Pointer<JavaTypeConverter> temp_003B;
		this->name = javaField->getName().getValue();
		javaType_0011 = javaField->getType();
		this->accessFlags = javaField->getAccessFlags();
		AttributeConstantValue::__ClassInit();
		temp_0020 = (AttributeConstantValue*)((javaField->getAttribute(createString("ConstantValue"))).getValue());
		temp_0020->checkCast(AttributeConstantValue::__thisClassStatic);
		this->attributeConstantValue = temp_0020.getValue();
		temp_003B = new JavaTypeConverter(javaType_0011, (((((this->accessFlags) & (8)) != 0) ? (1) : (0))) != 0);
		this->type = temp_003B->getCppType().getValue();
		return;
	}

	void CppField::generateHeader(Pointer<IndentedOutputStream> header, Pointer<String> newType)
	{
		UsageCounterMaintainer maintainer(this, true);

		int mask_0060 = 0;
		Pointer<StringBuilder> temp_007A;
		Pointer<StringBuilder> temp_00A8;
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (16384)) == 0) ? (1) : (0))) != 0, createString("Enum field not supported"));
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (4096)) == 0) ? (1) : (0))) != 0, createString("Synthetic field not supported"));
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (128)) == 0) ? (1) : (0))) != 0, createString("Transient field not supported"));
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (64)) == 0) ? (1) : (0))) != 0, createString("Volatile field not supported"));
		if (((this->accessFlags) & (8)) == 0)
			goto L009C;
		mask_0060 = -32;
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (mask_0060)) == 0) ? (1) : (0))) != 0, createString("Static field with other flags not supported"));
		temp_007A = new StringBuilder(createString("static "));
		Statics::__ClassInit();
		header->iprintln(temp_007A->append(Statics::addPointerIfNeeded(newType))->append(createString(" "))->append(this->name)->append(createString(";"))->toString());
		return;
	L009C: //
		Statics::__ClassInit();
		String::__ClassInit();
		temp_00A8 = new StringBuilder(String::valueOf(Statics::addPointerIfNeeded(newType).getValue()));
		header->iprintln(temp_00A8->append(createString(" "))->append(this->name)->append(createString(";"))->toString());
		return;
	}

	bool CppField::generateSource(Pointer<IndentedOutputStream> source, Pointer<String> className, Pointer<String> newType)
	{
		UsageCounterMaintainer maintainer(this, true);

		int mask_0061 = 0;
		Pointer<String> initializer_0079;
		Pointer<Constant> constant_0089;
		Pointer<String> value_0091;
		Pointer<String> local_0093;
		Pointer<ConstantInteger> temp_00DB;
		Pointer<StringBuilder> temp_00FB;
		Pointer<ConstantStringInfo> temp_0100;
		Pointer<StringBuilder> temp_011D;
		Pointer<StringBuilder> temp_0138;
		Pointer<StringBuilder> temp_0151;
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (16384)) == 0) ? (1) : (0))) != 0, createString("Enum field not supported"));
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (4096)) == 0) ? (1) : (0))) != 0, createString("Synthetic field not supported"));
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (128)) == 0) ? (1) : (0))) != 0, createString("Transient field not supported"));
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (64)) == 0) ? (1) : (0))) != 0, createString("Volatile field not supported"));
		if (((this->accessFlags) & (8)) == 0)
			goto L017B;
		mask_0061 = -32;
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (mask_0061)) == 0) ? (1) : (0))) != 0, createString("Static field with other flags not supported"));
		initializer_0079 = createString("");
		if ((this->attributeConstantValue).getValue() == nullptr)
			goto L0145;
		constant_0089 = this->attributeConstantValue->getConstant();
		initializer_0079 = createString(" = ");
		value_0091 = createString("");
		local_0093 = newType;
		switch (newType->hashCode())
		{
		case (int)0x943A4C31:
			goto L00B4;
		case (int)0x000197EF:
			goto L00C1;
		default:
			goto L0116;
		}
	L00B4: //
		if (local_0093->equals(createString("String")))
			goto L00E9;
		goto L0116;
	L00C1: //
		if (local_0093->equals(createString("int")))
			goto L00CE;
		goto L0116;
	L00CE: //
		Statics::__ClassInit();
		Statics::Assert(constant_0089->is(3), createString("Int: Int expected"));
		temp_00DB = (ConstantInteger*)((constant_0089).getValue());
		temp_00DB->checkCast(ConstantInteger::__thisClassStatic);
		String::__ClassInit();
		value_0091 = String::valueOf(temp_00DB->getValue());
		goto L012F;
	L00E9: //
		Statics::__ClassInit();
		Statics::Assert(constant_0089->is(8), createString("String: StringInfo expected"));
		temp_00FB = new StringBuilder(createString("createString(\""));
		temp_0100 = (ConstantStringInfo*)((constant_0089).getValue());
		temp_0100->checkCast(ConstantStringInfo::__thisClassStatic);
		value_0091 = temp_00FB->append(temp_0100->getString())->append(createString("\")"))->toString();
		goto L012F;
	L0116: //
		temp_011D = new StringBuilder(createString("Unsupported final type \'"));
		Statics::__ClassInit();
		Statics::Assert(false, temp_011D->append(newType)->append(createString("\'"))->toString());
	L012F: //
		String::__ClassInit();
		temp_0138 = new StringBuilder(String::valueOf(initializer_0079.getValue()));
		initializer_0079 = temp_0138->append(value_0091)->toString();
	L0145: //
		Statics::__ClassInit();
		String::__ClassInit();
		temp_0151 = new StringBuilder(String::valueOf(Statics::addPointerIfNeeded(newType).getValue()));
		source->iprintln(temp_0151->append(createString(" "))->append(className)->append(createString("::"))->append(this->name)->append(initializer_0079)->append(createString(";"))->toString());
		return 1;
	L017B: //
		return 0;
	}

	Pointer<String> CppField::getName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->name;
	}

	Pointer<String> CppField::getType()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->type;
	}

	bool CppField::isFinal()
	{
		UsageCounterMaintainer maintainer(this, true);

		if (((this->accessFlags) & (16)) == 0)
			goto L000C;
		return 1;
	L000C: //
		return 0;
	}

	bool CppField::isPresentInSource()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<RuntimeException> temp_0011;
		if (((this->accessFlags) & (4096)) == 0)
			goto L0015;
		temp_0011 = new RuntimeException(createString("Synthetic field not supported"));
		throw temp_0011;
	L0015: //
		return 1;
	}

	bool CppField::isStatic()
	{
		UsageCounterMaintainer maintainer(this, true);

		if (((this->accessFlags) & (8)) == 0)
			goto L000C;
		return 1;
	L000C: //
		return 0;
	}

}
