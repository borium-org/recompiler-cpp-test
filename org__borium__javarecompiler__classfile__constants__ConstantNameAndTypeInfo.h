#pragma once

#include "org__borium__javarecompiler__classfile__constants__Constant.h"

namespace java::lang
{
	class RuntimeException;
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
	class Constant;
	class ConstantPool;
}

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	class ConstantNameAndTypeInfo : public Constant
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int nameIndex;
		int descriptorIndex;
		Pointer<String> name;
		Pointer<String> descriptor;

		static void __ClassInit();
		ConstantNameAndTypeInfo();
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<String> getDescriptor();
		virtual Pointer<String> getName();
		virtual int getParameterCount();
		virtual int getReturnTypeCount();
		virtual void fixup(Pointer<ConstantPool> constantPool);
		virtual void read(Pointer<ByteInputStream> in);
		virtual bool verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index);
	};

}
