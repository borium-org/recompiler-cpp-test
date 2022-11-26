#pragma once

#include "org__borium__javarecompiler__classfile__ClassAttribute.h"

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class ClassAttribute;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class StackMapFrame;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	class AttributeStackMapTable : public ClassAttribute
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<JavaArray<StackMapFrame>> stackMapEntries;

		static void __ClassInit();
		AttributeStackMapTable(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp);
		virtual void decode(Pointer<ConstantPool> cp);
	};

}
