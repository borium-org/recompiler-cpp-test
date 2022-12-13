#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__ExceptionHandlers.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Integer.h"
#include "java__lang__String.h"
#include "java__util__ArrayList.h"
#include "java__util__Iterator.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__attribute__ExceptionTable.h"
#include "org__borium__javarecompiler__cplusplus__CppClass.h"
#include "org__borium__javarecompiler__cplusplus__ExceptionHandler.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariable.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> ExceptionHandlers::__thisClassStatic;

	void ExceptionHandlers::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::ExceptionHandlers",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ExceptionHandlers::ExceptionHandlers(Pointer<JavaArray<ExceptionTable>> exceptionTable, Pointer<CppClass> cppClass) :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<ExceptionTable> entry_0022;
		Pointer<ExceptionHandler> handler_0029;
		Pointer<String> exceptionClass_0053;
		Pointer<ArrayList<Object>> temp_0009;
		Pointer<JavaArray<ExceptionTable>> local_0011;
		int local_0014 = 0;
		int local_0017 = 0;
		Pointer<ExceptionHandler> temp_0034;
		temp_0009 = new ArrayList<Object>();
		this->handlers = (ArrayList<ExceptionHandler>*)temp_0009.getValue();
		local_0011 = (JavaArray<ExceptionTable>*)(exceptionTable.getValue());
		local_0014 = exceptionTable->length;
		local_0017 = 0;
		goto L0070;
	L001C: //
		entry_0022 = local_0011->get(local_0017);
		handler_0029 = this->findHandler(entry_0022);
		if ((handler_0029).getValue() != nullptr)
			goto L0046;
		temp_0034 = new ExceptionHandler(entry_0022, cppClass);
		handler_0029 = temp_0034;
		this->handlers->add(handler_0029.getValue());
		goto L006D;
	L0046: //
		exceptionClass_0053 = entry_0022->getExceptionClass()->replace('/', '.');
		Statics::__ClassInit();
		exceptionClass_0053 = Statics::javaToCppClass(exceptionClass_0053);
		exceptionClass_0053 = cppClass->simplifyType(exceptionClass_0053);
		handler_0029->exceptionClasses->add(exceptionClass_0053.getValue());
	L006D: //
		local_0017 += 1;
	L0070: //
		if ((local_0017) < (local_0014))
			goto L001C;
		return;
	}

	Pointer<ArrayList<Integer>> ExceptionHandlers::getCatchAddresses()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ArrayList<Integer>> addresses_0008;
		Pointer<ExceptionHandler> handler_001D;
		Pointer<ArrayList<Object>> temp_0004;
		Pointer<Iterator> local_000F;
		Pointer<ExceptionHandler> temp_0019;
		temp_0004 = new ArrayList<Object>();
		addresses_0008 = (ArrayList<Integer>*)(temp_0004.getValue());
		local_000F = this->handlers->iterator();
		goto L0029;
	L0013: //
		temp_0019 = (ExceptionHandler*)((local_000F->next()).getValue());
		temp_0019->checkCast(ExceptionHandler::__thisClassStatic);
		handler_001D = temp_0019;
		Integer::__ClassInit();
		addresses_0008->add(Integer::valueOf(handler_001D->handlerPc).getValue());
	L0029: //
		if (local_000F->hasNext())
			goto L0013;
		return addresses_0008;
	}

	bool ExceptionHandlers::isCatchBlock(int address)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ExceptionHandler> handler_0015;
		Pointer<Iterator> local_0007;
		Pointer<ExceptionHandler> temp_0011;
		local_0007 = this->handlers->iterator();
		goto L001F;
	L000B: //
		temp_0011 = (ExceptionHandler*)((local_0007->next()).getValue());
		temp_0011->checkCast(ExceptionHandler::__thisClassStatic);
		handler_0015 = temp_0011;
		if ((handler_0015->handlerPc) != (address))
			goto L001F;
		return 1;
	L001F: //
		if (local_0007->hasNext())
			goto L000B;
		return 0;
	}

	Pointer<ExceptionHandler> ExceptionHandlers::isParameter(Pointer<LocalVariable> local)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ExceptionHandler> handler_0015;
		Pointer<Iterator> local_0007;
		Pointer<ExceptionHandler> temp_0011;
		local_0007 = this->handlers->iterator();
		goto L0024;
	L000B: //
		temp_0011 = (ExceptionHandler*)((local_0007->next()).getValue());
		temp_0011->checkCast(ExceptionHandler::__thisClassStatic);
		handler_0015 = temp_0011;
		if ((local->startPc) != ((handler_0015->handlerPc) + (2)))
			goto L0024;
		return handler_0015;
	L0024: //
		if (local_0007->hasNext())
			goto L000B;
		// ARETURN: Type mismatch
		return (ExceptionHandler*)nullptr;
	}

	Pointer<ExceptionHandler> ExceptionHandlers::isTryVariable(Pointer<LocalVariable> local)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ExceptionHandler> handler_0015;
		Pointer<Iterator> local_0007;
		Pointer<ExceptionHandler> temp_0011;
		local_0007 = this->handlers->iterator();
		goto L002D;
	L000B: //
		temp_0011 = (ExceptionHandler*)((local_0007->next()).getValue());
		temp_0011->checkCast(ExceptionHandler::__thisClassStatic);
		handler_0015 = temp_0011;
		if ((local->startPc) < (handler_0015->startPc))
			goto L002D;
		if ((local->endPc) > (handler_0015->endPc))
			goto L002D;
		return handler_0015;
	L002D: //
		if (local_0007->hasNext())
			goto L000B;
		// ARETURN: Type mismatch
		return (ExceptionHandler*)nullptr;
	}

	Pointer<ExceptionHandler> ExceptionHandlers::findHandler(int address)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ExceptionHandler> handler_0015;
		Pointer<Iterator> local_0007;
		Pointer<ExceptionHandler> temp_0011;
		local_0007 = this->handlers->iterator();
		goto L002A;
	L000B: //
		temp_0011 = (ExceptionHandler*)((local_0007->next()).getValue());
		temp_0011->checkCast(ExceptionHandler::__thisClassStatic);
		handler_0015 = temp_0011;
		if ((address) <= (handler_0015->endPc))
			goto L0020;
		goto L002A;
	L0020: //
		if ((address) > (handler_0015->endPc))
			goto L002A;
		return handler_0015;
	L002A: //
		if (local_0007->hasNext())
			goto L000B;
		// ARETURN: Type mismatch
		return (ExceptionHandler*)nullptr;
	}

	Pointer<ExceptionHandler> ExceptionHandlers::findHandler(Pointer<ExceptionTable> entry)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ExceptionHandler> handler_0015;
		Pointer<Iterator> local_0007;
		Pointer<ExceptionHandler> temp_0011;
		local_0007 = this->handlers->iterator();
		goto L0038;
	L000B: //
		temp_0011 = (ExceptionHandler*)((local_0007->next()).getValue());
		temp_0011->checkCast(ExceptionHandler::__thisClassStatic);
		handler_0015 = temp_0011;
		if ((handler_0015->startPc) != (entry->startPc))
			goto L0038;
		if ((handler_0015->endPc) != (entry->endPc))
			goto L0038;
		if ((handler_0015->handlerPc) != (entry->handlerPc))
			goto L0038;
		return handler_0015;
	L0038: //
		if (local_0007->hasNext())
			goto L000B;
		// ARETURN: Type mismatch
		return (ExceptionHandler*)nullptr;
	}

}
