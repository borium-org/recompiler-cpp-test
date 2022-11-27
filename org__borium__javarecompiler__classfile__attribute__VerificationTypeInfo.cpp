#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__VerificationTypeInfo.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__ClassFormatError.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> VerificationTypeInfo::__thisClassStatic;

	int VerificationTypeInfo::ITEM_Top = 0;
	int VerificationTypeInfo::ITEM_Integer = 1;
	int VerificationTypeInfo::ITEM_Float = 2;
	int VerificationTypeInfo::ITEM_Double = 3;
	int VerificationTypeInfo::ITEM_Long = 4;
	int VerificationTypeInfo::ITEM_Null = 5;
	int VerificationTypeInfo::ITEM_UninitializedThis = 6;
	int VerificationTypeInfo::ITEM_Object = 7;
	int VerificationTypeInfo::ITEM_Uninitialized = 8;

	void VerificationTypeInfo::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::VerificationTypeInfo",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	VerificationTypeInfo::VerificationTypeInfo(Pointer<ByteInputStream> in) :
		Object() //
		, tag(0) //
		, cpoolIndex(0) //
		, offset(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<ClassFormatError> temp_0053;
		Pointer<ClassFormatError> temp_005D;
		Pointer<StringBuilder> temp_0087;
		Pointer<ClassFormatError> temp_0094;
		this->tag = in->u1();
		switch (this->tag)
		{
		case 0:
			goto L0044;
		case 1:
			goto L0047;
		case 2:
			goto L004A;
		case 3:
			goto L004D;
		case 4:
			goto L0057;
		case 5:
			goto L0061;
		case 6:
			goto L0064;
		case 7:
			goto L0067;
		case 8:
			goto L0072;
		default:
			goto L007D;
		}
	L0044: //
		goto L0098;
	L0047: //
		goto L0098;
	L004A: //
		goto L0098;
	L004D: //
		temp_0053 = new ClassFormatError(createString("Unhandled double"));
		throw temp_0053;
	L0057: //
		temp_005D = new ClassFormatError(createString("Unhandled long"));
		throw temp_005D;
	L0061: //
		goto L0098;
	L0064: //
		goto L0098;
	L0067: //
		this->cpoolIndex = in->u2();
		goto L0098;
	L0072: //
		this->offset = in->u2();
		goto L0098;
	L007D: //
		temp_0087 = new StringBuilder(createString("Unrecognized stack map entry tag "));
		temp_0094 = new ClassFormatError(temp_0087->append(this->tag)->toString());
		throw temp_0094;
	L0098: //
		return;
	}

}
