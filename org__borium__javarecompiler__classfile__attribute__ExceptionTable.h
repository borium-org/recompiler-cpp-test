#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantClassInfo;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	class ExceptionTable : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int startPc;
		int endPc;
		int handlerPc;
		int catchType;
		Pointer<ConstantClassInfo> catchClass;

		static void __ClassInit();
		ExceptionTable(Pointer<ByteInputStream> in);
		virtual Pointer<String> getExceptionClass();
		virtual void addLabels(Pointer<JavaRawArray<bool>> labels);
	};

}
