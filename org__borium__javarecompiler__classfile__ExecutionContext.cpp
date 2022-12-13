#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ExecutionContext.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__util__Stack.h"
#include "org__borium__javarecompiler__classfile__ClassMethod.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeCode.h"
#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ExecutionContext::__thisClassStatic;

	Pointer<String> ExecutionContext::StackEntrySeparator = createString("	");
	Pointer<String> ExecutionContext::SplitStackEntrySeparator = createString("[	]");

	void ExecutionContext::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ExecutionContext",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ExecutionContext::ExecutionContext(Pointer<ClassMethod> javaMethod) :
		Object() //
		, maxLocals(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<AttributeCode> code_0024;
		Pointer<Stack<Object>> temp_0009;
		temp_0009 = new Stack<Object>();
		this->stack = (Stack<String>*)temp_0009.getValue();
		this->name = javaMethod->getName().getValue();
		this->type = javaMethod->getDescriptor().getValue();
		code_0024 = javaMethod->getCode();
		if (javaMethod->isAbstract())
			goto L0043;
		this->instructions = code_0024->getInstructions();
		this->maxLocals = code_0024->getLocalsCount();
		this->labels = code_0024->getLabels();
	L0043: //
		return;
	}

	Pointer<Stack<String>> ExecutionContext::getStack()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->stack;
	}

}
