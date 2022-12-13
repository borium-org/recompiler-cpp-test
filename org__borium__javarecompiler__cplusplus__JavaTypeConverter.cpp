#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__JavaTypeConverter.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__Serializable.h"
#include "java__lang__Character.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariable.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariables.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> JavaTypeConverter::__thisClassStatic;

	void JavaTypeConverter::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::JavaTypeConverter",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	JavaTypeConverter::JavaTypeConverter(Pointer<String> javaType, bool isStatic) :
		JavaTypeConverter(javaType, isStatic, (LocalVariables*) nullptr) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	JavaTypeConverter::JavaTypeConverter(Pointer<String> javaType, bool isStatic, Pointer<LocalVariables> locals) :
		Object() //
		, index(0) //
		, dimensions(0) //
		, parameterIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->javaType = javaType.getValue();
		this->cppType = createString("");
		this->index = 0;
		this->dimensions = 0;
		this->parameterIndex = ((isStatic) ? (0) : (1));
		this->locals = locals.getValue();
		return;
	}

	Pointer<String> JavaTypeConverter::getCppType()
	{
		UsageCounterMaintainer maintainer(this, true);

		if (!(this->javaType->startsWith(createString("("))))
			goto L0013;
		this->parseMethod();
		goto L0018;
	L0013: //
		this->parseSingleType(false);
	L0018: //
		return this->cppType;
	}

	Pointer<JavaArray<String>> JavaTypeConverter::parseParameterTypes()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ArrayList<String>> parameterTypes_0016;
		Pointer<ArrayList<Object>> temp_0012;
		Pointer<JavaArray<String>> temp_004C;
		Pointer<JavaArray<String>> temp_0052;
		Statics::__ClassInit();
		Statics::Assert(this->javaType->startsWith(createString("(")), createString("Need a method signature"));
		temp_0012 = new ArrayList<Object>();
		parameterTypes_0016 = (ArrayList<String>*)(temp_0012.getValue());
		this->index = (this->index) + (1);
		goto L0037;
	L0023: //
		this->cppType = createString("");
		this->parseSingleType(false);
		parameterTypes_0016->add(this->cppType.getValue());
	L0037: //
		if ((this->javaType->charAt(this->index)) != (41))
			goto L0023;
		temp_004C = new JavaArray<String>(parameterTypes_0016->size());
		temp_0052 = (JavaArray<String>*)((parameterTypes_0016->toArray(temp_004C.getValue())).getValue());
		temp_0052->checkCast(JavaArray<String>::__thisClassStatic);
		return temp_0052;
	}

	void JavaTypeConverter::parseClass()
	{
		UsageCounterMaintainer maintainer(this, true);

		int count_00A0 = 0;
		Pointer<StringBuilder> temp_0010;
		Pointer<StringBuilder> temp_0086;
		Pointer<StringBuilder> temp_00B4;
		Pointer<StringBuilder> temp_00E7;
		goto L0049;
	L0003: //
		String::__ClassInit();
		temp_0010 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		Character::__ClassInit();
		this->cppType = temp_0010->append((((this->javaType->charAt(this->index)) == (47)) ? (((Pointer<String>) new String("::"))) : (Character::valueOf(this->javaType->charAt(this->index)))).getValue())->toString().getValue();
		this->index = (this->index) + (1);
	L0049: //
		if ((this->javaType->charAt(this->index)) == (59))
			goto L0069;
		if ((this->javaType->charAt(this->index)) != (60))
			goto L0003;
	L0069: //
		if ((this->javaType->charAt(this->index)) != (60))
			goto L00FF;
		String::__ClassInit();
		temp_0086 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_0086->append('<')->toString().getValue();
		this->index = (this->index) + (1);
		count_00A0 = 0;
		goto L00CA;
	L00A3: //
		if ((count_00A0) <= 0)
			goto L00C2;
		String::__ClassInit();
		temp_00B4 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_00B4->append(createString(", "))->toString().getValue();
	L00C2: //
		this->parseSingleType(false);
		count_00A0 += 1;
	L00CA: //
		if ((this->javaType->charAt(this->index)) != (62))
			goto L00A3;
		String::__ClassInit();
		temp_00E7 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_00E7->append('>')->toString().getValue();
		this->index = (this->index) + (1);
	L00FF: //
		if ((this->javaType->charAt(this->index)) != (59))
			goto L0119;
		this->index = (this->index) + (1);
	L0119: //
		return;
	}

	void JavaTypeConverter::parseMethod()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> separator_0013;
		Pointer<StringBuilder> temp_0023;
		Pointer<StringBuilder> temp_0055;
		this->cppType = createString("(");
		this->index = (this->index) + (1);
		separator_0013 = createString("");
		goto L0038;
	L0016: //
		String::__ClassInit();
		temp_0023 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_0023->append(separator_0013)->toString().getValue();
		separator_0013 = createString(", ");
		this->parseSingleType(true);
	L0038: //
		if ((this->javaType->charAt(this->index)) != (41))
			goto L0016;
		String::__ClassInit();
		temp_0055 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_0055->append(createString(")"))->toString().getValue();
		this->index = (this->index) + (1);
		this->parseSingleType(false);
		return;
	}

	void JavaTypeConverter::parseSingleType(bool addParameter)
	{
		UsageCounterMaintainer maintainer(this, true);

		int oldPos_002F = 0;
		bool rawArray_0031 = false;
		Pointer<LocalVariable> local_02F0;
		Pointer<String> name_0312;
		Pointer<StringBuilder> temp_00B5;
		Pointer<StringBuilder> temp_00DD;
		Pointer<StringBuilder> temp_0105;
		Pointer<StringBuilder> temp_012D;
		Pointer<StringBuilder> temp_0155;
		Pointer<StringBuilder> temp_017D;
		Pointer<StringBuilder> temp_01A5;
		Pointer<StringBuilder> temp_01CD;
		Pointer<StringBuilder> temp_021B;
		Pointer<StringBuilder> temp_0254;
		Pointer<StringBuilder> temp_0291;
		Pointer<StringBuilder> temp_0303;
		Pointer<StringBuilder> temp_031F;
		goto L0017;
	L0003: //
		this->dimensions = (this->dimensions) + (1);
		this->index = (this->index) + (1);
	L0017: //
		if ((this->javaType->charAt(this->index)) == (91))
			goto L0003;
		oldPos_002F = this->cppType->length();
		rawArray_0031 = 1;
		switch (this->javaType->charAt(this->index))
		{
		case (int)0x0000003C:
			goto L0236;
		case (int)0x00000042:
			goto L00A8;
		case (int)0x00000043:
			goto L00D0;
		case (int)0x00000044:
			goto L00F8;
		case (int)0x00000046:
			goto L0120;
		case (int)0x00000049:
			goto L0148;
		case (int)0x0000004A:
			goto L0170;
		case (int)0x0000004C:
			goto L01E8;
		case (int)0x00000053:
			goto L0198;
		case (int)0x00000054:
			goto L01FB;
		case (int)0x00000056:
			goto L020E;
		case (int)0x0000005A:
			goto L01C0;
		default:
			goto L024D;
		}
	L00A8: //
		String::__ClassInit();
		temp_00B5 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_00B5->append(createString("byte"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L00D0: //
		String::__ClassInit();
		temp_00DD = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_00DD->append(createString("char"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L00F8: //
		String::__ClassInit();
		temp_0105 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_0105->append(createString("double"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L0120: //
		String::__ClassInit();
		temp_012D = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_012D->append(createString("float"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L0148: //
		String::__ClassInit();
		temp_0155 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_0155->append(createString("int"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L0170: //
		String::__ClassInit();
		temp_017D = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_017D->append(createString("INT64"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L0198: //
		String::__ClassInit();
		temp_01A5 = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_01A5->append(createString("short"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L01C0: //
		String::__ClassInit();
		temp_01CD = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_01CD->append(createString("bool"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L01E8: //
		rawArray_0031 = 0;
		this->index = (this->index) + (1);
		this->parseClass();
		goto L02CC;
	L01FB: //
		rawArray_0031 = 0;
		this->index = (this->index) + (1);
		this->parseClass();
		goto L02CC;
	L020E: //
		String::__ClassInit();
		temp_021B = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_021B->append(createString("void"))->toString().getValue();
		this->index = (this->index) + (1);
		goto L02CC;
	L0236: //
		rawArray_0031 = 0;
		this->index = (this->index) + (1);
		this->removeTemplateArguments();
		this->parseMethod();
		goto L02CC;
	L024D: //
		temp_0254 = new StringBuilder(createString("Unhandled type "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_0254->append(this->javaType->charAt(this->index))->toString());
		goto L02CC;
	L026E: //
		Statics::__ClassInit();
		Statics::Assert(((((this->dimensions) == (1)) ? (1) : (0))) != 0, createString("Dimensions more than 1 not supported yet"));
		String::__ClassInit();
		temp_0291 = new StringBuilder(String::valueOf(this->cppType->substring(0, oldPos_002F).getValue()));
		this->cppType = temp_0291->append(createString("Java"))->append(((rawArray_0031) ? (((Pointer<String>) new String("Raw"))) : (((Pointer<String>) new String("")))))->append(createString("Array<"))->append(this->cppType->substring(oldPos_002F))->append(createString(">"))->toString().getValue();
		this->dimensions = (this->dimensions) - (1);
	L02CC: //
		if ((this->dimensions) > 0)
			goto L026E;
		if (!(addParameter))
			goto L033C;
		local_02F0 = (((this->locals).getValue() != nullptr) ? (this->locals->get(this->parameterIndex, (Instruction*) nullptr)) : ((LocalVariable*)nullptr));
		temp_0303 = new StringBuilder(createString("param"));
		name_0312 = (((local_02F0).getValue() != nullptr) ? (local_02F0->getName()) : (temp_0303->append(this->parameterIndex)->toString()));
		String::__ClassInit();
		temp_031F = new StringBuilder(String::valueOf(this->cppType.getValue()));
		this->cppType = temp_031F->append(createString(" "))->append(name_0312)->toString().getValue();
		this->parameterIndex = (this->parameterIndex) + (1);
	L033C: //
		return;
	}

	void JavaTypeConverter::removeTemplateArguments()
	{
		UsageCounterMaintainer maintainer(this, true);

		int brackets_0002 = 0;
		brackets_0002 = 1;
		goto L003F;
	L0005: //
		switch (this->javaType->charAt(this->index))
		{
		case 60:
			goto L002C;
		case 61:
			goto L0035;
		case 62:
			goto L0032;
		default:
			goto L0035;
		}
	L002C: //
		brackets_0002 += 1;
		goto L0035;
	L0032: //
		brackets_0002 += -1;
	L0035: //
		this->index = (this->index) + (1);
	L003F: //
		if ((brackets_0002) > 0)
			goto L0005;
		return;
	}

}
