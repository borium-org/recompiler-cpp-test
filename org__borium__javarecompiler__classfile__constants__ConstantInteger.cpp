#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInteger.h"
#include "java__lang__Class.h"
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

	Pointer<Class> ConstantInteger::__thisClassStatic;

	void ConstantInteger::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantInteger",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantInteger::ConstantInteger() :
		Constant() //
		, value(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantInteger::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Integer: "));
		stream->print(temp_0007->append(this->value)->toString());
		return;
	}

	int ConstantInteger::getValue()
	{
		return this->value;
	}

	void ConstantInteger::read(Pointer<ByteInputStream> in)
	{
		this->tag = 3;
		this->value = in->u4();
		return;
	}

	bool ConstantInteger::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
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
		return 1;
	}

}
