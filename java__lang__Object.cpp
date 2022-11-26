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
		Pointer<String> thisClassName = __thisClass->getName();
		Pointer<String> instClassName = clazz->getName();
		if (thisClassName->equals(instClassName))
			return true;
		throw new std::exception("InstanceOf not implemented");
	}

}
