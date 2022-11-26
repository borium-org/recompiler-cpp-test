#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class AttributeCode;
	class AttributeConstantValue;
	class AttributeExceptions;
	class AttributeInnerClasses;
	class AttributeLineNumberTable;
	class AttributeLocalVariableTable;
	class AttributeLocalVariableTypeTable;
	class AttributeNestMembers;
	class AttributeSignature;
	class AttributeSourceFile;
	class AttributeStackMapTable;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	class ClassAttribute : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int attributeNameIndex;
		int attributeLength;
		Pointer<String> attributeName;
		Pointer<JavaRawArray<byte>> info;

		static void __ClassInit();
		static Pointer<ClassAttribute> readAttribute(Pointer<ByteInputStream> in, Pointer<ConstantPool> constants);
		ClassAttribute(Pointer<ClassAttribute> attribute);
		ClassAttribute();
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<String> getName();
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual void read(Pointer<ByteInputStream> in, Pointer<ConstantPool> constants);
	};

}
