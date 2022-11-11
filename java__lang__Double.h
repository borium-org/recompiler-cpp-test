#pragma once

#include "java__lang__Object.h"

namespace java::lang
{

	class Double : public Object
	{
	public:
		//	static void ClassInit();
		static double longBitsToDouble(INT64 bits);
		static Pointer<String> toString(double value);
	};

}
