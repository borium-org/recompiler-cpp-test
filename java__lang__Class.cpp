#include "stdafx.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

namespace java::lang
{
	Class::Class(const char* thisClassName, Pointer<Class> parentClass)
	{
		thisName = thisClassName;
		parent = parentClass;
	}
	Class::Class(const char* thisClassName)
	{
		thisName = thisClassName;
	}
	Pointer<String> Class::getSimpleName()
	{
		CString simpleName = thisName.Mid(thisName.ReverseFind(':'));
		return new String(simpleName);
	}
}
