#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ClassFile::__thisClassStatic;

	void ClassFile::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ClassFile",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ClassFile::ClassFile() :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		return;
	}

}
