#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariables.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__util__ArrayList.h"
#include "java__util__Iterator.h"
#include "org__borium__javarecompiler__classfile__attribute__VariableTableEntry.h"
#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"
#include "org__borium__javarecompiler__cplusplus__CppClass.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariable.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::classfile::instruction;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> LocalVariables::__thisClassStatic;

	void LocalVariables::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::LocalVariables",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	LocalVariables::LocalVariables(Pointer<JavaArray<VariableTableEntry>> localVariableTable, Pointer<CppClass> cppClass) :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<VariableTableEntry> entry_0022;
		Pointer<ArrayList<Object>> temp_0009;
		Pointer<JavaArray<VariableTableEntry>> local_0011;
		int local_0014 = 0;
		int local_0017 = 0;
		Pointer<LocalVariable> temp_002C;
		temp_0009 = new ArrayList<Object>();
		this->localVariableTable = (ArrayList<LocalVariable>*)temp_0009.getValue();
		local_0011 = (JavaArray<VariableTableEntry>*)(localVariableTable.getValue());
		local_0014 = localVariableTable->length;
		local_0017 = 0;
		goto L0036;
	L001C: //
		entry_0022 = local_0011->get(local_0017);
		temp_002C = new LocalVariable(entry_0022, cppClass);
		this->localVariableTable->add(temp_002C.getValue());
		local_0017 += 1;
	L0036: //
		if ((local_0017) < (local_0014))
			goto L001C;
		return;
	}

	Pointer<LocalVariable> LocalVariables::get(int index, Pointer<Instruction> instruction)
	{
		UsageCounterMaintainer maintainer(this, true);

		int address_000D = 0;
		Pointer<LocalVariable> entry_0037;
		Pointer<Iterator> local_0026;
		Pointer<LocalVariable> temp_0032;
		address_000D = (((instruction).getValue() != nullptr) ? (instruction->address) : (0));
		if ((instruction).getValue() == nullptr)
			goto L001F;
		if (!(instruction->isXStore()))
			goto L001F;
		address_000D = (address_000D) + (instruction->length());
	L001F: //
		local_0026 = this->localVariableTable->iterator();
		goto L0055;
	L002B: //
		temp_0032 = (LocalVariable*)((local_0026->next()).getValue());
		temp_0032->checkCast(LocalVariable::__thisClassStatic);
		entry_0037 = temp_0032;
		if ((entry_0037->index) != (index))
			goto L0055;
		if ((address_000D) < (entry_0037->startPc))
			goto L0055;
		if ((address_000D) >= (entry_0037->endPc))
			goto L0055;
		return entry_0037;
	L0055: //
		if (local_0026->hasNext())
			goto L002B;
		// ARETURN: Type mismatch
		return (LocalVariable*)nullptr;
	}

	Pointer<LocalVariable> LocalVariables::get(int index, int address)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<LocalVariable> entry_0017;
		Pointer<Iterator> local_0007;
		Pointer<LocalVariable> temp_0013;
		local_0007 = this->localVariableTable->iterator();
		goto L0031;
	L000C: //
		temp_0013 = (LocalVariable*)((local_0007->next()).getValue());
		temp_0013->checkCast(LocalVariable::__thisClassStatic);
		entry_0017 = temp_0013;
		if ((entry_0017->index) != (index))
			goto L0031;
		if ((address) < (entry_0017->startPc))
			goto L0031;
		if ((address) >= (entry_0017->endPc))
			goto L0031;
		return entry_0017;
	L0031: //
		if (local_0007->hasNext())
			goto L000C;
		// ARETURN: Type mismatch
		return (LocalVariable*)nullptr;
	}

	Pointer<ArrayList<LocalVariable>> LocalVariables::getVariables()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->localVariableTable;
	}

	Pointer<LocalVariable> LocalVariables::set(int index, Pointer<String> type, int address)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<LocalVariable> local_000C;
		Pointer<LocalVariable> temp_0007;
		temp_0007 = new LocalVariable(index, type, address);
		local_000C = temp_0007;
		this->localVariableTable->add(local_000C.getValue());
		return local_000C;
	}

}
