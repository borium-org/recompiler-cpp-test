#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class IOException;
	class PrintStream;
}

namespace java::lang
{
	class Integer;
	class Object;
	class String;
	class StringBuilder;
}

namespace java::util
{
	template <class A> class ArrayList;
	class Iterator;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;

namespace org::borium::javarecompiler::classfile
{

	class IndentedOutputStream : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		static bool _disableLocking;
		Pointer<PrintStream> stream;
		int indentLevel;
		bool locked;
		Pointer<ArrayList<String>> temporaryOutput;

		static void __ClassInit();
		static void disableLocking();
		IndentedOutputStream(Pointer<String> fileName);
		virtual void close();
		virtual void indent(int i);
		virtual void iprint(Pointer<String> string);
		virtual void iprintln(Pointer<JavaRawArray<byte>> info);
		virtual void iprintln(Pointer<JavaRawArray<byte>> info, int start, int length);
		virtual void iprintln(Pointer<String> string);
		virtual void liprintln(int temporaryIndent, Pointer<String> string);
		virtual void lock();
		virtual void print(Pointer<String> string);
		virtual void printHex(int value, int length);
		virtual void println();
		virtual void println(Pointer<JavaRawArray<byte>> info, int start, int length);
		virtual void println(Pointer<String> string);
		virtual void unlock();
	};

}
