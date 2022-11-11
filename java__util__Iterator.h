#pragma once

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	class Iterator : public Object
	{
	public:
		virtual Pointer<Object> next() = 0;
		virtual bool hasNext() = 0;
	};
}
