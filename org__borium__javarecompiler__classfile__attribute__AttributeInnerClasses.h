#pragma once

#include "org__borium__javarecompiler__classfile__ClassAttribute.h"

namespace java::lang
{
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class ClassAttribute;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class InnerClass;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	class AttributeInnerClasses : public ClassAttribute
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<JavaArray<InnerClass>> classTable;

		static void __ClassInit();
		AttributeInnerClasses(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual void decode(Pointer<ConstantPool> cp);
	};

}
