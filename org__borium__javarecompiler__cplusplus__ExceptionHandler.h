#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
}

namespace java::util
{
	template <class A> class ArrayList;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class ExceptionTable;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppClass;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class ExceptionHandler : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int startPc;
		int endPc;
		int handlerPc;
		Pointer<ArrayList<String>> exceptionClasses;

		static void __ClassInit();
		ExceptionHandler(Pointer<ExceptionTable> entry, Pointer<CppClass> cppClass);
	};

}
