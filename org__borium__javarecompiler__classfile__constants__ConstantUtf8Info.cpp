#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantUtf8Info.h"
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

	Pointer<Class> ConstantUtf8Info::__thisClassStatic;

	void ConstantUtf8Info::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantUtf8Info",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantUtf8Info::ConstantUtf8Info() :
		Constant() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	void ConstantUtf8Info::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("UTF8: \'"));
		stream->print(temp_0007->append(this->utf8)->append(createString("\'"))->toString());
		return;
	}

	Pointer<String> ConstantUtf8Info::string()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->utf8;
	}

	void ConstantUtf8Info::read(Pointer<ByteInputStream> in)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->tag = 1;
		this->utf8 = in->utf8().getValue();
		return;
	}

	bool ConstantUtf8Info::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
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
