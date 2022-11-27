#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ClassAttribute.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeCode.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeConstantValue.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeExceptions.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeInnerClasses.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeLineNumberTable.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeLocalVariableTable.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeLocalVariableTypeTable.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeNestMembers.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeSignature.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeSourceFile.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeStackMapTable.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ClassAttribute::__thisClassStatic;

	void ClassAttribute::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ClassAttribute",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	Pointer<ClassAttribute> ClassAttribute::readAttribute(Pointer<ByteInputStream> in, Pointer<ConstantPool> constants)
	{
		__ClassInit();

		Pointer<ClassAttribute> attribute_0008;
		Pointer<ClassAttribute> temp_0004;
		Pointer<String> local_0013;
		Pointer<AttributeCode> temp_0102;
		Pointer<AttributeConstantValue> temp_010C;
		Pointer<AttributeExceptions> temp_0116;
		Pointer<AttributeInnerClasses> temp_0120;
		Pointer<AttributeNestMembers> temp_012A;
		Pointer<AttributeSignature> temp_0134;
		Pointer<AttributeSourceFile> temp_013E;
		Pointer<AttributeLocalVariableTable> temp_0148;
		Pointer<AttributeLineNumberTable> temp_0152;
		Pointer<AttributeLocalVariableTypeTable> temp_015C;
		Pointer<AttributeStackMapTable> temp_0166;
		temp_0004 = new ClassAttribute();
		attribute_0008 = temp_0004;
		attribute_0008->read(in, constants);
		local_0013 = attribute_0008->attributeName;
		switch (attribute_0008->attributeName->hashCode())
		{
		case (int)0x8AB1940D:
			goto L0078;
		case (int)0xB76FB898:
			goto L0084;
		case (int)0xBA85EE5A:
			goto L0090;
		case (int)0x0020220D:
			goto L009C;
		case (int)0x0735AB81:
			goto L00A8;
		case (int)0x2697F98D:
			goto L00B4;
		case (int)0x287C1624:
			goto L00C0;
		case (int)0x348C2857:
			goto L00CC;
		case (int)0x64C75927:
			goto L00D8;
		case (int)0x653F0551:
			goto L00E4;
		case (int)0x7ADB2910:
			goto L00F0;
		default:
			goto L016A;
		}
	L0078: //
		if (local_0013->equals(createString("ConstantValue")))
			goto L0106;
		goto L016A;
	L0084: //
		if (local_0013->equals(createString("Signature")))
			goto L012E;
		goto L016A;
	L0090: //
		if (local_0013->equals(createString("StackMapTable")))
			goto L0160;
		goto L016A;
	L009C: //
		if (local_0013->equals(createString("Code")))
			goto L00FC;
		goto L016A;
	L00A8: //
		if (local_0013->equals(createString("NestMembers")))
			goto L0124;
		goto L016A;
	L00B4: //
		if (local_0013->equals(createString("LocalVariableTypeTable")))
			goto L0156;
		goto L016A;
	L00C0: //
		if (local_0013->equals(createString("Exceptions")))
			goto L0110;
		goto L016A;
	L00CC: //
		if (local_0013->equals(createString("SourceFile")))
			goto L0138;
		goto L016A;
	L00D8: //
		if (local_0013->equals(createString("LocalVariableTable")))
			goto L0142;
		goto L016A;
	L00E4: //
		if (local_0013->equals(createString("LineNumberTable")))
			goto L014C;
		goto L016A;
	L00F0: //
		if (local_0013->equals(createString("InnerClasses")))
			goto L011A;
		goto L016A;
	L00FC: //
		temp_0102 = new AttributeCode(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_0102.getValue();
	L0106: //
		temp_010C = new AttributeConstantValue(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_010C.getValue();
	L0110: //
		temp_0116 = new AttributeExceptions(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_0116.getValue();
	L011A: //
		temp_0120 = new AttributeInnerClasses(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_0120.getValue();
	L0124: //
		temp_012A = new AttributeNestMembers(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_012A.getValue();
	L012E: //
		temp_0134 = new AttributeSignature(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_0134.getValue();
	L0138: //
		temp_013E = new AttributeSourceFile(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_013E.getValue();
	L0142: //
		temp_0148 = new AttributeLocalVariableTable(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_0148.getValue();
	L014C: //
		temp_0152 = new AttributeLineNumberTable(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_0152.getValue();
	L0156: //
		temp_015C = new AttributeLocalVariableTypeTable(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_015C.getValue();
	L0160: //
		temp_0166 = new AttributeStackMapTable(attribute_0008, constants);
		// ARETURN: Type mismatch
		return temp_0166.getValue();
	L016A: //
		return attribute_0008;
	}

	ClassAttribute::ClassAttribute(Pointer<ClassAttribute> attribute) :
		Object() //
		, attributeNameIndex(0) //
		, attributeLength(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->attributeNameIndex = attribute->attributeNameIndex;
		this->attributeLength = attribute->attributeLength;
		this->attributeName = attribute->attributeName.getValue();
		this->info = attribute->info;
		return;
	}

	ClassAttribute::ClassAttribute() :
		Object() //
		, attributeNameIndex(0) //
		, attributeLength(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	void ClassAttribute::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		Pointer<StringBuilder> temp_0023;
		temp_0007 = new StringBuilder(createString("Attribute: "));
		stream->println(temp_0007->append(this->attributeName)->toString());
		stream->indent(1);
		temp_0023 = new StringBuilder(createString("Data Length: "));
		stream->iprintln(temp_0023->append(this->attributeLength)->toString());
		stream->indent(1);
		stream->iprintln(this->info);
		stream->indent(-1);
		this->detailedDump(stream);
		stream->indent(-1);
		return;
	}

	Pointer<String> ClassAttribute::getName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->attributeName;
	}

	void ClassAttribute::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Attribute "));
		stream->iprintln(temp_0007->append(this->attributeName)->append(createString(": Detailed dump not implemented"))->toString());
		return;
	}

	void ClassAttribute::read(Pointer<ByteInputStream> in, Pointer<ConstantPool> constants)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->attributeNameIndex = in->u2();
		this->attributeLength = in->u4();
		this->info = in->read(this->attributeLength);
		this->attributeName = constants->getString(this->attributeNameIndex).getValue();
		return;
	}

}
