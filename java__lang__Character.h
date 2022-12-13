#pragma once

#include "java__lang__Object.h"

namespace java::lang
{

	class Character : public Object
	{
	public:
		static void __ClassInit();
		static Pointer<String> valueOf(char value);
		static bool isJavaIdentifierPart(char value);
		static Pointer<String> toString(int value);
	private:
		static CString javaIdentifierPart;
	};

}
