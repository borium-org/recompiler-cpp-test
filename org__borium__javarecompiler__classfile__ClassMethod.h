#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
	class StringBuilder;
}

namespace java::util
{
	template <class A> class ArrayList;
	template <class A, class B> class HashMap;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class ClassAttribute;
	class ClassFile;
	class IndentedOutputStream;
	class ReferencedClasses;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class AttributeCode;
	class AttributeSignature;
	class ExceptionTable;
	class VariableTableEntry;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile
{

	class ClassMethod : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		static int AccessSynthetic;
		static int AccessStrict;
		static int AccessAbstract;
		static int AccessNative;
		static int AccessVarArgs;
		static int AccessBridge;
		static int AccessSynchronized;
		static int AccessFinal;
		static int AccessStatic;
		static int AccessProtected;
		static int AccessPrivate;
		static int AccessPublic;
		int accessFlags;
		int nameIndex;
		int descriptorIndex;
		Pointer<HashMap<String, ClassAttribute>> attributes;
		Pointer<ArrayList<ClassAttribute>> attributeList;
		Pointer<String> name;
		Pointer<String> descriptor;

		static void __ClassInit();
		ClassMethod();
		virtual void addReferencedClasses(Pointer<ReferencedClasses> referencedClasses);
		virtual void dump(Pointer<IndentedOutputStream> stream, Pointer<ConstantPool> cp);
		virtual Pointer<AttributeCode> getCode();
		virtual Pointer<String> getDescriptor();
		virtual Pointer<JavaArray<ExceptionTable>> getExceptionTable();
		virtual Pointer<JavaArray<Instruction>> getInstructions();
		virtual int getLocalsCount();
		virtual Pointer<JavaArray<VariableTableEntry>> getLocalVariableTable();
		virtual Pointer<String> getName();
		virtual int getParameterCount();
		virtual Pointer<String> getType();
		virtual bool isAbstract();
		virtual bool isPresentInSource();
		virtual bool isStatic();
		virtual void read(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
	};

}
