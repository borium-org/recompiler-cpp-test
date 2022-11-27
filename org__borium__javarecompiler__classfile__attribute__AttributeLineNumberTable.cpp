#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeLineNumberTable.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> AttributeLineNumberTable::__thisClassStatic;

	void AttributeLineNumberTable::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::AttributeLineNumberTable",
			org::borium::javarecompiler::classfile::ClassAttribute::__thisClassStatic);

		org::borium::javarecompiler::classfile::ClassAttribute::__ClassInit();
	}

	AttributeLineNumberTable::AttributeLineNumberTable(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp) :
		ClassAttribute(attribute) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->decode(cp);
		return;
	}

	void AttributeLineNumberTable::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_001F = 0;
		Pointer<StringBuilder> temp_0007;
		Pointer<StringBuilder> temp_002B;
		temp_0007 = new StringBuilder(createString("Line Numbers: "));
		stream->iprintln(temp_0007->append(this->startPc->length)->toString());
		stream->indent(1);
		i_001F = 0;
		goto L0059;
	L0022: //
		String::__ClassInit();
		temp_002B = new StringBuilder(String::valueOf(i_001F));
		stream->iprint(temp_002B->append(createString(": Line "))->append(this->lineNumber->get(i_001F))->append(createString(" PC: "))->toString());
		stream->printHex(this->startPc->get(i_001F), 4);
		stream->println();
		i_001F += 1;
	L0059: //
		if ((i_001F) < (this->startPc->length))
			goto L0022;
		stream->indent(-1);
		return;
	}

	void AttributeLineNumberTable::decode(Pointer<ConstantPool> cp)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ByteInputStream> in_000C;
		int numberOfEntries_0011 = 0;
		int i_0022 = 0;
		Pointer<ByteInputStream> temp_0008;
		Pointer<JavaRawArray<int>> temp_0013;
		Pointer<JavaRawArray<int>> temp_001A;
		temp_0008 = new ByteInputStream(this->info);
		in_000C = temp_0008;
		numberOfEntries_0011 = in_000C->u2();
		temp_0013 = new JavaRawArray<int>(numberOfEntries_0011);
		this->startPc = temp_0013;
		temp_001A = new JavaRawArray<int>(numberOfEntries_0011);
		this->lineNumber = temp_001A;
		i_0022 = 0;
		goto L003E;
	L0025: //
		this->startPc->assign(i_0022, in_000C->u2());
		this->lineNumber->assign(i_0022, in_000C->u2());
		i_0022 += 1;
	L003E: //
		if ((i_0022) < (numberOfEntries_0011))
			goto L0025;
		in_000C->close();
		return;
	}

}
