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

using namespace java::io;
using namespace java::lang;

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
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

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
		return;
	}

}
