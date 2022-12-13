#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class VariableTableEntry;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppClass;
	class JavaTypeConverter;
}

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class LocalVariable : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int startPc;
		int endPc;
		Pointer<String> name;
		Pointer<String> type;
		int index;

		static void __ClassInit();
		LocalVariable(int index, Pointer<String> type, int address);
		LocalVariable(Pointer<VariableTableEntry> entry, Pointer<CppClass> cppClass);
		virtual Pointer<String> getName();
		virtual Pointer<String> getType();
	};

}
