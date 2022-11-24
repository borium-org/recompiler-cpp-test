#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInterfaceMethodrefInfo.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantNameAndTypeInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	Pointer<Class> ConstantInterfaceMethodrefInfo::__thisClassStatic;

	void ConstantInterfaceMethodrefInfo::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantInterfaceMethodrefInfo",
			org::borium::javarecompiler::classfile::constants::Constant::__thisClassStatic);

		org::borium::javarecompiler::classfile::constants::Constant::__ClassInit();
	}

	ConstantInterfaceMethodrefInfo::ConstantInterfaceMethodrefInfo() :
		Constant() //
		, classIndex(0) //
		, nameAndTypeIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	void ConstantInterfaceMethodrefInfo::dump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<StringBuilder> temp_0007;
		Pointer<StringBuilder> temp_002B;
		temp_0007 = new StringBuilder(createString("InterfaceMethodRef:  Class "));
		stream->print(temp_0007->append(this->classIndex)->append(createString(" "))->toString());
		this->classInfo->dump(stream);
		temp_002B = new StringBuilder(createString(" NameType "));
		stream->print(temp_002B->append(this->nameAndTypeIndex)->append(createString(" "))->toString());
		this->nameTypeInfo->dump(stream);
		return;
	}

	void ConstantInterfaceMethodrefInfo::fixup(Pointer<ConstantPool> constantPool)
	{
		Pointer<ConstantClassInfo> temp_0009;
		Pointer<ConstantNameAndTypeInfo> temp_0018;
		temp_0009 = (ConstantClassInfo*)((constantPool->get(this->classIndex)).getValue());
		temp_0009->checkCast(ConstantClassInfo::__thisClassStatic);
		this->classInfo = temp_0009.getValue();
		temp_0018 = (ConstantNameAndTypeInfo*)((constantPool->get(this->nameAndTypeIndex)).getValue());
		temp_0018->checkCast(ConstantNameAndTypeInfo::__thisClassStatic);
		this->nameTypeInfo = temp_0018.getValue();
		return;
	}

	void ConstantInterfaceMethodrefInfo::read(Pointer<ByteInputStream> in)
	{
		this->tag = 11;
		this->classIndex = in->u2();
		this->nameAndTypeIndex = in->u2();
		return;
	}

	bool ConstantInterfaceMethodrefInfo::verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index)
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
		if (cp->get(this->classIndex)->is(7))
			goto L0027;
		return 0;
	L0027: //
		if (cp->get(this->nameAndTypeIndex)->is(12))
			goto L0039;
		return 0;
	L0039: //
		return 1;
	}

}
