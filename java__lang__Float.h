#pragma once

#include "java__lang__Object.h"

namespace java::lang
{

	class Float : public Object
	{
	public:
		//	static void ClassInit();
		static float intBitsToFloat(int bits)
		{
			float value;
			int* ptr = (int*)&value;
			*ptr = bits;
			throw new std::exception("Float: intToBits: Verify bit ordering");
			return value;
		}
	private:
		float value;
	};

}
