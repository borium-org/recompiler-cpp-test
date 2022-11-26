#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ClassMethod.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__ClassAttribute.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeCode.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeSignature.h"
#include "org__borium__javarecompiler__classfile__attribute__ExceptionTable.h"
#include "org__borium__javarecompiler__classfile__attribute__VariableTableEntry.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"
#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ClassMethod::__thisClassStatic;

	int ClassMethod::AccessSynthetic = 4096;
	int ClassMethod::AccessStrict = 2048;
	int ClassMethod::AccessAbstract = 1024;
	int ClassMethod::AccessNative = 256;
	int ClassMethod::AccessVarArgs = 128;
	int ClassMethod::AccessBridge = 64;
	int ClassMethod::AccessSynchronized = 32;
	int ClassMethod::AccessFinal = 16;
	int ClassMethod::AccessStatic = 8;
	int ClassMethod::AccessProtected = 4;
	int ClassMethod::AccessPrivate = 2;
	int ClassMethod::AccessPublic = 1;

	void ClassMethod::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ClassMethod",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ClassMethod::ClassMethod() :
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

	void ClassMethod::addReferencedClasses(Pointer<ReferencedClasses> referencedClasses)
	{
		referencedClasses->add(this->getType());
		return;
	}

	void ClassMethod::dump(Pointer<IndentedOutputStream> stream, Pointer<ConstantPool> cp)
	{
		int flags_0044 = 0;
		int i_00F4 = 0;
		Pointer<ClassAttribute> attribute_011D;
		Pointer<StringBuilder> temp_0007;
		Pointer<StringBuilder> temp_00D9;
		Pointer<StringBuilder> temp_0101;
		Pointer<ClassAttribute> temp_0118;
		temp_0007 = new StringBuilder(createString("Method: "));
		stream->println(temp_0007->append(cp->getString(this->nameIndex))->append(createString(" "))->append(cp->getString(this->descriptorIndex))->toString());
		stream->indent(1);
		stream->iprint(createString("Access Flags: "));
		stream->printHex(this->accessFlags, 4);
		flags_0044 = this->accessFlags;
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 4096, createString(" Synthetic"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 2048, createString(" Strict"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 1024, createString(" Abstract"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 256, createString(" Native"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 128, createString(" VarArgs"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 64, createString(" Bridge"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 32, createString(" Synchronized"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 16, createString(" Final"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 8, createString(" Static"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 4, createString(" Protected"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 2, createString(" Private"));
		ClassFile::__ClassInit();
		flags_0044 = ClassFile::printAccessFlag(stream, flags_0044, 1, createString(" Public"));
		if ((flags_0044) == 0)
			goto L00CE;
		stream->print(createString(" Invalid "));
		stream->printHex(flags_0044, 4);
	L00CE: //
		stream->println();
		temp_00D9 = new StringBuilder(createString("Attributes: "));
		stream->iprintln(temp_00D9->append(this->attributes->size())->toString());
		stream->indent(1);
		i_00F4 = 0;
		goto L0126;
	L00F7: //
		String::__ClassInit();
		temp_0101 = new StringBuilder(String::valueOf(i_00F4));
		stream->iprint(temp_0101->append(createString(": "))->toString());
		temp_0118 = (ClassAttribute*)((this->attributeList->get(i_00F4)).getValue());
		temp_0118->checkCast(ClassAttribute::__thisClassStatic);
		attribute_011D = temp_0118;
		attribute_011D->dump(stream);
		i_00F4 += 1;
	L0126: //
		if ((i_00F4) < (this->attributes->size()))
			goto L00F7;
		stream->indent(-2);
		return;
	}

	Pointer<AttributeCode> ClassMethod::getCode()
	{
		Pointer<AttributeCode> code_000D;
		Pointer<AttributeCode> temp_0009;
		temp_0009 = (AttributeCode*)((this->attributes->get(createString("Code"))).getValue());
		temp_0009->checkCast(AttributeCode::__thisClassStatic);
		code_000D = temp_0009;
		return code_000D;
	}

	Pointer<String> ClassMethod::getDescriptor()
	{
		return this->descriptor;
	}

	Pointer<JavaArray<ExceptionTable>> ClassMethod::getExceptionTable()
	{
		Pointer<AttributeCode> code_000D;
		Pointer<AttributeCode> temp_0009;
		temp_0009 = (AttributeCode*)((this->attributes->get(createString("Code"))).getValue());
		temp_0009->checkCast(AttributeCode::__thisClassStatic);
		code_000D = temp_0009;
		return code_000D->getExceptionTable();
	}

	Pointer<JavaArray<Instruction>> ClassMethod::getInstructions()
	{
		Pointer<AttributeCode> code_000D;
		Pointer<AttributeCode> temp_0009;
		temp_0009 = (AttributeCode*)((this->attributes->get(createString("Code"))).getValue());
		temp_0009->checkCast(AttributeCode::__thisClassStatic);
		code_000D = temp_0009;
		return (((code_000D).getValue() != nullptr) ? (code_000D->getInstructions()) : ((JavaArray<Instruction>*)nullptr));
	}

	int ClassMethod::getLocalsCount()
	{
		Pointer<AttributeCode> code_000D;
		Pointer<AttributeCode> temp_0009;
		temp_0009 = (AttributeCode*)((this->attributes->get(createString("Code"))).getValue());
		temp_0009->checkCast(AttributeCode::__thisClassStatic);
		code_000D = temp_0009;
		return code_000D->getLocalsCount();
	}

	Pointer<JavaArray<VariableTableEntry>> ClassMethod::getLocalVariableTable()
	{
		Pointer<AttributeCode> code_000D;
		Pointer<AttributeCode> temp_0009;
		temp_0009 = (AttributeCode*)((this->attributes->get(createString("Code"))).getValue());
		temp_0009->checkCast(AttributeCode::__thisClassStatic);
		code_000D = temp_0009;
		return code_000D->getLocalVariableTable();
	}

	Pointer<String> ClassMethod::getName()
	{
		return this->name;
	}

	int ClassMethod::getParameterCount()
	{
		Statics::__ClassInit();
		return (Statics::getParameterCount(this->descriptor)) + (((this->isStatic()) ? (0) : (1)));
	}

	Pointer<String> ClassMethod::getType()
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

	bool ClassMethod::isAbstract()
	{
		if (((this->accessFlags) & (1024)) == 0)
			goto L000D;
		return 1;
	L000D: //
		return 0;
	}

	bool ClassMethod::isPresentInSource()
	{
		if (((this->accessFlags) & (4160)) == 0)
			goto L0025;
		Statics::__ClassInit();
		Statics::Assert((((((this->accessFlags) & (4160)) == (4160)) ? (1) : (0))) != 0, createString("Both Synthetic and Bridge expected"));
		return 0;
	L0025: //
		return 1;
	}

	bool ClassMethod::isStatic()
	{
		if (((this->accessFlags) & (8)) == 0)
			goto L000C;
		return 1;
	L000C: //
		return 0;
	}

	void ClassMethod::read(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp)
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
