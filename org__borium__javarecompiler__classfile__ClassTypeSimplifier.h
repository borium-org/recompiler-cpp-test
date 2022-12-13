#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
}

using namespace java::lang;

namespace org::borium::javarecompiler::classfile
{

	class ClassTypeSimplifier : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:

		static void __ClassInit();
		virtual Pointer<String> typeSimplifier(Pointer<String> param1) = 0;
	};

}
