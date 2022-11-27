#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__ExceptionTable.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> ExceptionTable::__thisClassStatic;

	void ExceptionTable::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::ExceptionTable",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ExceptionTable::ExceptionTable(Pointer<ByteInputStream> in) :
		Object() //
		, startPc(0) //
		, endPc(0) //
		, handlerPc(0) //
		, catchType(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->startPc = in->u2();
		this->endPc = in->u2();
		this->handlerPc = in->u2();
		this->catchType = in->u2();
		return;
	}

	Pointer<String> ExceptionTable::getExceptionClass()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->catchClass->getName();
	}

	void ExceptionTable::addLabels(Pointer<JavaRawArray<bool>> labels)
	{
		UsageCounterMaintainer maintainer(this, true);

		labels->assign(this->startPc, (1) & 1);
		labels->assign(this->endPc, (1) & 1);
		labels->assign(this->handlerPc, (1) & 1);
		return;
	}

}
