#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class String : public Object
	{
		friend class StringBuilder;
	public:
		String()
		{
			__ClassInit();
			__thisClass = __thisClassStatic;
		}
		String(const char* string)
		{
			__ClassInit();
			__thisClass = __thisClassStatic;

			data = string;
		}
		String(Pointer<JavaRawArray<byte>> bytes, Pointer<String> encoding);
		static void __ClassInit();
		static Pointer<String> valueOf(Pointer<String> string)
		{
			return string;
		}
		static Pointer<String> valueOf(int value)
		{
			CString string;
			string.Format("%d", value);
			return new String(string);
		}
		static Pointer<String> valueOf(INT64 value)
		{
			CString string;
			string.Format("%I64d", value);
			return new String(string);
		}
		//	static Pointer<String> valueOf(INT64 integer);
		static Pointer<String> join(Pointer<String> separator, Pointer<JavaArray<String>> parts);
		virtual int hashCode();
		virtual int length()
		{
			return data.GetLength();
		}
		virtual bool equals(Pointer<String> other);
		virtual bool contains(Pointer<String> part)
		{
			return data.Find(part->operator CString()) >= 0;
		}
		virtual bool startsWith(const char* start)
		{
			return data.Left((int)strlen(start)) == start;
		}
		virtual bool startsWith(Pointer<String> start)
		{
			CString startString = start->operator CString();
			return data.Left(startString.GetLength()) == startString;
		}
		virtual bool endsWith(const char* end)
		{
			int length = (int)strlen(end);
			if (length > data.GetLength())
				return false;
			return data.Mid(data.GetLength() - length) == end;
		}
		virtual bool endsWith(Pointer<String> end)
		{
			CString endString = end->operator CString();
			int length = (int)strlen(endString);
			if (length > data.GetLength())
				return false;
			return data.Mid(data.GetLength() - length) == endString;
		}
		virtual Pointer<String> replace(char from, char to)
		{
			CString replaced = data;
			replaced.Replace(from, to);
			return new String(replaced);
		}
		virtual bool operator < (Object* other) const
		{
			String* string2 = (String*)other;
			return data < string2->data;
		}
		virtual Pointer<String> substring(int first);
		virtual Pointer<String> substring(int first, int last);
		virtual int indexOf(char ch)
		{
			return data.Find(ch);
		}
		virtual int indexOf(Pointer<String> string)
		{
			return data.Find(string->operator CString());
		}
		virtual int lastIndexOf(char ch)
		{
			return data.ReverseFind(ch);
		}
		virtual int lastIndexOf(Pointer<String> string)
		{
			CString str = string->operator CString();
			int pos = data.Find(str);
			int pos1 = data.Find(str, pos + 1);
			while (pos1 != -1)
			{
				pos = pos1;
				pos1 = data.Find(str, pos + 1);
			}
			throw new std::exception("lastIndexOf: Verify correctness");
			return pos;
		}
		//	virtual int lastIndexOf(const char* string);
		virtual char charAt(int index)
		{
			return data[index];
		}
		virtual Pointer<JavaArray<String>> split(Pointer<String> regex);
		virtual Pointer<String> toUpperCase();
		virtual Pointer<String> toLowerCase();
		operator CString() const
		{
			return data;
		}

		operator Object* () const
		{
			return (Object*)this;
		}

	private:
		CString data;
	};

}
