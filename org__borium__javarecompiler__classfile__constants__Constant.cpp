#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__ClassFormatError.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantDouble.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantDynamic.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantFieldrefInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantFloat.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInteger.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInterfaceMethodrefInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantInvokeDynamic.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantLong.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantMethodHandle.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantMethodType.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantMethodrefInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantModule.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantNameAndTypeInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPackage.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantStringInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantUtf8Info.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	Pointer<Class> Constant::__thisClassStatic;

	int Constant::CONSTANT_Utf8 = 1;
	int Constant::CONSTANT_Integer = 3;
	int Constant::CONSTANT_Float = 4;
	int Constant::CONSTANT_Long = 5;
	int Constant::CONSTANT_Double = 6;
	int Constant::CONSTANT_Class = 7;
	int Constant::CONSTANT_String = 8;
	int Constant::CONSTANT_Fieldref = 9;
	int Constant::CONSTANT_Methodref = 10;
	int Constant::CONSTANT_InterfaceMethodref = 11;
	int Constant::CONSTANT_NameAndType = 12;
	int Constant::CONSTANT_MethodHandle = 15;
	int Constant::CONSTANT_MethodType = 16;
	int Constant::CONSTANT_Dynamic = 17;
	int Constant::CONSTANT_InvokeDynamic = 18;
	int Constant::CONSTANT_Module = 19;
	int Constant::CONSTANT_Package = 20;

	void Constant::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::Constant",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	Constant::Constant() :
		Object() //
		, tag(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

	Pointer<Constant> Constant::create(int tag)
	{
		__ClassInit();

		Pointer<ConstantUtf8Info> temp_0064;
		Pointer<ConstantInteger> temp_006C;
		Pointer<ConstantFloat> temp_0074;
		Pointer<ConstantLong> temp_007C;
		Pointer<ConstantDouble> temp_0084;
		Pointer<ConstantClassInfo> temp_008C;
		Pointer<ConstantStringInfo> temp_0094;
		Pointer<ConstantFieldrefInfo> temp_009C;
		Pointer<ConstantMethodrefInfo> temp_00A4;
		Pointer<ConstantInterfaceMethodrefInfo> temp_00AC;
		Pointer<ConstantNameAndTypeInfo> temp_00B4;
		Pointer<ConstantMethodHandle> temp_00BC;
		Pointer<ConstantMethodType> temp_00C4;
		Pointer<ConstantDynamic> temp_00CC;
		Pointer<ConstantInvokeDynamic> temp_00D4;
		Pointer<ConstantModule> temp_00DC;
		Pointer<ConstantPackage> temp_00E4;
		Pointer<StringBuilder> temp_00F2;
		Pointer<ClassFormatError> temp_00FC;
		switch (tag)
		{
		case 1:
			goto L0060;
		case 2:
			goto L00E8;
		case 3:
			goto L0068;
		case 4:
			goto L0070;
		case 5:
			goto L0078;
		case 6:
			goto L0080;
		case 7:
			goto L0088;
		case 8:
			goto L0090;
		case 9:
			goto L0098;
		case 10:
			goto L00A0;
		case 11:
			goto L00A8;
		case 12:
			goto L00B0;
		case 13:
			goto L00E8;
		case 14:
			goto L00E8;
		case 15:
			goto L00B8;
		case 16:
			goto L00C0;
		case 17:
			goto L00C8;
		case 18:
			goto L00D0;
		case 19:
			goto L00D8;
		case 20:
			goto L00E0;
		default:
			goto L00E8;
		}
	L0060: //
		temp_0064 = new ConstantUtf8Info();
		// ARETURN: Type mismatch
		return temp_0064.getValue();
	L0068: //
		temp_006C = new ConstantInteger();
		// ARETURN: Type mismatch
		return temp_006C.getValue();
	L0070: //
		temp_0074 = new ConstantFloat();
		// ARETURN: Type mismatch
		return temp_0074.getValue();
	L0078: //
		temp_007C = new ConstantLong();
		// ARETURN: Type mismatch
		return temp_007C.getValue();
	L0080: //
		temp_0084 = new ConstantDouble();
		// ARETURN: Type mismatch
		return temp_0084.getValue();
	L0088: //
		temp_008C = new ConstantClassInfo();
		// ARETURN: Type mismatch
		return temp_008C.getValue();
	L0090: //
		temp_0094 = new ConstantStringInfo();
		// ARETURN: Type mismatch
		return temp_0094.getValue();
	L0098: //
		temp_009C = new ConstantFieldrefInfo();
		// ARETURN: Type mismatch
		return temp_009C.getValue();
	L00A0: //
		temp_00A4 = new ConstantMethodrefInfo();
		// ARETURN: Type mismatch
		return temp_00A4.getValue();
	L00A8: //
		temp_00AC = new ConstantInterfaceMethodrefInfo();
		// ARETURN: Type mismatch
		return temp_00AC.getValue();
	L00B0: //
		temp_00B4 = new ConstantNameAndTypeInfo();
		// ARETURN: Type mismatch
		return temp_00B4.getValue();
	L00B8: //
		temp_00BC = new ConstantMethodHandle();
		// ARETURN: Type mismatch
		return temp_00BC.getValue();
	L00C0: //
		temp_00C4 = new ConstantMethodType();
		// ARETURN: Type mismatch
		return temp_00C4.getValue();
	L00C8: //
		temp_00CC = new ConstantDynamic();
		// ARETURN: Type mismatch
		return temp_00CC.getValue();
	L00D0: //
		temp_00D4 = new ConstantInvokeDynamic();
		// ARETURN: Type mismatch
		return temp_00D4.getValue();
	L00D8: //
		temp_00DC = new ConstantModule();
		// ARETURN: Type mismatch
		return temp_00DC.getValue();
	L00E0: //
		temp_00E4 = new ConstantPackage();
		// ARETURN: Type mismatch
		return temp_00E4.getValue();
	L00E8: //
		temp_00F2 = new StringBuilder(createString("Bad constant type "));
		temp_00FC = new ClassFormatError(temp_00F2->append(tag)->toString());
		throw temp_00FC;
	}

	bool Constant::is(int constantType)
	{
		if ((constantType) != (this->tag))
			goto L000A;
		return 1;
	L000A: //
		return 0;
	}

	void Constant::fixup(Pointer<ConstantPool> constantPool)
	{
		return;
	}

}
