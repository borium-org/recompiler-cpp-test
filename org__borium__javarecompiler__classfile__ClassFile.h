#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
}

using namespace java::lang;

namespace org::borium::javarecompiler::classfile
{

	class ClassFile : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:

		static void __ClassInit();
		ClassFile();
	};

}
