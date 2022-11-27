#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeConstantValue.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> AttributeConstantValue::__thisClassStatic;

	void AttributeConstantValue::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::AttributeConstantValue",
			org::borium::javarecompiler::classfile::ClassAttribute::__thisClassStatic);

		org::borium::javarecompiler::classfile::ClassAttribute::__ClassInit();
	}

	AttributeConstantValue::AttributeConstantValue(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp) :
		ClassAttribute(attribute) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->decode(cp);
		return;
	}

	Pointer<Constant> AttributeConstantValue::getConstant()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->constantValue;
	}

	void AttributeConstantValue::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		stream->iprintln(createString("ConstantValue:"));
		stream->indent(1);
		stream->iprint(createString(""));
		this->constantValue->dump(stream);
		stream->println();
		stream->indent(-1);
		return;
	}

	void AttributeConstantValue::decode(Pointer<ConstantPool> cp)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ByteInputStream> in_000C;
		int constantIndex_0011 = 0;
		Pointer<ByteInputStream> temp_0008;
		temp_0008 = new ByteInputStream(this->info);
		in_000C = temp_0008;
		constantIndex_0011 = in_000C->u2();
		in_000C->close();
		this->constantValue = cp->get(constantIndex_0011).getValue();
		return;
	}

}
