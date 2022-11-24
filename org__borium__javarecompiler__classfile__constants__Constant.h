#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class ClassFormatError;
	class Object;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantClassInfo;
	class ConstantDouble;
	class ConstantDynamic;
	class ConstantFieldrefInfo;
	class ConstantFloat;
	class ConstantInteger;
	class ConstantInterfaceMethodrefInfo;
	class ConstantInvokeDynamic;
	class ConstantLong;
	class ConstantMethodHandle;
	class ConstantMethodType;
	class ConstantMethodrefInfo;
	class ConstantModule;
	class ConstantNameAndTypeInfo;
	class ConstantPackage;
	class ConstantPool;
	class ConstantStringInfo;
	class ConstantUtf8Info;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	class Constant : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		static int CONSTANT_Utf8;
		static int CONSTANT_Integer;
		static int CONSTANT_Float;
		static int CONSTANT_Long;
		static int CONSTANT_Double;
		static int CONSTANT_Class;
		static int CONSTANT_String;
		static int CONSTANT_Fieldref;
		static int CONSTANT_Methodref;
		static int CONSTANT_InterfaceMethodref;
		static int CONSTANT_NameAndType;
		static int CONSTANT_MethodHandle;
		static int CONSTANT_MethodType;
		static int CONSTANT_Dynamic;
		static int CONSTANT_InvokeDynamic;
		static int CONSTANT_Module;
		static int CONSTANT_Package;
		int tag;

		static void __ClassInit();
		Constant();
		static Pointer<Constant> create(int tag);
		virtual void dump(Pointer<IndentedOutputStream> param1) = 0;
		virtual bool is(int constantType);
		virtual void fixup(Pointer<ConstantPool> constantPool);
		virtual void read(Pointer<ByteInputStream> param1) = 0;
		virtual bool verify(int param1, int param2, Pointer<ConstantPool> param3, int param4) = 0;
	};

}
