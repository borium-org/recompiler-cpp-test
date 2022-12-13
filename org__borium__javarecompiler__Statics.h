#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Integer;
	class Object;
	class RuntimeException;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::cplusplus
{
	class JavaTypeConverter;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler
{

	class Statics : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:

		static void __ClassInit();
		Statics();
		static Pointer<String> addPointerIfNeeded(Pointer<String> type);
		static Pointer<String> addPointersIfNeeded(Pointer<String> methodType);
		static void Assert(bool condition, Pointer<String> errorMessage);
		static void Check(Pointer<IndentedOutputStream> stream, bool condition, Pointer<String> errorMessage);
		static Pointer<String> commaSeparatedList(Pointer<JavaArray<String>> values);
		static Pointer<String> dotToNamespace(Pointer<String> dots);
		static Pointer<String> escapeCharacters(Pointer<String> string);
		static int getParameterCount(Pointer<String> javaDescriptor);
		static Pointer<String> hexString(int value, int length);
		static bool isTemplate(Pointer<String> type);
		static Pointer<String> javaToCppClass(Pointer<String> javaClassName);
		static Pointer<String> parseJavaReturnType(Pointer<String> javaMethodSignature);
		static Pointer<String> removeJavaArray(Pointer<String> javaArray);
		static Pointer<String> removePointerWrapper(Pointer<String> wrappedObject);
		static void parseClass(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data);
		static void parseSingleType(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data);
	};

}
