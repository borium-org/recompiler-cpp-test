#include "stdafx.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"

using namespace java::lang;

namespace java::io
{
	class ByteArrayInputStream : public Object
	{
	public:
		ByteArrayInputStream(Pointer<JavaRawArray<byte>> bytes)
		{
			Pointer<String> data = new String(bytes, createString("UTF-8"));
			CString string = data.getValue()->operator CString();
			is.str(string.GetBuffer());
		}
		virtual int available()
		{
			std::streampos pos = is.tellg();
			is.seekg(0, is.end);
			std::streampos end = is.tellg();
			is.seekg(pos, is.beg);
			return (int)(end - pos);
		}
		virtual void close()
		{
		}
		virtual int read()
		{
			return is.get();
		}
		virtual void read(Pointer<JavaRawArray<byte>> data)
		{
			for (int i = 0; i < data->length; i++)
				data->assign(i, (byte)read());
		}
	private:
		std::istringstream is;
	};
}
