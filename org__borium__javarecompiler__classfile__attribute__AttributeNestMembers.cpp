#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeNestMembers.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> AttributeNestMembers::__thisClassStatic;

	void AttributeNestMembers::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::AttributeNestMembers",
			org::borium::javarecompiler::classfile::ClassAttribute::__thisClassStatic);

		org::borium::javarecompiler::classfile::ClassAttribute::__ClassInit();
	}

	AttributeNestMembers::AttributeNestMembers(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp) :
		ClassAttribute(attribute) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		int i_0018 = 0;
		Pointer<JavaArray<ConstantClassInfo>> temp_0010;
		Pointer<ConstantClassInfo> temp_002A;
		this->decode(cp);
		temp_0010 = new JavaArray<ConstantClassInfo>(this->classTable->length);
		this->classInfo = temp_0010;
		i_0018 = 0;
		goto L0031;
	L001B: //
		temp_002A = (ConstantClassInfo*)((cp->get(this->classTable->get(i_0018))).getValue());
		temp_002A->checkCast(ConstantClassInfo::__thisClassStatic);
		this->classInfo->assign(i_0018, temp_002A);
		i_0018 += 1;
	L0031: //
		if ((i_0018) < (this->classInfo->length))
			goto L001B;
		return;
	}

	void AttributeNestMembers::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		int i_001F = 0;
		Pointer<StringBuilder> temp_0007;
		Pointer<StringBuilder> temp_002B;
		temp_0007 = new StringBuilder(createString("Nest members: "));
		stream->iprintln(temp_0007->append(this->classTable->length)->toString());
		stream->indent(1);
		i_001F = 0;
		goto L0058;
	L0022: //
		String::__ClassInit();
		temp_002B = new StringBuilder(String::valueOf(i_001F));
		stream->iprint(temp_002B->append(createString(": "))->append(this->classTable->get(i_001F))->append(createString(" "))->toString());
		this->classInfo->get(i_001F)->dump(stream);
		stream->println();
		i_001F += 1;
	L0058: //
		if ((i_001F) < (this->classTable->length))
			goto L0022;
		stream->indent(-1);
		return;
	}

	void AttributeNestMembers::decode(Pointer<ConstantPool> cp)
	{
		Pointer<ByteInputStream> in_000C;
		int numberOfClasses_0011 = 0;
		int i_001B = 0;
		Pointer<ByteInputStream> temp_0008;
		Pointer<JavaRawArray<int>> temp_0013;
		temp_0008 = new ByteInputStream(this->info);
		in_000C = temp_0008;
		numberOfClasses_0011 = in_000C->u2();
		temp_0013 = new JavaRawArray<int>(numberOfClasses_0011);
		this->classTable = temp_0013;
		i_001B = 0;
		goto L002C;
	L001E: //
		this->classTable->assign(i_001B, in_000C->u2());
		i_001B += 1;
	L002C: //
		if ((i_001B) < (numberOfClasses_0011))
			goto L001E;
		in_000C->close();
		return;
	}

}
