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
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::io;
using namespace java::lang;
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
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<ConstantPool> temp_0009;
		temp_0009 = new ConstantPool();
		this->cp = temp_0009.getValue();
		return;
	}

	void ClassFile::read(Pointer<String> fileName)
	{
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
		this->in->close();
		return;
	}

	void ClassFile::readConstants()
	{
		this->cp->read(this->in);
		this->cp->verify(this->majorVersion, this->minorVersion);
		return;
	}

	void ClassFile::readID()
	{
		int magic_0008 = 0;
		Pointer<ClassFormatError> temp_0014;
		magic_0008 = this->in->u4();
		if ((magic_0008) == (-889275714))
			goto L0018;
		temp_0014 = new ClassFormatError(createString("CAFEBABE not found"));
		throw temp_0014;
	L0018: //
		return;
	}

	void ClassFile::readVersion()
	{
		Pointer<StringBuilder> temp_0030;
		Pointer<ClassFormatError> temp_0049;
		this->minorVersion = this->in->u2();
		this->majorVersion = this->in->u2();
		if ((this->majorVersion) != (60))
			goto L0026;
		if ((this->minorVersion) == 0)
			goto L004D;
	L0026: //
		temp_0030 = new StringBuilder(createString("Unsupported version "));
		temp_0049 = new ClassFormatError(temp_0030->append(this->majorVersion)->append(createString(":"))->append(this->minorVersion)->toString());
		throw temp_0049;
	L004D: //
		return;
	}

}
