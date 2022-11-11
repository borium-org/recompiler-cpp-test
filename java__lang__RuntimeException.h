#pragma once

#include "java__lang__Throwable.h"

namespace java::lang
{

	class RuntimeException : public Throwable
	{
	public:
		//	//RuntimeException();
		RuntimeException(Pointer<String> message);
		//	virtual ~RuntimeException();
	};

}
