#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantDynamic.h"
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

	Pointer<Class> ConstantDynamic::__thisClassStatic;

	void ConstantDynamic::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantDynamic",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantDynamic::ConstantDynamic() :
		Constant() //
		, bootstrapMethodAttrIndex(0) //
		, nameAndTypeIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantDynamic::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Dynamic: Bootstrap "));
		stream->println(temp_0007->append(this->bootstrap)->append(createString(" Name and type "))->append(this->nameAndType)->toString());
		return;
	}

	void ConstantDynamic::fixup(Pointer<ConstantPool> constantPool)
	{
		this->bootstrap = constantPool->getString(this->bootstrapMethodAttrIndex).getValue();
		this->nameAndType = constantPool->getString(this->nameAndTypeIndex).getValue();
		return;
	}

	void ConstantDynamic::read(Pointer<ByteInputStream> in)
	{
		this->tag = 17;
		this->bootstrapMethodAttrIndex = in->u2();
		this->nameAndTypeIndex = in->u2();
		return;
	}

	bool ConstantDynamic::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
	{
		if ((majorVersion) < (55))
			goto L000A;
		if ((minorVersion) == 0)
			goto L000C;
	L000A: //
		return 0;
	L000C: //
		return 1;
	}

}
