#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class StringBuffer : public Object
	{
	public:
		//	StringBuffer(Pointer<String> value);
		StringBuffer(int value)
		{
		}
		virtual void append(char value)
		{
			buffer += value;
		}
		virtual void append(Pointer<String> value)
		{
			buffer += value->operator CString();
		}
		virtual void setLength(int length)
		{
			buffer = buffer.Left(length);
		}
		virtual int length()
		{
			return buffer.GetLength();
		}
		virtual Pointer<String> toString()
		{
			return new String(buffer);
		}
	private:
		CString buffer;
	};
}
