#pragma once

#include "org__borium__javarecompiler__classfile__constants__Constant.h"

namespace java::lang
{
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
	class Constant;
	class ConstantPool;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	class ConstantStringInfo : public Constant
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int stringIndex;
		Pointer<String> string;

		static void __ClassInit();
		ConstantStringInfo();
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<String> getString();
		virtual Pointer<String> getValue(Pointer<ConstantPool> constantPool);
		virtual void fixup(Pointer<ConstantPool> constantPool);
		virtual void read(Pointer<ByteInputStream> in);
		virtual bool verify(int majorVersion, int minorVersion, Pointer<ConstantPool> cp, int index);
	};

}
