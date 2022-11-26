#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class DataInputStream;
	class FileInputStream;
	class IOException;
}

namespace java::lang
{
	class ClassFormatError;
	class Object;
	class String;
	class StringBuilder;
}

namespace java::util
{
	template <class A> class ArrayList;
	template <class A, class B> class HashMap;
}

namespace org::borium::javarecompiler
{
	class Recomp;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class ClassAttribute;
	class ClassField;
	class ClassMethod;
	class IndentedOutputStream;
	class ReferencedClasses;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantClassInfo;
	class ConstantPool;
}

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	class ClassFile : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<ByteInputStream> in;
		int majorVersion;
		int minorVersion;
		Pointer<ConstantPool> cp;
		int accessFlags;
		int thisClass;
		int superClass;
		Pointer<JavaRawArray<int>> interfaces;
		Pointer<JavaArray<ClassField>> fields;
		Pointer<JavaArray<ClassMethod>> methods;
		Pointer<HashMap<String, ClassAttribute>> attributes;
		Pointer<ArrayList<ClassAttribute>> attributeList;
		Pointer<String> className;
		Pointer<String> superClassName;

		static void __ClassInit();
		ClassFile();
		static int printAccessFlag(Pointer<IndentedOutputStream> stream, int flags, int bit, Pointer<String> string);
		virtual void addReferencedClasses(Pointer<ReferencedClasses> referencedClassNames);
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<String> getClassName();
		virtual Pointer<String> getClassSimpleName();
		virtual Pointer<JavaArray<ClassField>> getFields();
		virtual Pointer<String> getFieldType(Pointer<String> fieldName);
		virtual Pointer<ClassMethod> getMethod(Pointer<String> methodName, Pointer<String> methodDescriptor);
		virtual Pointer<JavaArray<ClassMethod>> getMethods();
		virtual Pointer<String> getParentClassName();
		virtual Pointer<ReferencedClasses> getReferencedClasses();
		virtual void read(Pointer<String> fileName);
		virtual void dumpAttributes(Pointer<IndentedOutputStream> stream);
		virtual void dumpClassInfo(Pointer<IndentedOutputStream> stream);
		virtual void dumpFields(Pointer<IndentedOutputStream> stream);
		virtual void dumpInterfaces(Pointer<IndentedOutputStream> stream);
		virtual void dumpMethods(Pointer<IndentedOutputStream> stream);
		virtual void readAttributes();
		virtual void readClassInfo();
		virtual void readConstants();
		virtual void readFields();
		virtual void readID();
		virtual void readInterfaces();
		virtual void readMethods();
		virtual void readVersion();
	};

}
