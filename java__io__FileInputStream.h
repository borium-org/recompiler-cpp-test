#pragma once

#include "java__lang__Object.h"
#include "java__lang__String.h"

namespace java::io
{

	class FileInputStream : public Object
	{
	public:
		FileInputStream(Pointer<String> fileName)
		{
			is.open(fileName->operator CString(), std::ifstream::in | std::ifstream::binary);
		}
		virtual void close()
		{
			is.close();
		}
		virtual int available()
		{
			std::streampos pos = is.tellg();
			is.seekg(0, is.end);
			std::streampos end = is.tellg();
			is.seekg(pos, is.beg);
			return (int)(end - pos);
		}
		byte readByte()
		{
			return (byte)is.get();
		}
		//	virtual void read(Pointer<JavaArray<byte>> data);
	private:
		std::ifstream is;
	};

}
