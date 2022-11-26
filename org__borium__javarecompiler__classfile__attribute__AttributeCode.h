#pragma once

#include "org__borium__javarecompiler__classfile__ClassAttribute.h"

namespace java::lang
{
	class String;
	class StringBuilder;
}

namespace java::util
{
	template <class A> class ArrayList;
	template <class A, class B> class HashMap;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class ClassAttribute;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class AttributeLocalVariableTable;
	class AttributeLocalVariableTypeTable;
	class ExceptionTable;
	class LocalVariableType;
	class VariableTableEntry;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantClassInfo;
	class ConstantPool;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::attribute
{

	class AttributeCode : public ClassAttribute
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<JavaArray<Instruction>> instructions;
		int maxStack;
		int maxLocals;
		int codeLength;
		Pointer<JavaRawArray<byte>> code;
		Pointer<JavaArray<ExceptionTable>> exceptionTable;
		Pointer<HashMap<String, ClassAttribute>> attributes;
		Pointer<ArrayList<ClassAttribute>> attributeList;
		Pointer<JavaRawArray<bool>> labels;

		static void __ClassInit();
		AttributeCode(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp);
		virtual Pointer<JavaArray<ExceptionTable>> getExceptionTable();
		virtual Pointer<JavaArray<Instruction>> getInstructions();
		virtual Pointer<JavaRawArray<bool>> getLabels();
		virtual int getLength();
		virtual int getLocalsCount();
		virtual Pointer<JavaArray<VariableTableEntry>> getLocalVariableTable();
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual void decode(Pointer<ConstantPool> cp);
		virtual void updateEntries(Pointer<JavaArray<VariableTableEntry>> entries, Pointer<JavaArray<LocalVariableType>> localVariableTypes);
	};

}
