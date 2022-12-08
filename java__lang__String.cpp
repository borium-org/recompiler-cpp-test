#include "stdafx.h"
#include "java__lang__String.h"
#include "java__lang__Class.h"

namespace java::lang
{
	Pointer<String> createString(const char* string)
	{
		return new String(string);
	}

	void String::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class("java::lang::String",
			java::lang::Object::__thisClassStatic);

		return;
	}


	String::String(Pointer<JavaRawArray<byte>> bytes, Pointer<String> encoding)
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		if (encoding->operator CString() != "UTF-8")
			throw new std::exception("UTF-8 encoding expected");
		for (int i = 0; i < bytes->length; i++)
			data += (char)bytes->get(i);
	}

	int String::hashCode()
	{
		int h = 0;
		int length = data.GetLength();
		for (int i = 0; i < length; i++)
		{
			int v = data[i];
			h = 31 * h + (v & 0xff);
		}
		return h;
	}

	bool String::equals(Pointer<String> other)
	{
		return data == other->data;
	}

	Pointer<String> String::substring(int first)
	{
		CString buf = data.Mid(first);
		return new String(buf);
	}

	Pointer<String> String::substring(int first, int last)
	{
		CString buf = data.Mid(first, last - first);
		return new String(buf);
	}

	Pointer<String> String::toUpperCase()
	{
		CString buf = data;
		buf.MakeUpper();
		return new String(buf);
	}

	Pointer<String> String::toLowerCase()
	{
		CString buf = data;
		buf.MakeLower();
		return new String(buf);
	}

	// https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
	Pointer<JavaArray<String>> String::split(Pointer<String> regex)
	{
		std::vector<std::string> output;
		std::string::size_type prev_pos = 0, pos = 0;

		CString separator = regex->operator CString();
		if (separator[0] == '[')
			separator = separator.Mid(1, separator.GetLength() - 2);
		std::string string = data.GetBuffer();
		while ((pos = string.find(separator, pos)) != std::string::npos)
		{
			std::string substring(string.substr(prev_pos, pos - prev_pos));
			output.push_back(substring);
			prev_pos = ++pos;
		}
		output.push_back(string.substr(prev_pos, pos - prev_pos)); // Last word

		JavaArray<String>* array = new JavaArray<String>((int)output.size());
		for (int i = 0; i < output.size(); i++)
			array->assignString(i, output[i].c_str());
		return array;
	}

	Pointer<String> String::join(Pointer<String> separator, Pointer<JavaArray<String>> parts)
	{
		CString result;
		for (int i = 0; i < parts->length; i++)
		{
			if (i > 0)
				result += separator->operator CString();
			result += parts->get(i)->operator CString();
		}
		return new String(result);
	}
}
