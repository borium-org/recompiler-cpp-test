#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class Class;
	class Object;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantFieldrefInfo;
	class ConstantNameAndTypeInfo;
	class ConstantPool;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionWithFieldIndex : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int index;
		Pointer<ConstantFieldrefInfo> fieldref;
		Pointer<ConstantNameAndTypeInfo> nameType;
		Pointer<String> fieldName;
		Pointer<String> fieldType;

		static void __ClassInit();
		InstructionWithFieldIndex(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<String> getClassName();
		virtual Pointer<String> getFieldName();
		virtual Pointer<String> getFieldType();
		virtual int length();
	};

}
