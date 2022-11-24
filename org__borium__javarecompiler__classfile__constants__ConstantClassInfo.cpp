#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
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

	Pointer<Class> ConstantClassInfo::__thisClassStatic;

	void ConstantClassInfo::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantClassInfo",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantClassInfo::ConstantClassInfo() :
		Constant() //
		, nameIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantClassInfo::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("ClassInfo: "));
		stream->print(temp_0007->append(this->nameIndex)->append(createString(" "))->append(this->name)->toString());
		return;
	}

	Pointer<String> ConstantClassInfo::getName()
	{
		return this->name;
	}

	Pointer<String> ConstantClassInfo::getValue()
	{
		return this->name;
	}

	void ConstantClassInfo::fixup(Pointer<ConstantPool> constantPool)
	{
		this->name = constantPool->getString(this->nameIndex).getValue();
		return;
	}

	void ConstantClassInfo::read(Pointer<ByteInputStream> in)
	{
		this->tag = 7;
		this->nameIndex = in->u2();
		return;
	}

	bool ConstantClassInfo::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
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
		return cp->get(this->nameIndex)->is(1);
	}

}
