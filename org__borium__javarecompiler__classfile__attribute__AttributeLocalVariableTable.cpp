#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeLocalVariableTable.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__attribute__VariableTableEntry.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> AttributeLocalVariableTable::__thisClassStatic;

	void AttributeLocalVariableTable::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::AttributeLocalVariableTable",
			org::borium::javarecompiler::classfile::ClassAttribute::__thisClassStatic);

		org::borium::javarecompiler::classfile::ClassAttribute::__ClassInit();
	}

	AttributeLocalVariableTable::AttributeLocalVariableTable(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp) :
		ClassAttribute(attribute) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		this->decode(cp);
		return;
	}

	Pointer<JavaArray<VariableTableEntry>> AttributeLocalVariableTable::getVariableTable()
	{
		return this->variableTable;
	}

	void AttributeLocalVariableTable::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		int i_001F = 0;
		Pointer<StringBuilder> temp_0007;
		Pointer<StringBuilder> temp_002B;
		temp_0007 = new StringBuilder(createString("Local Variables: "));
		stream->iprintln(temp_0007->append(this->variableTable->length)->toString());
		stream->indent(1);
		i_001F = 0;
		goto L004A;
	L0022: //
		String::__ClassInit();
		temp_002B = new StringBuilder(String::valueOf(i_001F));
		stream->iprint(temp_002B->append(createString(": "))->toString());
		this->variableTable->get(i_001F)->dump(stream);
		stream->println();
		i_001F += 1;
	L004A: //
		if ((i_001F) < (this->variableTable->length))
			goto L0022;
		stream->indent(-1);
		return;
	}

	void AttributeLocalVariableTable::decode(Pointer<ConstantPool> cp)
	{
		Pointer<ByteInputStream> in_000C;
		int variableTableLength_0011 = 0;
		int i_001C = 0;
		Pointer<ByteInputStream> temp_0008;
		Pointer<JavaArray<VariableTableEntry>> temp_0013;
		Pointer<VariableTableEntry> temp_002B;
		temp_0008 = new ByteInputStream(this->info);
		in_000C = temp_0008;
		variableTableLength_0011 = in_000C->u2();
		temp_0013 = new JavaArray<VariableTableEntry>(variableTableLength_0011);
		this->variableTable = temp_0013;
		i_001C = 0;
		goto L0032;
	L001F: //
		temp_002B = new VariableTableEntry(in_000C, cp);
		this->variableTable->assign(i_001C, temp_002B);
		i_001C += 1;
	L0032: //
		if ((i_001C) < (variableTableLength_0011))
			goto L001F;
		in_000C->close();
		return;
	}

}
