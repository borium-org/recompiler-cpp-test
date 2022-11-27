#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeSignature.h"
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

	Pointer<Class> AttributeSignature::__thisClassStatic;

	void AttributeSignature::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::AttributeSignature",
			org::borium::javarecompiler::classfile::ClassAttribute::__thisClassStatic);

		org::borium::javarecompiler::classfile::ClassAttribute::__ClassInit();
	}

	AttributeSignature::AttributeSignature(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp) :
		ClassAttribute(attribute) //
		, signatureIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->decode(cp);
		this->signature = cp->getString(this->signatureIndex).getValue();
		return;
	}

	Pointer<String> AttributeSignature::getSignature()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->signature;
	}

	void AttributeSignature::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Signature: "));
		stream->iprintln(temp_0007->append(this->signatureIndex)->append(createString(" "))->append(this->signature)->toString());
		return;
	}

	void AttributeSignature::decode(Pointer<ConstantPool> cp)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ByteInputStream> in_000C;
		Pointer<ByteInputStream> temp_0008;
		temp_0008 = new ByteInputStream(this->info);
		in_000C = temp_0008;
		this->signatureIndex = in_000C->u2();
		in_000C->close();
		return;
	}

}
