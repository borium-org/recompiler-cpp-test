#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class RuntimeException;
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::classfile
{
	class ClassField;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class AttributeConstantValue;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class Constant;
	class ConstantInteger;
	class ConstantStringInfo;
}

namespace org::borium::javarecompiler::cplusplus
{
	class JavaTypeConverter;
}

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class CppField : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<String> name;
		Pointer<String> type;
		int accessFlags;
		Pointer<AttributeConstantValue> attributeConstantValue;

		static void __ClassInit();
		CppField(Pointer<ClassField> javaField);
		virtual void generateHeader(Pointer<IndentedOutputStream> header, Pointer<String> newType);
		virtual bool generateSource(Pointer<IndentedOutputStream> source, Pointer<String> className, Pointer<String> newType);
		virtual Pointer<String> getName();
		virtual Pointer<String> getType();
		virtual bool isFinal();
		virtual bool isPresentInSource();
		virtual bool isStatic();
	};

}
