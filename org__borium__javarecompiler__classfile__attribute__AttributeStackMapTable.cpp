#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeStackMapTable.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__attribute__StackMapFrame.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> AttributeStackMapTable::__thisClassStatic;

	void AttributeStackMapTable::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::AttributeStackMapTable",
			org::borium::javarecompiler::classfile::ClassAttribute::__thisClassStatic);

		org::borium::javarecompiler::classfile::ClassAttribute::__ClassInit();
	}

	AttributeStackMapTable::AttributeStackMapTable(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp) :
		ClassAttribute(attribute) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->decode(cp);
		return;
	}

	void AttributeStackMapTable::decode(Pointer<ConstantPool> cp)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ByteInputStream> in_000C;
		int numberOfEntries_0011 = 0;
		int i_001C = 0;
		Pointer<ByteInputStream> temp_0008;
		Pointer<JavaArray<StackMapFrame>> temp_0013;
		Pointer<StackMapFrame> temp_002A;
		temp_0008 = new ByteInputStream(this->info);
		in_000C = temp_0008;
		numberOfEntries_0011 = in_000C->u2();
		temp_0013 = new JavaArray<StackMapFrame>(numberOfEntries_0011);
		this->stackMapEntries = temp_0013;
		i_001C = 0;
		goto L0031;
	L001F: //
		temp_002A = new StackMapFrame(in_000C);
		this->stackMapEntries->assign(i_001C, temp_002A);
		i_001C += 1;
	L0031: //
		if ((i_001C) < (numberOfEntries_0011))
			goto L001F;
		in_000C->close();
		return;
	}

}
