#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeSourceFile.h"
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

	Pointer<Class> AttributeSourceFile::__thisClassStatic;

	void AttributeSourceFile::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::AttributeSourceFile",
			org::borium::javarecompiler::classfile::ClassAttribute::__thisClassStatic);

		org::borium::javarecompiler::classfile::ClassAttribute::__ClassInit();
	}

	AttributeSourceFile::AttributeSourceFile(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp) :
		ClassAttribute(attribute) //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->decode(cp);
		this->sourceFile = cp->getString(this->index).getValue();
		return;
	}

	void AttributeSourceFile::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Source File: "));
		stream->iprintln(temp_0007->append(this->sourceFile)->toString());
		return;
	}

	void AttributeSourceFile::decode(Pointer<ConstantPool> cp)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ByteInputStream> in_000C;
		Pointer<ByteInputStream> temp_0008;
		temp_0008 = new ByteInputStream(this->info);
		in_000C = temp_0008;
		this->index = in_000C->u2();
		in_000C->close();
		return;
	}

}
