#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class ClassFormatError;
	class Object;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class VerificationTypeInfo;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;

namespace org::borium::javarecompiler::classfile::attribute
{

	class StackMapFrame : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int frameType;
		int offsetDelta;
		Pointer<JavaArray<VerificationTypeInfo>> stack;
		Pointer<JavaArray<VerificationTypeInfo>> locals;

		static void __ClassInit();
		StackMapFrame(Pointer<ByteInputStream> in);
	};

}
