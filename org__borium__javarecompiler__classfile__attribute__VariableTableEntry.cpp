#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__VariableTableEntry.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> VariableTableEntry::__thisClassStatic;

	void VariableTableEntry::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::VariableTableEntry",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	VariableTableEntry::VariableTableEntry(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		Object() //
		, startPc(0) //
		, length(0) //
		, nameIndex(0) //
		, descriptorIndex(0) //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		this->startPc = in->u2();
		this->length = in->u2();
		this->nameIndex = in->u2();
		this->name = cp->getString(this->nameIndex).getValue();
		this->descriptorIndex = in->u2();
		this->descriptor = cp->getString(this->descriptorIndex).getValue();
		this->index = in->u2();
		return;
	}

	void VariableTableEntry::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_000C;
		Pointer<StringBuilder> temp_0050;
		String::__ClassInit();
		temp_000C = new StringBuilder(String::valueOf(this->name.getValue()));
		stream->println(temp_000C->append(createString(": "))->append(this->descriptor)->toString());
		stream->indent(1);
		stream->iprint(createString("Start PC: "));
		stream->printHex(this->startPc, 4);
		stream->print(createString(", End PC: "));
		stream->printHex((this->startPc) + (this->length), 4);
		temp_0050 = new StringBuilder(createString(", Index: "));
		stream->print(temp_0050->append(this->index)->toString());
		stream->indent(-1);
		return;
	}

}
