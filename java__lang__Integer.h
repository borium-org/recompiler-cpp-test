#pragma once

#include "java__lang__Object.h"
#include "java__lang__String.h"

namespace java::lang
{

	class Integer : public Object
	{
	public:
		//	static void ClassInit();
		Integer(int expression)
		{
			value = expression;
		}
		static Pointer<String> toHexString(int value)
		{
			CString buf;
			buf.Format("%x", value);
			return new String(buf);
		}
		static Pointer<Integer> valueOf(int expression)
		{
			return new Integer(expression);
		}
		static int parseInt(Pointer<String> value)
		{
			CString string = value->operator CString();
			return atoi(string);
		}
		virtual int intValue()
		{
			return value;
		}
	private:
		int value;
	};

}
