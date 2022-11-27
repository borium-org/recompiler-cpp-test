#include "stdafx.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
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

	bool Object::instanceOf(Pointer<Class> clazz)
	{
		if (this == nullptr)
			return false;
		Pointer<String> instClassName = clazz->getName();
		Pointer<Class> thisClass = __thisClass;
		while (thisClass.getValue() != nullptr)
		{
			Pointer<String> thisClassName = thisClass->getName();
			if (thisClassName->equals(instClassName))
				return true;
			thisClass = thisClass->getParentClass();
		}
		return false;
	}

}
