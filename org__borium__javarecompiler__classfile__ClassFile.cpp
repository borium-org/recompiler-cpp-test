#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__DataInputStream.h"
#include "java__io__FileInputStream.h"
#include "java__io__IOException.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"
#include "org__borium__javarecompiler__Recomp.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__ClassAttribute.h"
#include "org__borium__javarecompiler__classfile__ClassField.h"
#include "org__borium__javarecompiler__classfile__ClassMethod.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ClassFile::__thisClassStatic;

	void ClassFile::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ClassFile",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ClassFile::ClassFile() :
		Object() //
		, majorVersion(0) //
		, minorVersion(0) //
		, accessFlags(0) //
		, thisClass(0) //
		, superClass(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<ConstantPool> temp_0009;
		Pointer<HashMap<Object, Object>> temp_0014;
		Pointer<ArrayList<Object>> temp_001F;
		temp_0009 = new ConstantPool();
		this->cp = temp_0009.getValue();
		temp_0014 = new HashMap<Object, Object>();
		this->attributes = (HashMap<String, ClassAttribute>*)temp_0014.getValue();
		temp_001F = new ArrayList<Object>();
		this->attributeList = (ArrayList<ClassAttribute>*)temp_001F.getValue();
		return;
	}

	int ClassFile::printAccessFlag(Pointer<IndentedOutputStream> stream, int flags, int bit, Pointer<String> string)
	{
		__ClassInit();

		if (((flags) & (bit)) == 0)
			goto L000B;
		stream->print(string);
	L000B: //
		flags = (flags) & ((bit) ^ (-1));
		return flags;
	}

	void ClassFile::addReferencedClasses(Pointer<ReferencedClasses> referencedClassNames)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->cp->addReferencedClasses(referencedClassNames);
		referencedClassNames->removeClass(this->getClassName());
		referencedClassNames->removeClass(this->getParentClassName());
		return;
	}

	void ClassFile::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		Pointer<StringBuilder> temp_001E;
		Pointer<StringBuilder> temp_0035;
		temp_0007 = new StringBuilder(createString("Class: "));
		stream->println(temp_0007->append(this->className)->toString());
		temp_001E = new StringBuilder(createString("Major Version: "));
		stream->println(temp_001E->append(this->majorVersion)->toString());
		temp_0035 = new StringBuilder(createString("Minor Version: "));
		stream->println(temp_0035->append(this->minorVersion)->toString());
		this->cp->dump(stream);
		this->dumpClassInfo(stream);
		this->dumpInterfaces(stream);
		this->dumpFields(stream);
		this->dumpMethods(stream);
		this->dumpAttributes(stream);
		return;
	}

	Pointer<String> ClassFile::getClassName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->className->replace('/', '.');
	}

	Pointer<String> ClassFile::getClassSimpleName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->className->substring((this->className->lastIndexOf(46)) + (1));
	}

	Pointer<JavaArray<ClassField>> ClassFile::getFields()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->fields;
	}

	Pointer<String> ClassFile::getFieldType(Pointer<String> fieldName)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ClassField> field_0014;
		Pointer<ClassFile> superClass_003B;
		Pointer<JavaArray<ClassField>> local_0005;
		int local_0008 = 0;
		int local_000B = 0;
		Pointer<ClassFile> temp_0037;
		local_0005 = (JavaArray<ClassField>*)(this->fields.getValue());
		local_0008 = this->fields->length;
		local_000B = 0;
		goto L0027;
	L000F: //
		field_0014 = local_0005->get(local_000B);
		if (!(field_0014->getName()->equals(fieldName.getValue())))
			goto L0024;
		return field_0014->getType();
	L0024: //
		local_000B += 1;
	L0027: //
		if ((local_000B) < (local_0008))
			goto L000F;
		Recomp::__ClassInit();
		temp_0037 = (ClassFile*)((Recomp::processedClasses->get(this->superClassName.getValue())).getValue());
		temp_0037->checkCast(ClassFile::__thisClassStatic);
		superClass_003B = temp_0037;
		if ((superClass_003B).getValue() != nullptr)
			goto L0041;
		// ARETURN: Type mismatch
		return (String*)nullptr;
	L0041: //
		return superClass_003B->getFieldType(fieldName);
	}

	Pointer<ClassMethod> ClassFile::getMethod(Pointer<String> methodName, Pointer<String> methodDescriptor)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ClassMethod> method_0016;
		Pointer<ClassFile> superClass_0046;
		Pointer<JavaArray<ClassMethod>> local_0005;
		int local_0008 = 0;
		int local_000B = 0;
		Pointer<ClassFile> temp_0042;
		local_0005 = (JavaArray<ClassMethod>*)(this->methods.getValue());
		local_0008 = this->methods->length;
		local_000B = 0;
		goto L0031;
	L0010: //
		method_0016 = local_0005->get(local_000B);
		if (!(method_0016->getName()->equals(methodName.getValue())))
			goto L002E;
		if (!(method_0016->getDescriptor()->equals(methodDescriptor.getValue())))
			goto L002E;
		return method_0016;
	L002E: //
		local_000B += 1;
	L0031: //
		if ((local_000B) < (local_0008))
			goto L0010;
		Recomp::__ClassInit();
		temp_0042 = (ClassFile*)((Recomp::processedClasses->get(this->superClassName.getValue())).getValue());
		temp_0042->checkCast(ClassFile::__thisClassStatic);
		superClass_0046 = temp_0042;
		if ((superClass_0046).getValue() != nullptr)
			goto L004C;
		// ARETURN: Type mismatch
		return (ClassMethod*)nullptr;
	L004C: //
		return superClass_0046->getMethod(methodName, methodDescriptor);
	}

	Pointer<JavaArray<ClassMethod>> ClassFile::getMethods()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->methods;
	}

	Pointer<String> ClassFile::getParentClassName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->superClassName;
	}

	Pointer<ReferencedClasses> ClassFile::getReferencedClasses()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ReferencedClasses> referencedClasses_000C;
		Pointer<ClassField> field_0020;
		Pointer<ClassMethod> method_0042;
		Pointer<ReferencedClasses> temp_0008;
		Pointer<JavaArray<ClassField>> local_0011;
		int local_0014 = 0;
		int local_0017 = 0;
		Pointer<JavaArray<ClassMethod>> local_0033;
		temp_0008 = new ReferencedClasses(this->cp);
		referencedClasses_000C = temp_0008;
		local_0011 = (JavaArray<ClassField>*)(this->fields.getValue());
		local_0014 = this->fields->length;
		local_0017 = 0;
		goto L0028;
	L001B: //
		field_0020 = local_0011->get(local_0017);
		field_0020->addReferencedClasses(referencedClasses_000C);
		local_0017 += 1;
	L0028: //
		if ((local_0017) < (local_0014))
			goto L001B;
		local_0033 = (JavaArray<ClassMethod>*)(this->methods.getValue());
		local_0014 = this->methods->length;
		local_0017 = 0;
		goto L004A;
	L003D: //
		method_0042 = local_0033->get(local_0017);
		method_0042->addReferencedClasses(referencedClasses_000C);
		local_0017 += 1;
	L004A: //
		if ((local_0017) < (local_0014))
			goto L003D;
		referencedClasses_000C->removeClass(this->getClassName());
		return referencedClasses_000C;
	}

	void ClassFile::read(Pointer<String> fileName)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<String>> directories_0007;
		int index_0009 = 0;
		Pointer<String> classFileName_0032;
		Pointer<DataInputStream> dataIn_0091;
		Pointer<JavaRawArray<byte>> data_009A;
		Pointer<StringBuilder> temp_003E;
		Pointer<FileInputStream> temp_0089;
		Pointer<DataInputStream> temp_008C;
		Pointer<JavaRawArray<byte>> temp_0096;
		Pointer<ByteInputStream> temp_00AE;
		directories_0007 = (JavaArray<String>*)(fileName->split(createString("[/]")).getValue());
		index_0009 = 0;
		goto L0020;
	L000C: //
		if (!(directories_0007->get(index_0009)->equals(createString("bin"))))
			goto L001D;
		index_0009 += 1;
		goto L0026;
	L001D: //
		index_0009 += 1;
	L0020: //
		if ((index_0009) < (directories_0007->length))
			goto L000C;
	L0026: //
		if ((index_0009) != (directories_0007->length))
			goto L002E;
		index_0009 = 0;
	L002E: //
		classFileName_0032 = createString("");
		goto L0061;
	L0035: //
		String::__ClassInit();
		temp_003E = new StringBuilder(String::valueOf(classFileName_0032.getValue()));
		classFileName_0032 = temp_003E->append((((classFileName_0032->length()) > 0) ? (((Pointer<String>) new String("/"))) : (((Pointer<String>) new String("")))))->append(directories_0007->get(index_0009))->toString();
		index_0009 += 1;
	L0061: //
		if ((index_0009) < (directories_0007->length))
			goto L0035;
		this->className = classFileName_0032->substring(0, (classFileName_0032->length()) - (6))->replace('/', '.').getValue();
		temp_0089 = new FileInputStream(fileName);
		temp_008C = new DataInputStream(temp_0089.getValue());
		dataIn_0091 = temp_008C;
		temp_0096 = new JavaRawArray<byte>(dataIn_0091->available());
		data_009A = (JavaRawArray<byte>*)(temp_0096.getValue());
		dataIn_0091->read(data_009A);
		dataIn_0091->close();
		temp_00AE = new ByteInputStream(data_009A);
		this->in = temp_00AE.getValue();
		this->readID();
		this->readVersion();
		this->readConstants();
		this->readClassInfo();
		this->readInterfaces();
		this->readFields();
		this->readMethods();
		this->readAttributes();
		this->in->close();
		return;
	}

	void ClassFile::dumpAttributes(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_0022 = 0;
		Pointer<ClassAttribute> attribute_0049;
		Pointer<StringBuilder> temp_0008;
		Pointer<StringBuilder> temp_002E;
		Pointer<ClassAttribute> temp_0045;
		temp_0008 = new StringBuilder(createString("Attributes: "));
		stream->println(temp_0008->append(this->attributeList->size())->toString());
		stream->indent(1);
		i_0022 = 0;
		goto L0051;
	L0025: //
		String::__ClassInit();
		temp_002E = new StringBuilder(String::valueOf(i_0022));
		stream->iprint(temp_002E->append(createString(": "))->toString());
		temp_0045 = (ClassAttribute*)((this->attributeList->get(i_0022)).getValue());
		temp_0045->checkCast(ClassAttribute::__thisClassStatic);
		attribute_0049 = temp_0045;
		attribute_0049->dump(stream);
		i_0022 += 1;
	L0051: //
		if ((i_0022) < (this->attributeList->size()))
			goto L0025;
		stream->indent(-1);
		return;
	}

	void ClassFile::dumpClassInfo(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int flags_0015 = 0;
		Pointer<ConstantClassInfo> thisClassInfo_00BF;
		Pointer<ConstantClassInfo> superClassInfo_0107;
		Pointer<StringBuilder> temp_009A;
		Pointer<ConstantClassInfo> temp_00BB;
		Pointer<StringBuilder> temp_00D0;
		Pointer<ConstantClassInfo> temp_0102;
		stream->print(createString("Access Flags: "));
		stream->printHex(this->accessFlags, 4);
		flags_0015 = this->accessFlags;
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 32768, createString(" Module"));
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 16384, createString(" Enum"));
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 8192, createString(" Annotation"));
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 4096, createString(" Synthetic"));
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 1024, createString(" Abstract"));
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 512, createString(" Interface"));
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 32, createString(" Super"));
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 16, createString(" Final"));
		ClassFile::__ClassInit();
		flags_0015 = ClassFile::printAccessFlag(stream, flags_0015, 1, createString(" Public"));
		if ((flags_0015) == 0)
			goto L008E;
		stream->print(createString(" Invalid "));
		stream->printHex(flags_0015, 4);
	L008E: //
		stream->println();
		temp_009A = new StringBuilder(createString("This Class: "));
		stream->print(temp_009A->append(this->thisClass)->append(createString(" "))->toString());
		temp_00BB = (ConstantClassInfo*)((this->cp->get(this->thisClass)).getValue());
		temp_00BB->checkCast(ConstantClassInfo::__thisClassStatic);
		thisClassInfo_00BF = temp_00BB;
		thisClassInfo_00BF->dump(stream);
		stream->println();
		temp_00D0 = new StringBuilder(createString("Super Class: "));
		stream->print(temp_00D0->append(this->superClass)->append(createString(" "))->toString());
		if ((this->superClass) != 0)
			goto L00F7;
		stream->print(createString("<None>"));
		goto L010D;
	L00F7: //
		temp_0102 = (ConstantClassInfo*)((this->cp->get(this->superClass)).getValue());
		temp_0102->checkCast(ConstantClassInfo::__thisClassStatic);
		superClassInfo_0107 = temp_0102;
		superClassInfo_0107->dump(stream);
	L010D: //
		stream->println();
		return;
	}

	void ClassFile::dumpFields(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_0020 = 0;
		Pointer<ClassField> field_0042;
		Pointer<StringBuilder> temp_0008;
		Pointer<StringBuilder> temp_002C;
		temp_0008 = new StringBuilder(createString("Fields: "));
		stream->println(temp_0008->append(this->fields->length)->toString());
		stream->indent(1);
		i_0020 = 0;
		goto L004A;
	L0023: //
		String::__ClassInit();
		temp_002C = new StringBuilder(String::valueOf(i_0020));
		stream->iprint(temp_002C->append(createString(": "))->toString());
		field_0042 = this->fields->get(i_0020);
		field_0042->dump(stream);
		i_0020 += 1;
	L004A: //
		if ((i_0020) < (this->fields->length))
			goto L0023;
		stream->indent(-1);
		return;
	}

	void ClassFile::dumpInterfaces(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_0020 = 0;
		Pointer<ConstantClassInfo> classInfo_004C;
		Pointer<StringBuilder> temp_0008;
		Pointer<StringBuilder> temp_002C;
		Pointer<ConstantClassInfo> temp_0048;
		temp_0008 = new StringBuilder(createString("Interfaces: "));
		stream->println(temp_0008->append(this->interfaces->length)->toString());
		stream->indent(1);
		i_0020 = 0;
		goto L0058;
	L0023: //
		String::__ClassInit();
		temp_002C = new StringBuilder(String::valueOf(i_0020));
		stream->iprint(temp_002C->append(createString(": "))->toString());
		temp_0048 = (ConstantClassInfo*)((this->cp->get(this->interfaces->get(i_0020))).getValue());
		temp_0048->checkCast(ConstantClassInfo::__thisClassStatic);
		classInfo_004C = temp_0048;
		classInfo_004C->dump(stream);
		stream->println();
		i_0020 += 1;
	L0058: //
		if ((i_0020) < (this->interfaces->length))
			goto L0023;
		stream->indent(-1);
		return;
	}

	void ClassFile::dumpMethods(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_0020 = 0;
		Pointer<ClassMethod> method_0042;
		Pointer<StringBuilder> temp_0008;
		Pointer<StringBuilder> temp_002C;
		temp_0008 = new StringBuilder(createString("Methods: "));
		stream->println(temp_0008->append(this->methods->length)->toString());
		stream->indent(1);
		i_0020 = 0;
		goto L004E;
	L0023: //
		String::__ClassInit();
		temp_002C = new StringBuilder(String::valueOf(i_0020));
		stream->iprint(temp_002C->append(createString(": "))->toString());
		method_0042 = this->methods->get(i_0020);
		method_0042->dump(stream, this->cp);
		i_0020 += 1;
	L004E: //
		if ((i_0020) < (this->methods->length))
			goto L0023;
		stream->indent(-1);
		return;
	}

	void ClassFile::readAttributes()
	{
		UsageCounterMaintainer maintainer(this, true);

		int attributeCount_0008 = 0;
		int i_000A = 0;
		Pointer<ClassAttribute> attribute_0019;
		attributeCount_0008 = this->in->u2();
		i_000A = 0;
		goto L0032;
	L000D: //
		ClassAttribute::__ClassInit();
		attribute_0019 = ClassAttribute::readAttribute(this->in, this->cp);
		this->attributes->put(attribute_0019->getName().getValue(), attribute_0019.getValue());
		this->attributeList->add(attribute_0019.getValue());
		i_000A += 1;
	L0032: //
		if ((i_000A) < (attributeCount_0008))
			goto L000D;
		return;
	}

	void ClassFile::readClassInfo()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ConstantClassInfo> ci_0030;
		Pointer<ConstantClassInfo> temp_002C;
		this->accessFlags = this->in->u2();
		this->thisClass = this->in->u2();
		this->superClass = this->in->u2();
		temp_002C = (ConstantClassInfo*)((this->cp->get(this->superClass)).getValue());
		temp_002C->checkCast(ConstantClassInfo::__thisClassStatic);
		ci_0030 = temp_002C;
		this->superClassName = this->cp->getString(ci_0030->nameIndex)->replace('/', '.').getValue();
		return;
	}

	void ClassFile::readConstants()
	{
		UsageCounterMaintainer maintainer(this, true);

		this->cp->read(this->in);
		this->cp->verify(this->majorVersion, this->minorVersion);
		return;
	}

	void ClassFile::readFields()
	{
		UsageCounterMaintainer maintainer(this, true);

		int count_0008 = 0;
		int i_0012 = 0;
		Pointer<ClassField> field_001D;
		Pointer<JavaArray<ClassField>> temp_000A;
		Pointer<ClassField> temp_0019;
		count_0008 = this->in->u2();
		temp_000A = new JavaArray<ClassField>(count_0008);
		this->fields = temp_000A;
		i_0012 = 0;
		goto L0033;
	L0015: //
		temp_0019 = new ClassField();
		field_001D = temp_0019;
		field_001D->read(this->in, this->cp);
		this->fields->assign(i_0012, field_001D);
		i_0012 += 1;
	L0033: //
		if ((i_0012) < (count_0008))
			goto L0015;
		return;
	}

	void ClassFile::readID()
	{
		UsageCounterMaintainer maintainer(this, true);

		int magic_0008 = 0;
		Pointer<ClassFormatError> temp_0016;
		magic_0008 = this->in->u4();
		if ((magic_0008) == (-889275714))
			goto L001A;
		temp_0016 = new ClassFormatError(createString("CAFEBABE not found"));
		throw temp_0016;
	L001A: //
		return;
	}

	void ClassFile::readInterfaces()
	{
		UsageCounterMaintainer maintainer(this, true);

		int count_0008 = 0;
		int i_0011 = 0;
		Pointer<JavaRawArray<int>> temp_000A;
		count_0008 = this->in->u2();
		temp_000A = new JavaRawArray<int>(count_0008);
		this->interfaces = temp_000A;
		i_0011 = 0;
		goto L0024;
	L0014: //
		this->interfaces->assign(i_0011, this->in->u2());
		i_0011 += 1;
	L0024: //
		if ((i_0011) < (count_0008))
			goto L0014;
		return;
	}

	void ClassFile::readMethods()
	{
		UsageCounterMaintainer maintainer(this, true);

		int count_0008 = 0;
		int i_0012 = 0;
		Pointer<ClassMethod> method_001D;
		Pointer<JavaArray<ClassMethod>> temp_000A;
		Pointer<ClassMethod> temp_0019;
		count_0008 = this->in->u2();
		temp_000A = new JavaArray<ClassMethod>(count_0008);
		this->methods = temp_000A;
		i_0012 = 0;
		goto L0033;
	L0015: //
		temp_0019 = new ClassMethod();
		method_001D = temp_0019;
		method_001D->read(this->in, this->cp);
		this->methods->assign(i_0012, method_001D);
		i_0012 += 1;
	L0033: //
		if ((i_0012) < (count_0008))
			goto L0015;
		return;
	}

	void ClassFile::readVersion()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0031;
		Pointer<ClassFormatError> temp_004B;
		this->minorVersion = this->in->u2();
		this->majorVersion = this->in->u2();
		if ((this->majorVersion) != (60))
			goto L0026;
		if ((this->minorVersion) == 0)
			goto L004F;
	L0026: //
		temp_0031 = new StringBuilder(createString("Unsupported version "));
		temp_004B = new ClassFormatError(temp_0031->append(this->majorVersion)->append(createString(":"))->append(this->minorVersion)->toString());
		throw temp_004B;
	L004F: //
		return;
	}

}
