#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__InnerClass.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> InnerClass::__thisClassStatic;

	void InnerClass::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::InnerClass",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	InnerClass::InnerClass(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		Object() //
		, innerClassInfoIndex(0) //
		, outerClassInfoIndex(0) //
		, innerClassNameIndex(0) //
		, innerClassAccessFlags(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<ConstantClassInfo> temp_002D;
		Pointer<ConstantClassInfo> temp_004B;
		this->innerClassInfoIndex = in->u2();
		this->outerClassInfoIndex = in->u2();
		this->innerClassNameIndex = in->u2();
		this->innerClassAccessFlags = in->u2();
		temp_002D = (ConstantClassInfo*)((cp->get(this->outerClassInfoIndex)).getValue());
		temp_002D->checkCast(ConstantClassInfo::__thisClassStatic);
		this->outer = temp_002D.getValue();
		this->outerName = cp->getString(this->outer->nameIndex).getValue();
		temp_004B = (ConstantClassInfo*)((cp->get(this->innerClassInfoIndex)).getValue());
		temp_004B->checkCast(ConstantClassInfo::__thisClassStatic);
		this->inner = temp_004B.getValue();
		this->innerName = cp->getString(this->inner->nameIndex).getValue();
		this->innerClassName = cp->getString(this->innerClassNameIndex).getValue();
		return;
	}

	void InnerClass::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int flags_0055 = 0;
		Pointer<StringBuilder> temp_000C;
		Pointer<StringBuilder> temp_0023;
		Pointer<StringBuilder> temp_003A;
		stream->indent(1);
		temp_000C = new StringBuilder(createString("Outer: "));
		stream->iprintln(temp_000C->append(this->outerName)->toString());
		temp_0023 = new StringBuilder(createString("Inner: "));
		stream->iprintln(temp_0023->append(this->innerName)->toString());
		temp_003A = new StringBuilder(createString("Name: "));
		stream->iprintln(temp_003A->append(this->innerClassName)->toString());
		stream->iprint(createString("Access: "));
		flags_0055 = this->innerClassAccessFlags;
		stream->printHex(flags_0055, 4);
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 16384, createString(" Enum"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 8192, createString(" Annotation"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 4096, createString(" Synthetic"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 1024, createString(" Abstract"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 512, createString(" Interface"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 16, createString(" Final"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 8, createString(" Static"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 4, createString(" Protected"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 2, createString(" Private"));
		ClassFile::__ClassInit();
		flags_0055 = ClassFile::printAccessFlag(stream, flags_0055, 1, createString(" Public"));
		if ((flags_0055) == 0)
			goto L00D1;
		stream->print(createString(" Invalid "));
		stream->printHex(flags_0055, 4);
	L00D1: //
		stream->println();
		stream->indent(-1);
		return;
	}

}
