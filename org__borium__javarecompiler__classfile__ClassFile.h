#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class DataInputStream;
	class FileInputStream;
	class IOException;
}

namespace java::lang
{
	class ClassFormatError;
	class Object;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

using namespace java::io;
using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	class ClassFile : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<ByteInputStream> in;
		int majorVersion;
		int minorVersion;
		Pointer<ConstantPool> cp;
		Pointer<String> className;

		static void __ClassInit();
		ClassFile();
		virtual void read(Pointer<String> fileName);
		virtual void readConstants();
		virtual void readID();
		virtual void readVersion();
	};

}
