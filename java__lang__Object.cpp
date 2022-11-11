#include "stdafx.h"
#include "java__lang__Object.h"
#include "java__lang__Class.h"

namespace java::lang
{

	Pointer<Class> Object::__thisClassStatic;

	void Object::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class("java::lang::Object");

		return;
	}

}
