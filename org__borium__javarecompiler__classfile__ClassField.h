#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
	class StringBuilder;
}

namespace java::util
{
	template <class A> class ArrayList;
	template <class A, class B> class HashMap;
	class Iterator;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class ClassAttribute;
	class ClassFile;
	class IndentedOutputStream;
	class ReferencedClasses;
}

namespace org::borium::javarecompiler::classfile::attribute
{
	class AttributeSignature;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantPool;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	class ClassField : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		static int AccessPublic;
		static int AccessPrivate;
		static int AccessProtected;
		static int AccessStatic;
		static int AccessFinal;
		static int AccessVolatile;
		static int AccessTransient;
		static int AccessSynthetic;
		static int AccessEnum;
		int accessFlags;
		int nameIndex;
		int descriptorIndex;
		Pointer<HashMap<String, ClassAttribute>> attributes;
		Pointer<ArrayList<ClassAttribute>> attributeList;
		Pointer<String> name;
		Pointer<String> descriptor;

		static void __ClassInit();
		ClassField();
		virtual void addReferencedClasses(Pointer<ReferencedClasses> referencedClasses);
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual int getAccessFlags();
		virtual Pointer<ClassAttribute> getAttribute(Pointer<String> attributeName);
		virtual Pointer<String> getName();
		virtual Pointer<String> getType();
		virtual void read(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp);
	};

}
