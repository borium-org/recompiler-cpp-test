// recompiler-cpp-test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
#include "recompiler-cpp-test.h"
#include "java__lang__String.h"
#include "org__borium__javarecompiler__Recomp.h"

//using namespace java::lang;

using namespace org::borium::javarecompiler;

int main(int argc, char** argv)
{
	int nRetCode = 0;
	Pointer<JavaArray<String>> args = new JavaArray<String>(argc - 1);
	for (int i = 1; i < argc; i++)
		args[i - 1] = new String(argv[i]);
	Recomp::__ClassInit();
	Recomp::main(args);
	return nRetCode;
}
