#pragma once

#include "java__io__PrintStream.h"

using namespace java::io;

namespace java::lang
{
	class System
	{
	public:
		static Pointer<Class> __thisClassStatic;
		static Pointer<PrintStream> out;
		static Pointer<PrintStream> err;
		//	static Pointer<PrintStream> err;
		static void __ClassInit();
	};
}
