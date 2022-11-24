#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantMethodType.h"
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

namespace org::borium::javarecompiler::classfile::constants
{

	Pointer<Class> ConstantMethodType::__thisClassStatic;

	void ConstantMethodType::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantMethodType",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantMethodType::ConstantMethodType() :
		Constant() //
		, descriptorIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantMethodType::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("MethodType: "));
		stream->println(temp_0007->append(this->descriptor)->toString());
		return;
	}

	void ConstantMethodType::fixup(Pointer<ConstantPool> constantPool)
	{
		this->descriptor = constantPool->getString(this->descriptorIndex).getValue();
		return;
	}

	void ConstantMethodType::read(Pointer<ByteInputStream> in)
	{
		this->tag = 16;
		this->descriptorIndex = in->u2();
		return;
	}

	bool ConstantMethodType::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
	{
		if ((majorVersion) < (51))
			goto L000A;
		if ((minorVersion) == 0)
			goto L000C;
	L000A: //
		return 0;
	L000C: //
		if (cp->get(this->descriptorIndex)->is(1))
			goto L001D;
		return 0;
	L001D: //
		return 1;
	}

}
