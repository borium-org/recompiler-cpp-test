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

	bool Object::equals(Pointer<Object> other)
	{
		if (other.getValue() == nullptr)
			return false;
		CString thisClassName = this->__thisClass->getName()->operator CString();
		CString thatClassName = other->__thisClass->getName()->operator CString();
		CString stringClassName = String::__thisClassStatic->getName()->operator CString();
		if (thisClassName == stringClassName && thatClassName == stringClassName)
		{
			String* thisString = (String*)this;
			String* thatString = (String*)other.getValue();
			return thisString->equals(thatString);
		}

		return this == other.getValue();
	}

}
