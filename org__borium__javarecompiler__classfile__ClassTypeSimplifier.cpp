#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ClassTypeSimplifier.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"

using namespace java::lang;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ClassTypeSimplifier::__thisClassStatic;

	void ClassTypeSimplifier::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ClassTypeSimplifier",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

}
