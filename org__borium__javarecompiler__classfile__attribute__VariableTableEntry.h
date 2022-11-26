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

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	class VariableTableEntry : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int startPc;
		int length;
		int nameIndex;
		int descriptorIndex;
		int index;
		Pointer<String> name;
		Pointer<String> descriptor;

		static void __ClassInit();
		VariableTableEntry(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
		virtual void dump(Pointer<IndentedOutputStream> stream);
	};

}
