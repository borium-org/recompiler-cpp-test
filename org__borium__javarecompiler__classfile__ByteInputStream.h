#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class ByteArrayInputStream;
	class IOException;
	class UnsupportedEncodingException;
}

namespace java::lang
{
	class ClassFormatError;
	class Double;
	class Float;
	class Object;
	class String;
	class StringBuilder;
}

using namespace java::io;
using namespace java::lang;

namespace org::borium::javarecompiler::classfile
{

	class ByteInputStream : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<ByteArrayInputStream> in;
		int length;

		static void __ClassInit();
		ByteInputStream(Pointer<JavaRawArray<byte>> data);
		virtual int available();
		virtual void close();
		virtual double f4();
		virtual double f8();
		virtual int getPosition();
		virtual Pointer<JavaRawArray<byte>> read(int length);
		virtual int s1();
		virtual int s2();
		virtual int s4();
		virtual int u1();
		virtual int u2();
		virtual int u4();
		virtual INT64 u8();
		virtual Pointer<String> utf8();
	};

}
