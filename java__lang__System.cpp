#include "stdafx.h"
#include "java__lang__System.h"
#include "java__lang__Class.h"

namespace java::lang
{

	Pointer<Class> System::__thisClassStatic;

	Pointer<PrintStream> System::out;
	Pointer<PrintStream> System::err;

	void System::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"java::lang::System",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();

		out = new PrintStream(std::cout);
		err = new PrintStream(std::cerr);
	}

}
