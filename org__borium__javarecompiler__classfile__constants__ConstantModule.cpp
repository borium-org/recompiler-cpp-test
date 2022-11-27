#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantModule.h"
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

	Pointer<Class> ConstantModule::__thisClassStatic;

	void ConstantModule::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantModule",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantModule::ConstantModule() :
		Constant() //
		, nameIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	void ConstantModule::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Module: "));
		stream->println(temp_0007->append(this->name)->toString());
		return;
	}

	void ConstantModule::fixup(Pointer<ConstantPool> constantPool)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->name = constantPool->getString(this->nameIndex).getValue();
		return;
	}

	void ConstantModule::read(Pointer<ByteInputStream> in)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->tag = 19;
		this->nameIndex = in->u2();
		return;
	}

	bool ConstantModule::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		if ((majorVersion) < (53))
			goto L000A;
		if ((minorVersion) == 0)
			goto L000C;
	L000A: //
		return 0;
	L000C: //
		return 1;
	}

}
