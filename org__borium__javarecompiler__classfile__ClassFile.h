#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class IOException;
}

namespace java::lang
{
	class ClassFormatError;
	class Object;
	class String;
	class StringBuilder;
}

using namespace java::io;
using namespace java::lang;

namespace org::borium::javarecompiler::classfile
{

	class ClassFile : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<String> className;

		static void __ClassInit();
		ClassFile();
		virtual void read(Pointer<String> fileName);
	};

}
