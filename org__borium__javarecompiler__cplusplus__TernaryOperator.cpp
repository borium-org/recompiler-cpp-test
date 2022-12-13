#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__TernaryOperator.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"

using namespace java::lang;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> TernaryOperator::__thisClassStatic;

	void TernaryOperator::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::TernaryOperator",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	TernaryOperator::TernaryOperator() :
		Object() //
		, falsePathAddress(0) //
		, endAddress(0) //
		, endOfTruePath(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

}
