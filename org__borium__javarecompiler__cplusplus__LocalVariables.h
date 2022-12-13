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
	class Iterator;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class VariableTableEntry;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppClass;
	class LocalVariable;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::instruction;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class LocalVariables : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<ArrayList<LocalVariable>> localVariableTable;

		static void __ClassInit();
		LocalVariables(Pointer<JavaArray<VariableTableEntry>> localVariableTable, Pointer<CppClass> cppClass);
		virtual Pointer<LocalVariable> get(int index, Pointer<Instruction> instruction);
		virtual Pointer<LocalVariable> get(int index, int address);
		virtual Pointer<ArrayList<LocalVariable>> getVariables();
		virtual Pointer<LocalVariable> set(int index, Pointer<String> type, int address);
	};

}
