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
			data = bytes->getData();
			pos = 0;
		}
		virtual int available()
		{
			return (int)(data.size() - pos);
		}
		virtual void close()
		{
		}
		virtual int read()
		{
			return data[pos++] & 0xFF;
		}
		virtual void read(Pointer<JavaRawArray<byte>> data)
		{
			for (int i = 0; i < data->length; i++)
				data->assign(i, (byte)read());
		}
	private:
		std::vector<byte> data;
		size_t pos;
	};
}
