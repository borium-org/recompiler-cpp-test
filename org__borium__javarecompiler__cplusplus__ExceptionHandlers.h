#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Integer;
	class Object;
	class String;
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

namespace org::borium::javarecompiler::classfile::attribute
{
	class ExceptionTable;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppClass;
	class ExceptionHandler;
	class LocalVariable;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class ExceptionHandlers : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<ArrayList<ExceptionHandler>> handlers;

		static void __ClassInit();
		ExceptionHandlers(Pointer<JavaArray<ExceptionTable>> exceptionTable, Pointer<CppClass> cppClass);
		virtual Pointer<ArrayList<Integer>> getCatchAddresses();
		virtual bool isCatchBlock(int address);
		virtual Pointer<ExceptionHandler> isParameter(Pointer<LocalVariable> local);
		virtual Pointer<ExceptionHandler> isTryVariable(Pointer<LocalVariable> local);
		virtual Pointer<ExceptionHandler> findHandler(int address);
		virtual Pointer<ExceptionHandler> findHandler(Pointer<ExceptionTable> entry);
	};

}
