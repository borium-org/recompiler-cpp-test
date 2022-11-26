#pragma once

#include "org__borium__javarecompiler__classfile__ClassAttribute.h"

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class ClassAttribute;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class Constant;
	class ConstantPool;
}

using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	class AttributeConstantValue : public ClassAttribute
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<Constant> constantValue;

		static void __ClassInit();
		AttributeConstantValue(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp);
		virtual Pointer<Constant> getConstant();
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual void decode(Pointer<ConstantPool> cp);
	};

}
