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
	private:
		CString thisName;
		Pointer<Class> parent;
	};
}
