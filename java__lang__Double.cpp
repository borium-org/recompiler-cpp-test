#include "stdafx.h"
#include "java__lang__Double.h"
#include "java__lang__String.h"

namespace java::lang
{
	double Double::longBitsToDouble(INT64 bits)
	{
		double value;
		INT64* ptr = (INT64*)&value;
		*ptr = bits;
		return value;
	}

	Pointer<String> Double::toString(double value)
	{
		CString string;
		string.Format("%G", value);
		return new String(string);
	}

}
