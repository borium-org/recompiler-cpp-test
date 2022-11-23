#pragma once

#include "java__io__FileInputStream.h"

namespace java::io
{

	class DataInputStream : public Object
	{
	public:
		DataInputStream(Pointer<FileInputStream> stream)
		{
			fis = stream;
		}
		virtual void close()
		{
			fis->close();
		}
		virtual int available()
		{
			return fis->available();
		}
		void read(Pointer<JavaRawArray<byte>> buffer)
		{
			for (int i = 0; i < buffer->length; i++)
				buffer->assign(i, fis->readByte());
		}
	private:
		Pointer<FileInputStream> fis;
	};

}
