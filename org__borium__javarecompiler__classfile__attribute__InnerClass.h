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
	class ClassFile;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantClassInfo;
	class ConstantPool;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	class InnerClass : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int innerClassInfoIndex;
		int outerClassInfoIndex;
		int innerClassNameIndex;
		int innerClassAccessFlags;
		Pointer<ConstantClassInfo> outer;
		Pointer<ConstantClassInfo> inner;
		Pointer<String> outerName;
		Pointer<String> innerName;
		Pointer<String> innerClassName;

		static void __ClassInit();
		InnerClass(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
	};

}
