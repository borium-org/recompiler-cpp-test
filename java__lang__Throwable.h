#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Throwable : public Object
	{
	public:
		//	virtual ~Throwable()
		//	{
		//	}
		virtual void printStackTrace()
		{
			throw new std::exception();
		}
	protected:
		CString errorMessage;
	};
}
