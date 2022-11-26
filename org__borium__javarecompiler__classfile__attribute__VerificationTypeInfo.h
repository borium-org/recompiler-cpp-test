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

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::attribute
{

	class VerificationTypeInfo : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		static int ITEM_Top;
		static int ITEM_Integer;
		static int ITEM_Float;
		static int ITEM_Double;
		static int ITEM_Long;
		static int ITEM_Null;
		static int ITEM_UninitializedThis;
		static int ITEM_Object;
		static int ITEM_Uninitialized;
		int tag;
		int cpoolIndex;
		int offset;

		static void __ClassInit();
		VerificationTypeInfo(Pointer<ByteInputStream> in);
	};

}
