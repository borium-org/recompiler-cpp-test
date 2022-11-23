#include "stdafx.h"
#include "java__io__File.h"
#include "java__lang__String.h"

namespace java::io
{

	File::File(Pointer<String> fileName)
	{
		this->fileName = fileName->operator CString();
	}

	File::~File()
	{
	}

	bool File::exists()
	{
		DWORD attributes = GetFileAttributes(fileName);
		return attributes != INVALID_FILE_ATTRIBUTES;
	}

	bool File::isFile()
	{
		DWORD attributes = GetFileAttributes(fileName);
		return (attributes & FILE_ATTRIBUTE_DIRECTORY) == 0;
	}

}
