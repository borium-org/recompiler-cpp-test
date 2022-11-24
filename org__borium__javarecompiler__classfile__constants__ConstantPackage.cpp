#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPackage.h"
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

	Pointer<Class> ConstantPackage::__thisClassStatic;

	void ConstantPackage::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantPackage",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantPackage::ConstantPackage() :
		Constant() //
		, nameIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantPackage::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Package: "));
		stream->println(temp_0007->append(this->name)->toString());
		return;
	}

	void ConstantPackage::fixup(Pointer<ConstantPool> constantPool)
	{
		this->name = constantPool->getString(this->nameIndex).getValue();
		return;
	}

	void ConstantPackage::read(Pointer<ByteInputStream> in)
	{
		this->tag = 20;
		this->nameIndex = in->u2();
		return;
	}

	bool ConstantPackage::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
	{
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
