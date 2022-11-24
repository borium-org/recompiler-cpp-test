#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Integer;
	class Object;
	class RuntimeException;
	class String;
	class StringBuilder;
}

namespace java::util
{
	class Iterator;
	template <class A> class TreeSet;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	class ReferencedClasses : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<TreeSet<String>> referencedClasses;

		static void __ClassInit();
		ReferencedClasses(Pointer<ConstantPool> cp);
		virtual void add(Pointer<String> type);
		virtual Pointer<TreeSet<String>> getClasses();
		virtual int getTemplateParameterCount(Pointer<String> fullClassName);
		virtual void removeClass(Pointer<String> className);
		virtual Pointer<String> addClass(Pointer<String> type);
		virtual Pointer<String> addTemplateBaseClasses(Pointer<String> type);
		virtual void insert(Pointer<String> className);
		virtual Pointer<String> skipClass(Pointer<String> type);
	};

}
