#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Class : public Object
	{
	public:
		Class(const char* thisClassName, Pointer<Class> parentClass);
		Class(const char* thisClassName);
		//	virtual bool isInstance(Pointer<Object> clazz);
		virtual Pointer<String> getSimpleName();
		virtual Pointer<String> getName()
		{
			return createString(thisName);
		}
		Pointer<Class> getParentClass()
		{
			return parent;
		}
	private:
		CString thisName;
		Pointer<Class> parent;
	};
}
