#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ClassField.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"
#include "java__util__Iterator.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__ClassAttribute.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeSignature.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ClassField::__thisClassStatic;

	int ClassField::AccessPublic = 1;
	int ClassField::AccessPrivate = 2;
	int ClassField::AccessProtected = 4;
	int ClassField::AccessStatic = 8;
	int ClassField::AccessFinal = 16;
	int ClassField::AccessVolatile = 64;
	int ClassField::AccessTransient = 128;
	int ClassField::AccessSynthetic = 4096;
	int ClassField::AccessEnum = 16384;

	void ClassField::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ClassField",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ClassField::ClassField() :
		Object() //
		, accessFlags(0) //
		, nameIndex(0) //
		, descriptorIndex(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<HashMap<Object, Object>> temp_0009;
		Pointer<ArrayList<Object>> temp_0014;
		temp_0009 = new HashMap<Object, Object>();
		this->attributes = (HashMap<String, ClassAttribute>*)temp_0009.getValue();
		temp_0014 = new ArrayList<Object>();
		this->attributeList = (ArrayList<ClassAttribute>*)temp_0014.getValue();
		return;
	}

	void ClassField::addReferencedClasses(Pointer<ReferencedClasses> referencedClasses)
	{
		referencedClasses->add(this->getType());
		return;
	}

	void ClassField::dump(Pointer<IndentedOutputStream> stream)
	{
		int flags_003C = 0;
		int i_00CB = 0;
		Pointer<ClassAttribute> attribute_00F2;
		Pointer<StringBuilder> temp_0007;
		Pointer<StringBuilder> temp_00B1;
		Pointer<StringBuilder> temp_00D7;
		Pointer<ClassAttribute> temp_00ED;
		temp_0007 = new StringBuilder(createString("Field: "));
		stream->println(temp_0007->append(this->name)->append(createString(" "))->append(this->descriptor)->toString());
		stream->indent(1);
		stream->iprint(createString("Access Flags: "));
		stream->printHex(this->accessFlags, 4);
		flags_003C = this->accessFlags;
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 16384, createString(" Enum"));
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 4096, createString(" Synthetic"));
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 128, createString(" Transient"));
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 64, createString(" Volatile"));
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 16, createString(" Final"));
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 8, createString(" Static"));
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 4, createString(" Protected"));
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 2, createString(" Private"));
		ClassFile::__ClassInit();
		flags_003C = ClassFile::printAccessFlag(stream, flags_003C, 1, createString(" Public"));
		if ((flags_003C) == 0)
			goto L00A6;
		stream->print(createString(" Invalid "));
		stream->printHex(flags_003C, 4);
	L00A6: //
		stream->println();
		temp_00B1 = new StringBuilder(createString("Attributes: "));
		stream->iprintln(temp_00B1->append(this->attributes->size())->toString());
		stream->indent(1);
		i_00CB = 0;
		goto L00FB;
	L00CE: //
		String::__ClassInit();
		temp_00D7 = new StringBuilder(String::valueOf(i_00CB));
		stream->iprint(temp_00D7->append(createString(": "))->toString());
		temp_00ED = (ClassAttribute*)((this->attributeList->get(i_00CB)).getValue());
		temp_00ED->checkCast(ClassAttribute::__thisClassStatic);
		attribute_00F2 = temp_00ED;
		attribute_00F2->dump(stream);
		i_00CB += 1;
	L00FB: //
		if ((i_00CB) < (this->attributes->size()))
			goto L00CE;
		stream->indent(-2);
		return;
	}

	int ClassField::getAccessFlags()
	{
		return this->accessFlags;
	}

	Pointer<ClassAttribute> ClassField::getAttribute(Pointer<String> attributeName)
	{
		Pointer<ClassAttribute> a_0015;
		Pointer<Iterator> local_0007;
		Pointer<ClassAttribute> temp_0011;
		local_0007 = this->attributeList->iterator();
		goto L0022;
	L000B: //
		temp_0011 = (ClassAttribute*)((local_0007->next()).getValue());
		temp_0011->checkCast(ClassAttribute::__thisClassStatic);
		a_0015 = temp_0011;
		if (!(a_0015->getName()->equals(attributeName.getValue())))
			goto L0022;
		return a_0015;
	L0022: //
		if (local_0007->hasNext())
			goto L000B;
		// ARETURN: Type mismatch
		return (ClassAttribute*)nullptr;
	}

	Pointer<String> ClassField::getName()
	{
		return this->name;
	}

	Pointer<String> ClassField::getType()
	{
		Pointer<AttributeSignature> sig_0019;
		Pointer<AttributeSignature> temp_0015;
		if (!(this->attributes->containsKey(createString("Signature"))))
			goto L001E;
		temp_0015 = (AttributeSignature*)((this->attributes->get(createString("Signature"))).getValue());
		temp_0015->checkCast(AttributeSignature::__thisClassStatic);
		sig_0019 = temp_0015;
		return sig_0019->getSignature();
	L001E: //
		return this->descriptor;
	}

	void ClassField::read(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp)
	{
		int attributeCount_0035 = 0;
		int i_0038 = 0;
		Pointer<ClassAttribute> attribute_0042;
		this->accessFlags = in->u2();
		this->nameIndex = in->u2();
		this->name = cp->getString(this->nameIndex).getValue();
		this->descriptorIndex = in->u2();
		this->descriptor = cp->getString(this->descriptorIndex).getValue();
		attributeCount_0035 = in->u2();
		i_0038 = 0;
		goto L005E;
	L003B: //
		ClassAttribute::__ClassInit();
		attribute_0042 = ClassAttribute::readAttribute(in, cp);
		this->attributes->put(attribute_0042->getName().getValue(), attribute_0042.getValue());
		this->attributeList->add(attribute_0042.getValue());
		i_0038 += 1;
	L005E: //
		if ((i_0038) < (attributeCount_0035))
			goto L003B;
		return;
	}

}
