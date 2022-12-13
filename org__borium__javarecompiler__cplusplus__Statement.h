#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
	class StringBuilder;
}

namespace java::util
{
	template <class A> class ArrayList;
	class Iterator;
	template <class A> class Stack;
}

namespace org::borium::javarecompiler
{
	class Recomp;
	class Statics;
}

namespace org::borium::javarecompiler::classfile
{
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppExecutionContext;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class Statement : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<ArrayList<Instruction>> instructions;
		Pointer<CppExecutionContext> executionContext;

		static void __ClassInit();
		Statement(Pointer<CppExecutionContext> executionContext, Pointer<ArrayList<Instruction>> instructions);
		virtual void dumpInstructions(Pointer<IndentedOutputStream> trace);
		virtual void generateLabel(Pointer<IndentedOutputStream> source);
		virtual void generateSource(Pointer<IndentedOutputStream> source, bool allowLabel);
		virtual int getAddress();
		virtual int getInstructionCount();
		virtual Pointer<ArrayList<Instruction>> getInstructions();
		virtual Pointer<Instruction> getLastInstruction();
		virtual int length();
		virtual void merge(Pointer<Statement> nextStatement);
		virtual Pointer<Statement> splitLastInstruction();
		virtual void dumpStack(Pointer<IndentedOutputStream> source, Pointer<Stack<String>> stack);
	};

}
