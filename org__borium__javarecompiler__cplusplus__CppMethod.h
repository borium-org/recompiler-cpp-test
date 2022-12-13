#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class IOException;
	class PrintStream;
}

namespace java::lang
{
	class Integer;
	class Object;
	class String;
	class StringBuilder;
	class System;
}

namespace java::util
{
	template <class A> class ArrayList;
	class Arrays;
	template <class A, class B> class HashMap;
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
	class ClassMethod;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
	class InstructionARETURN;
	class InstructionASTORE;
	class InstructionDRETURN;
	class InstructionFRETURN;
	class InstructionGOTO;
	class InstructionINVOKESPECIAL;
	class InstructionIRETURN;
	class InstructionLRETURN;
	class InstructionRETURN;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppClass;
	class CppExecutionContext;
	class CppField;
	class ExceptionHandler;
	class ExceptionHandlers;
	class LocalVariable;
	class Statement;
}

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class CppMethod : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<HashMap<Integer, Statement>> statements;
		Pointer<CppExecutionContext> executionContext;
		bool isStatic;
		bool isAbstract;
		bool isPresent;
		Pointer<CppClass> cppClass;
		Pointer<ExceptionHandlers> exceptionHandlers;
		int parameterCount;
		Pointer<JavaArray<Instruction>> instructions;

		static void __ClassInit();
		static void generateClassInitDefaultCode(Pointer<IndentedOutputStream> source, Pointer<CppClass> clazz);
		CppMethod(Pointer<CppClass> cppClass, Pointer<ClassMethod> javaMethod);
		virtual bool containsStatementAt(int targetAddress);
		virtual void generateHeader(Pointer<IndentedOutputStream> header, Pointer<String> newName, Pointer<String> newType);
		virtual void generateSource(Pointer<IndentedOutputStream> source, Pointer<String> newName, Pointer<String> newType, Pointer<JavaArray<CppField>> fields);
		virtual Pointer<JavaArray<Instruction>> getInstructions();
		virtual Pointer<String> getName();
		virtual Pointer<String> getType();
		virtual bool isPresentInSource();
		virtual void combineStatements();
		virtual Pointer<String> createInitializer(Pointer<String> type);
		virtual void generateLocalVariableInitializer(Pointer<IndentedOutputStream> source, Pointer<LocalVariable> local);
		virtual void generateLocalVariables(Pointer<IndentedOutputStream> source);
		virtual int generateStatements(Pointer<IndentedOutputStream> source, int address, int endAddress, bool allowLabel);
		virtual void generateStatementSource(Pointer<IndentedOutputStream> source, bool isConstructor, bool isStaticConstructor);
		virtual void generateTryBlockVariables(Pointer<IndentedOutputStream> source, int address, int endPc);
		virtual void parseStatements();
	};

}
