#pragma once

#include "java__lang__Exception.h"
#include "java__lang__String.h"

namespace java::lang
{
	class ClassFormatError : public Exception
	{
	public:
		ClassFormatError(const char* message)
		{
			this->message = message;
		}
		ClassFormatError(Pointer<String> message)
		{
			this->message = message->operator CString();
		}
	private:
		CString message;
	};
}
