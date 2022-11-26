#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeCode.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeLocalVariableTable.h"
#include "org__borium__javarecompiler__classfile__attribute__AttributeLocalVariableTypeTable.h"
#include "org__borium__javarecompiler__classfile__attribute__ExceptionTable.h"
#include "org__borium__javarecompiler__classfile__attribute__LocalVariableType.h"
#include "org__borium__javarecompiler__classfile__attribute__VariableTableEntry.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"
#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::constants;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> AttributeCode::__thisClassStatic;

	void AttributeCode::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::AttributeCode",
			org::borium::javarecompiler::classfile::ClassAttribute::__thisClassStatic);

		org::borium::javarecompiler::classfile::ClassAttribute::__ClassInit();
	}

	AttributeCode::AttributeCode(Pointer<ClassAttribute> attribute, Pointer<ConstantPool> cp) :
		ClassAttribute(attribute) //
		, maxStack(0) //
		, maxLocals(0) //
		, codeLength(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<HashMap<Object, Object>> temp_000A;
		Pointer<ArrayList<Object>> temp_0015;
		temp_000A = new HashMap<Object, Object>();
		this->attributes = (HashMap<String, ClassAttribute>*)temp_000A.getValue();
		temp_0015 = new ArrayList<Object>();
		this->attributeList = (ArrayList<ClassAttribute>*)temp_0015.getValue();
		this->decode(cp);
		return;
	}

	Pointer<JavaArray<ExceptionTable>> AttributeCode::getExceptionTable()
	{
		return this->exceptionTable;
	}

	Pointer<JavaArray<Instruction>> AttributeCode::getInstructions()
	{
		return this->instructions;
	}

	Pointer<JavaRawArray<bool>> AttributeCode::getLabels()
	{
		return this->labels;
	}

	int AttributeCode::getLength()
	{
		return this->codeLength;
	}

	int AttributeCode::getLocalsCount()
	{
		return this->maxLocals;
	}

	Pointer<JavaArray<VariableTableEntry>> AttributeCode::getLocalVariableTable()
	{
		Pointer<AttributeLocalVariableTable> table_000D;
		Pointer<JavaArray<VariableTableEntry>> entries_0012;
		Pointer<AttributeLocalVariableTypeTable> types_001F;
		Pointer<AttributeLocalVariableTable> temp_0009;
		Pointer<AttributeLocalVariableTypeTable> temp_001B;
		temp_0009 = (AttributeLocalVariableTable*)((this->attributes->get(createString("LocalVariableTable"))).getValue());
		temp_0009->checkCast(AttributeLocalVariableTable::__thisClassStatic);
		table_000D = temp_0009;
		entries_0012 = (JavaArray<VariableTableEntry>*)(table_000D->getVariableTable().getValue());
		temp_001B = (AttributeLocalVariableTypeTable*)((this->attributes->get(createString("LocalVariableTypeTable"))).getValue());
		temp_001B->checkCast(AttributeLocalVariableTypeTable::__thisClassStatic);
		types_001F = temp_001B;
		if ((types_001F).getValue() == nullptr)
			goto L002C;
		this->updateEntries(entries_0012, types_001F->getLocalVariableTypes());
	L002C: //
		return entries_0012;
	}

	void AttributeCode::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		int address_005F = 0;
		int length_0090 = 0;
		int i_00EC = 0;
		Pointer<ConstantClassInfo> ci_0166;
		int i_019F = 0;
		Pointer<StringBuilder> temp_000C;
		Pointer<StringBuilder> temp_0023;
		Pointer<StringBuilder> temp_003A;
		Pointer<StringBuilder> temp_00D9;
		Pointer<StringBuilder> temp_00FD;
		Pointer<StringBuilder> temp_018A;
		Pointer<StringBuilder> temp_01B0;
		Pointer<ClassAttribute> temp_01C6;
		stream->indent(1);
		temp_000C = new StringBuilder(createString("Stack: "));
		stream->iprintln(temp_000C->append(this->maxStack)->toString());
		temp_0023 = new StringBuilder(createString("Locals: "));
		stream->iprintln(temp_0023->append(this->maxLocals)->toString());
		temp_003A = new StringBuilder(createString("Code length: "));
		stream->iprintln(temp_003A->append(this->code->length)->toString());
		stream->indent(1);
		stream->iprintln(this->code);
		stream->indent(-1);
		address_005F = 0;
		goto L00C9;
	L0062: //
		if (!(this->labels->get(address_005F)))
			goto L007D;
		stream->iprint(createString("L"));
		stream->printHex(address_005F, 4);
		stream->println(createString(":"));
	L007D: //
		if ((this->instructions->get(address_005F)).getValue() == nullptr)
			goto L00C6;
		length_0090 = this->instructions->get(address_005F)->length();
		if ((length_0090) > (8))
			goto L00B2;
		stream->iprint(createString(""));
		stream->printHex(address_005F, 4);
		stream->print(createString(": "));
		stream->println(this->code, address_005F, length_0090);
	L00B2: //
		stream->indent(1);
		this->instructions->get(address_005F)->detailedDump(stream);
		stream->indent(-1);
	L00C6: //
		address_005F += 1;
	L00C9: //
		if ((address_005F) < (this->code->length))
			goto L0062;
		temp_00D9 = new StringBuilder(createString("Exceptions: "));
		stream->iprintln(temp_00D9->append(this->exceptionTable->length)->toString());
		i_00EC = 0;
		goto L017A;
	L00EF: //
		stream->indent(1);
		String::__ClassInit();
		temp_00FD = new StringBuilder(String::valueOf(i_00EC));
		stream->iprint(temp_00FD->append(createString(": L"))->toString());
		stream->printHex(this->exceptionTable->get(i_00EC)->startPc, 4);
		stream->print(createString("...L"));
		stream->printHex(this->exceptionTable->get(i_00EC)->endPc, 4);
		stream->print(createString(" -> L"));
		stream->printHex(this->exceptionTable->get(i_00EC)->handlerPc, 4);
		stream->print(createString(", "));
		if ((this->exceptionTable->get(i_00EC)->catchType) != 0)
			goto L015C;
		stream->print(createString("null"));
		goto L016E;
	L015C: //
		ci_0166 = this->exceptionTable->get(i_00EC)->catchClass;
		stream->print(ci_0166->getName());
	L016E: //
		stream->println();
		stream->indent(-1);
		i_00EC += 1;
	L017A: //
		if ((i_00EC) < (this->exceptionTable->length))
			goto L00EF;
		temp_018A = new StringBuilder(createString("Attributes: "));
		stream->iprintln(temp_018A->append(this->attributes->size())->toString());
		i_019F = 0;
		goto L01D5;
	L01A2: //
		stream->indent(1);
		String::__ClassInit();
		temp_01B0 = new StringBuilder(String::valueOf(i_019F));
		stream->iprint(temp_01B0->append(createString(": "))->toString());
		temp_01C6 = (ClassAttribute*)((this->attributeList->get(i_019F)).getValue());
		temp_01C6->checkCast(ClassAttribute::__thisClassStatic);
		temp_01C6->dump(stream);
		stream->indent(-1);
		i_019F += 1;
	L01D5: //
		if ((i_019F) < (this->attributes->size()))
			goto L01A2;
		stream->indent(-1);
		return;
	}

	void AttributeCode::decode(Pointer<ConstantPool> cp)
	{
		Pointer<ByteInputStream> in_000C;
		int exceptionTableLength_0035 = 0;
		int i_0040 = 0;
		int attributeCount_0089 = 0;
		int i_008C = 0;
		Pointer<ClassAttribute> attribute_0096;
		Pointer<ByteInputStream> inCode_00D6;
		int index_00D9 = 0;
		int address_011F = 0;
		Pointer<Instruction> insn_012B;
		Pointer<ExceptionTable> exception_015F;
		Pointer<ByteInputStream> temp_0008;
		Pointer<JavaArray<ExceptionTable>> temp_0037;
		Pointer<ExceptionTable> temp_004E;
		Pointer<ConstantClassInfo> temp_0074;
		Pointer<JavaArray<Instruction>> temp_00C3;
		Pointer<ByteInputStream> temp_00D1;
		Pointer<JavaRawArray<bool>> temp_0117;
		Pointer<JavaArray<ExceptionTable>> local_014D;
		int local_0150 = 0;
		int local_0153 = 0;
		temp_0008 = new ByteInputStream(this->info);
		in_000C = temp_0008;
		this->maxStack = in_000C->u2();
		this->maxLocals = in_000C->u2();
		this->codeLength = in_000C->u4();
		this->code = in_000C->read(this->codeLength);
		exceptionTableLength_0035 = in_000C->u2();
		temp_0037 = new JavaArray<ExceptionTable>(exceptionTableLength_0035);
		this->exceptionTable = temp_0037;
		i_0040 = 0;
		goto L007D;
	L0043: //
		temp_004E = new ExceptionTable(in_000C);
		this->exceptionTable->assign(i_0040, temp_004E);
		if ((this->exceptionTable->get(i_0040)->catchType) == 0)
			goto L007A;
		temp_0074 = (ConstantClassInfo*)((cp->get(this->exceptionTable->get(i_0040)->catchType)).getValue());
		temp_0074->checkCast(ConstantClassInfo::__thisClassStatic);
		this->exceptionTable->get(i_0040)->catchClass = temp_0074.getValue();
	L007A: //
		i_0040 += 1;
	L007D: //
		if ((i_0040) < (exceptionTableLength_0035))
			goto L0043;
		attributeCount_0089 = in_000C->u2();
		i_008C = 0;
		goto L00B2;
	L008F: //
		ClassAttribute::__ClassInit();
		attribute_0096 = ClassAttribute::readAttribute(in_000C, cp);
		this->attributes->put(attribute_0096->getName().getValue(), attribute_0096.getValue());
		this->attributeList->add(attribute_0096.getValue());
		i_008C += 1;
	L00B2: //
		if ((i_008C) < (attributeCount_0089))
			goto L008F;
		in_000C->close();
		temp_00C3 = new JavaArray<Instruction>(this->code->length);
		this->instructions = temp_00C3;
		temp_00D1 = new ByteInputStream(this->code);
		inCode_00D6 = temp_00D1;
		index_00D9 = 0;
		goto L0104;
	L00DC: //
		Instruction::__ClassInit();
		this->instructions->assign(index_00D9, Instruction::read(inCode_00D6, cp));
		this->instructions->get(index_00D9)->setAddress(index_00D9);
		index_00D9 = (index_00D9) + (this->instructions->get(index_00D9)->length());
	L0104: //
		if ((inCode_00D6->available()) > 0)
			goto L00DC;
		inCode_00D6->close();
		temp_0117 = new JavaRawArray<bool>(this->code->length);
		this->labels = temp_0117;
		address_011F = 0;
		goto L013E;
	L0122: //
		insn_012B = this->instructions->get(address_011F);
		if ((insn_012B).getValue() == nullptr)
			goto L013B;
		insn_012B->addLabel(address_011F, this->labels);
	L013B: //
		address_011F += 1;
	L013E: //
		if ((address_011F) < (this->code->length))
			goto L0122;
		local_014D = (JavaArray<ExceptionTable>*)(this->exceptionTable.getValue());
		local_0150 = this->exceptionTable->length;
		local_0153 = 0;
		goto L016B;
	L0158: //
		exception_015F = local_014D->get(local_0153);
		exception_015F->addLabels(this->labels);
		local_0153 += 1;
	L016B: //
		if ((local_0153) < (local_0150))
			goto L0158;
		return;
	}

	void AttributeCode::updateEntries(Pointer<JavaArray<VariableTableEntry>> entries, Pointer<JavaArray<LocalVariableType>> localVariableTypes)
	{
		Pointer<LocalVariableType> type_0013;
		Pointer<VariableTableEntry> entry_0027;
		Pointer<JavaArray<LocalVariableType>> local_0002;
		int local_0005 = 0;
		int local_0008 = 0;
		Pointer<JavaArray<VariableTableEntry>> local_0015;
		int local_0018 = 0;
		int local_001B = 0;
		local_0002 = (JavaArray<LocalVariableType>*)(localVariableTypes.getValue());
		local_0005 = localVariableTypes->length;
		local_0008 = 0;
		goto L004F;
	L000D: //
		type_0013 = local_0002->get(local_0008);
		local_0015 = (JavaArray<VariableTableEntry>*)(entries.getValue());
		local_0018 = entries->length;
		local_001B = 0;
		goto L0045;
	L0020: //
		entry_0027 = local_0015->get(local_001B);
		if (!(entry_0027->name->equals(type_0013->name.getValue())))
			goto L0042;
		entry_0027->descriptor = type_0013->signature.getValue();
		goto L004C;
	L0042: //
		local_001B += 1;
	L0045: //
		if ((local_001B) < (local_0018))
			goto L0020;
	L004C: //
		local_0008 += 1;
	L004F: //
		if ((local_0008) < (local_0005))
			goto L000D;
		return;
	}

}
