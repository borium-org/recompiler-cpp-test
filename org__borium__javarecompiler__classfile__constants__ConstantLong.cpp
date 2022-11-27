#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantLong.h"
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

	Pointer<Class> ConstantLong::__thisClassStatic;

	void ConstantLong::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantLong",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantLong::ConstantLong() :
		Constant() //
		, value(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	void ConstantLong::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Long: "));
		stream->print(temp_0007->append(this->value)->toString());
		return;
	}

	void ConstantLong::read(Pointer<ByteInputStream> in)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->tag = 5;
		this->value = in->u8();
		return;
	}

	bool ConstantLong::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
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
		if ((cp->get((index) + (1))).getValue() == nullptr)
			goto L0022;
		return 0;
	L0022: //
		return 1;
	}

}
