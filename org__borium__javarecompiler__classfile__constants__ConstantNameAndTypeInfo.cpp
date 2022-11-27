#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantNameAndTypeInfo.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	Pointer<Class> ConstantNameAndTypeInfo::__thisClassStatic;

	void ConstantNameAndTypeInfo::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantNameAndTypeInfo",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantNameAndTypeInfo::ConstantNameAndTypeInfo() :
		Constant() //
		, nameIndex(0) //
		, descriptorIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	void ConstantNameAndTypeInfo::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("NameType: Name "));
		stream->print(temp_0007->append(this->nameIndex)->append(createString(" "))->append(this->name)->append(createString(" Descriptor "))->append(this->descriptorIndex)->append(createString(" "))->append(this->descriptor)->toString());
		return;
	}

	Pointer<String> ConstantNameAndTypeInfo::getDescriptor()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->descriptor;
	}

	Pointer<String> ConstantNameAndTypeInfo::getName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->name;
	}

	int ConstantNameAndTypeInfo::getParameterCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		Statics::__ClassInit();
		return Statics::getParameterCount(this->descriptor);
	}

	int ConstantNameAndTypeInfo::getReturnTypeCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		int pos_0020 = 0;
		Pointer<RuntimeException> temp_0012;
		Pointer<RuntimeException> temp_002B;
		if (this->descriptor->startsWith(createString("(")))
			goto L0016;
		temp_0012 = new RuntimeException(createString("Get return type for non-method"));
		throw temp_0012;
	L0016: //
		pos_0020 = this->descriptor->indexOf(41);
		if ((pos_0020) != (-1))
			goto L002F;
		temp_002B = new RuntimeException(createString("No closing \')\'"));
		throw temp_002B;
	L002F: //
		return (((this->descriptor->charAt((pos_0020) + (1))) != (86)) ? (1) : (0));
	}

	void ConstantNameAndTypeInfo::fixup(Pointer<ConstantPool> constantPool)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->name = constantPool->getString(this->nameIndex).getValue();
		this->descriptor = constantPool->getString(this->descriptorIndex).getValue();
		return;
	}

	void ConstantNameAndTypeInfo::read(Pointer<ByteInputStream> in)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->tag = 7;
		this->nameIndex = in->u2();
		this->descriptorIndex = in->u2();
		return;
	}

	bool ConstantNameAndTypeInfo::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
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
		if (cp->get(this->nameIndex)->is(1))
			goto L0026;
		return 0;
	L0026: //
		if (cp->get(this->descriptorIndex)->is(1))
			goto L0037;
		return 0;
	L0037: //
		return 1;
	}

}
