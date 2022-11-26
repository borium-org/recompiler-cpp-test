#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class Class;
	class Object;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantClassInfo;
	class ConstantInterfaceMethodrefInfo;
	class ConstantNameAndTypeInfo;
	class ConstantPool;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionINVOKEINTERFACE : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int index;
		int count;
		int zero;
		Pointer<ConstantInterfaceMethodrefInfo> methodref;
		Pointer<ConstantNameAndTypeInfo> nameType;
		Pointer<ConstantClassInfo> classInfo;
		Pointer<String> methodClassName;
		Pointer<String> methodName;

		static void __ClassInit();
		InstructionINVOKEINTERFACE(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual int getCount();
		virtual Pointer<String> getMethodClassName();
		virtual Pointer<String> getmethodDescriptor();
		virtual Pointer<String> getMethodName();
		virtual int getStackDepthChange();
		virtual int length();
	};

}
