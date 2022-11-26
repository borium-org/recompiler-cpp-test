#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionWithLocalVariableIndex.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionWithLocalVariableIndex::__thisClassStatic;

	void InstructionWithLocalVariableIndex::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionWithLocalVariableIndex",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionWithLocalVariableIndex::InstructionWithLocalVariableIndex(Pointer<ByteInputStream> in, bool wide) :
		Instruction() //
		, index(0) //
		, indexConstantLength(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		this->indexConstantLength = ((wide) ? (2) : (1));
		this->index = ((wide) ? (in->u2()) : (in->u1()));
		return;
	}

	InstructionWithLocalVariableIndex::InstructionWithLocalVariableIndex(int index) :
		Instruction() //
		, index(0) //
		, indexConstantLength(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		this->indexConstantLength = 0;
		this->index = index;
		return;
	}

	void InstructionWithLocalVariableIndex::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		Pointer<String> className_0010;
		Pointer<StringBuilder> temp_0019;
		className_0010 = this->getClass()->getSimpleName()->substring(11)->toLowerCase();
		String::__ClassInit();
		temp_0019 = new StringBuilder(String::valueOf(className_0010.getValue()));
		stream->iprintln(temp_0019->append(createString(" "))->append(this->index)->toString());
		return;
	}

	int InstructionWithLocalVariableIndex::getIndex()
	{
		return this->index;
	}

	int InstructionWithLocalVariableIndex::length()
	{
		return (1) + (this->indexConstantLength);
	}

}
