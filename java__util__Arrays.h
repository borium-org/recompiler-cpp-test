#pragma once

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	class Arrays : public Object
	{
	public:
		template <typename T> static void fill(Pointer<JavaRawArray<T>> array, T value)
		{
			for (int i = 0; i < array->length; i++)
				array->assign(i, value);
		}
	};
}
