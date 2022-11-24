#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Class;
	class ClassFormatError;
	class Object;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
	class ReferencedClasses;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class Constant;
	class ConstantClassInfo;
	class ConstantUtf8Info;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	class ConstantPool : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<JavaArray<Constant>> constants;

		static void __ClassInit();
		ConstantPool();
		virtual void addReferencedClasses(Pointer<ReferencedClasses> referencedClasses);
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<Constant> get(int index);
		virtual Pointer<String> getString(int index);
		virtual void read(Pointer<ByteInputStream> in);
		virtual void verify(int majorVersion, int minorVersion);
	};

}
