#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class StringBuilder : public Object
	{
	public:
		StringBuilder()
		{
		}
		StringBuilder(Pointer<String> string);
		StringBuilder(const char* string);
		//	virtual ~StringBuilder();
		virtual Pointer<StringBuilder> append(Pointer<String> string);
		virtual Pointer<StringBuilder> append(int value);
		virtual Pointer<StringBuilder> append(char value);
		virtual Pointer<StringBuilder> append(INT64 value);
		virtual Pointer<StringBuilder> append(double value);
		//	Pointer<StringBuilder> append(double value);
		virtual Pointer<String> toString();
	private:
		CString buffer;
	};
}
