#pragma once

#include "java__lang__Object.h"
//#include "java__lang__String.h"

using namespace java::lang;

namespace java::io
{
	class File : public Object
	{
	public:
		File(Pointer<String> fileName);
		virtual ~File();
		virtual bool exists();
		virtual bool isFile();
	private:
		CString fileName;
	};
}
