#include "stdafx.h"
#include "java__lang__StringBuilder.h"
#include "java__lang__String.h"
#include "java__lang__Double.h"

namespace java::lang
{

	StringBuilder::StringBuilder(Pointer<String> string)
	{
		buffer = string->data;
	}

	StringBuilder::StringBuilder(const char* string)
	{
		buffer = string;
	}

	//StringBuilder::~StringBuilder()
	//{
	//}

	Pointer<StringBuilder> StringBuilder::append(Pointer<String> string)
	{
		buffer += string->data;
		return this;
	}

	Pointer<StringBuilder> StringBuilder::append(char value)
	{
		CString string;
		string.Format("%c", value);
		buffer += string;
		return this;
	}

	Pointer<StringBuilder> StringBuilder::append(int value)
	{
		CString string;
		string.Format("%d", value);
		buffer += string;
		return this;
	}

	Pointer<StringBuilder> StringBuilder::append(INT64 value)
	{
		CString string;
		string.Format("%I64d", value);
		buffer += string;
		return this;
	}

	Pointer<StringBuilder> StringBuilder::append(double value)
	{
		Double::toString(value);
		CString string;
		string.Format("%g", value);
		buffer += string;
		return this;
	}

	Pointer<String> StringBuilder::toString()
	{
		return new String(buffer);
	}

}
