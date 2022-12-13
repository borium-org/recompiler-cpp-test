#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__ExceptionHandler.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__util__ArrayList.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__attribute__ExceptionTable.h"
#include "org__borium__javarecompiler__cplusplus__CppClass.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> ExceptionHandler::__thisClassStatic;

	void ExceptionHandler::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::ExceptionHandler",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ExceptionHandler::ExceptionHandler(Pointer<ExceptionTable> entry, Pointer<CppClass> cppClass) :
		Object() //
		, startPc(0) //
		, endPc(0) //
		, handlerPc(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<String> exceptionClass_0033;
		Pointer<ArrayList<Object>> temp_0009;
		temp_0009 = new ArrayList<Object>();
		this->exceptionClasses = (ArrayList<String>*)temp_0009.getValue();
		this->startPc = entry->startPc;
		this->endPc = entry->endPc;
		this->handlerPc = entry->handlerPc;
		exceptionClass_0033 = entry->getExceptionClass()->replace('/', '.');
		Statics::__ClassInit();
		exceptionClass_0033 = Statics::javaToCppClass(exceptionClass_0033);
		exceptionClass_0033 = cppClass->simplifyType(exceptionClass_0033);
		this->exceptionClasses->add(exceptionClass_0033.getValue());
		return;
	}

}
