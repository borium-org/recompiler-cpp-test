#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantMethodHandle.h"
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

	Pointer<Class> ConstantMethodHandle::__thisClassStatic;

	void ConstantMethodHandle::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantMethodHandle",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantMethodHandle::ConstantMethodHandle() :
		Constant() //
		, referenceKind(0) //
		, referenceIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantMethodHandle::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("MethodHandle: Kind "));
		stream->println(temp_0007->append(this->referenceKind)->append(createString(" Index "))->append(this->referenceIndex)->toString());
		return;
	}

	void ConstantMethodHandle::read(Pointer<ByteInputStream> in)
	{
		this->tag = 15;
		this->referenceKind = in->u1();
		this->referenceIndex = in->u2();
		return;
	}

	bool ConstantMethodHandle::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
	{
		if ((majorVersion) < (51))
			goto L000A;
		if ((minorVersion) == 0)
			goto L000C;
	L000A: //
		return 0;
	L000C: //
		return 1;
	}

}
