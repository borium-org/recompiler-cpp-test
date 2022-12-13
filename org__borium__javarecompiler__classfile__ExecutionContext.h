#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
}

namespace java::util
{
	template <class A> class Stack;
}

namespace org::borium::javarecompiler::classfile
{
	class ClassMethod;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class AttributeCode;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile
{

	class ExecutionContext : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		static Pointer<String> StackEntrySeparator;
		static Pointer<String> SplitStackEntrySeparator;
		Pointer<String> name;
		Pointer<String> type;
		Pointer<JavaArray<Instruction>> instructions;
		int maxLocals;
		Pointer<Stack<String>> stack;
		Pointer<JavaRawArray<bool>> labels;

		static void __ClassInit();
		ExecutionContext(Pointer<ClassMethod> javaMethod);
		virtual Pointer<Stack<String>> getStack();
	};

}
