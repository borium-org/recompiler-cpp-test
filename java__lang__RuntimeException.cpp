#include "stdafx.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"

namespace java::lang
{
	RuntimeException::RuntimeException(Pointer<String> message)
	{
		errorMessage = message->operator CString();
	}
}
