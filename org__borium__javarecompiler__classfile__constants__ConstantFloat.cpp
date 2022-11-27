#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantFloat.h"
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

	Pointer<Class> ConstantFloat::__thisClassStatic;

	void ConstantFloat::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantFloat",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantFloat::ConstantFloat() :
		Constant() //
		, value(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	void ConstantFloat::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Float: "));
		stream->print(temp_0007->append(this->value)->toString());
		return;
	}

	double ConstantFloat::getValue()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->value;
	}

	void ConstantFloat::read(Pointer<ByteInputStream> in)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->tag = 4;
		this->value = in->f4();
		return;
	}

	bool ConstantFloat::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
	{
		UsageCounterMaintainer maintainer(this, true);

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
