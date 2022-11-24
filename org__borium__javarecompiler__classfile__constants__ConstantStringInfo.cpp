#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantStringInfo.h"
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

	Pointer<Class> ConstantStringInfo::__thisClassStatic;

	void ConstantStringInfo::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantStringInfo",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantStringInfo::ConstantStringInfo() :
		Constant() //
		, stringIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantStringInfo::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("String: "));
		stream->print(temp_0007->append(this->stringIndex)->append(createString(" \'"))->append(this->string)->append(createString("\'"))->toString());
		return;
	}

	Pointer<String> ConstantStringInfo::getString()
	{
		return this->string;
	}

	Pointer<String> ConstantStringInfo::getValue(Pointer<ConstantPool> constantPool)
	{
		return constantPool->getString(this->stringIndex);
	}

	void ConstantStringInfo::fixup(Pointer<ConstantPool> constantPool)
	{
		this->string = constantPool->getString(this->stringIndex).getValue();
		return;
	}

	void ConstantStringInfo::read(Pointer<ByteInputStream> in)
	{
		this->tag = 8;
		this->stringIndex = in->u2();
		return;
	}

	bool ConstantStringInfo::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
	{
		if ((majorVersion) >= (45))
			goto L0008;
		return 0;
	L0008: //
		if ((majorVersion) != (45))
			goto L0015;
		if ((minorVersion) >= (3))
			goto L0015;
		return 0;
	L0015: //
		if (cp->get(this->stringIndex)->is(1))
			goto L0026;
		return 0;
	L0026: //
		return 1;
	}

}
