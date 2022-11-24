#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantDouble.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Double.h"
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

	Pointer<Class> ConstantDouble::__thisClassStatic;

	void ConstantDouble::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantDouble",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantDouble::ConstantDouble() :
		Constant() //
		, value(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantDouble::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("Double: "));
		stream->print(temp_0007->append(this->value)->toString());
		return;
	}

	Pointer<String> ConstantDouble::getValue()
	{
		Double::__ClassInit();
		return Double::toString(this->value);
	}

	void ConstantDouble::read(Pointer<ByteInputStream> in)
	{
		this->tag = 6;
		this->value = in->f8();
		return;
	}

	bool ConstantDouble::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
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
		if ((cp->get((index) + (1))).getValue() == nullptr)
			goto L0022;
		return 0;
	L0022: //
		return 1;
	}

}
