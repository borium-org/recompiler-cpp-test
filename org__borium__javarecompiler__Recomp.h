#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class File;
	class PrintStream;
}

namespace java::lang
{
	class Object;
	class RuntimeException;
	class String;
	class StringBuilder;
	class System;
}

namespace java::util
{
	template <class A> class ArrayList;
	template <class A, class B> class HashMap;
	class Iterator;
}

namespace org::borium::javarecompiler::classfile
{
	class ClassFile;
}

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler
{

	class Recomp : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		static bool instructionComments;
		static bool stackComments;
		static bool dumpInstructions;
		static bool dumpStatements;
		static Pointer<HashMap<String, String>> simpleClassNames;
		Pointer<String> mainClass;
		Pointer<ArrayList<String>> classPaths;
		Pointer<String> outputPath;
		Pointer<String> visualStudio;

		static void __ClassInit();
		Recomp();
		static void main(Pointer<JavaArray<String>> args);
		virtual void addClassPath(Pointer<String> classPath);
		virtual void run();
		virtual void setMainClass(Pointer<String> mainClass);
		virtual void setOutputPath(Pointer<String> outputPath);
		virtual void setVisualStudio(Pointer<String> visualStudio);
		virtual Pointer<ClassFile> processClassFile(Pointer<String> classFileName);
		virtual void setCommentLevel(Pointer<String> commentLevel);
	};

}
