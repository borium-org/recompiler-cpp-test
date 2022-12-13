#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class IOException;
}

namespace java::lang
{
	class Character;
	class Integer;
	class Object;
	class RuntimeException;
	class String;
	class StringBuffer;
	class StringBuilder;
}

namespace java::util
{
	template <class A, class B> class HashMap;
	class Iterator;
	template <class A> class TreeSet;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::classfile
{
	class ClassField;
	class ClassFile;
	class ClassMethod;
	class IndentedOutputStream;
	class ReferencedClasses;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppField;
	class CppMethod;
}

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class CppClass : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<ClassFile> classFile;
		Pointer<String> fileName;
		Pointer<String> className;
		Pointer<String> nameSpace;
		Pointer<JavaArray<CppField>> fields;
		Pointer<TreeSet<String>> namespaces;
		Pointer<TreeSet<String>> multipleClasses;
		Pointer<JavaArray<CppMethod>> methods;
		Pointer<String> parentClassName;
		Pointer<ReferencedClasses> referencedClasses;

		static void __ClassInit();
		CppClass(Pointer<ClassFile> classFile);
		virtual Pointer<CppField> getField(Pointer<String> fieldName);
		virtual Pointer<String> getFullClassName();
		virtual int getTemplateParameterCount(Pointer<String> fullClassName);
		virtual bool isAssignable(Pointer<String> source, Pointer<String> destination);
		virtual void writeClass(Pointer<String> outputPath);
		virtual Pointer<String> simplifyType(Pointer<String> className);
		virtual void generateHeader(Pointer<IndentedOutputStream> header);
		virtual void generateSource(Pointer<IndentedOutputStream> source);
		virtual void extractCppClassName();
		virtual void extractFields();
		virtual void extractMethods();
		virtual void extractNamespaces();
		virtual void extractParentClassName();
		virtual void generateHeaderBeginThisClassNamespace(Pointer<IndentedOutputStream> header);
		virtual void generateHeaderClassInitIfNeeded(Pointer<IndentedOutputStream> header);
		virtual void generateHeaderEndThisClassNamespace(Pointer<IndentedOutputStream> header);
		virtual void generateHeaderFields(Pointer<IndentedOutputStream> header);
		virtual void generateHeaderIncludesAndNamespaces(Pointer<IndentedOutputStream> header);
		virtual void generateHeaderJavaClass(Pointer<IndentedOutputStream> header);
		virtual void generateHeaderMethods(Pointer<IndentedOutputStream> header);
		virtual void generateSourceClassInitIfNeeded(Pointer<IndentedOutputStream> source);
		virtual void generateSourceIncludesAndNamespaces(Pointer<IndentedOutputStream> source);
		virtual void generateSourceJavaClass(Pointer<IndentedOutputStream> source);
		virtual void generateSourceMethods(Pointer<IndentedOutputStream> source);
		virtual void generateSourceStaticFields(Pointer<IndentedOutputStream> source);
		virtual Pointer<String> simplifyTypeComponent(Pointer<String> fullyQualifiedType);
	};

}
