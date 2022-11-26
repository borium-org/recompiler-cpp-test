#pragma once

#include "org__borium__javarecompiler__classfile__ClassAttribute.h"

namespace java::lang
{
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class ClassAttribute;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	class AttributeSignature : public ClassAttribute
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int signatureIndex;
		Pointer<String> signature;

		static void __ClassInit();
		AttributeSignature(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp);
		virtual Pointer<String> getSignature();
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual void decode(Pointer<ConstantPool> cp);
	};

}
