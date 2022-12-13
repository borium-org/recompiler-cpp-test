#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariable.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__attribute__VariableTableEntry.h"
#include "org__borium__javarecompiler__cplusplus__CppClass.h"
#include "org__borium__javarecompiler__cplusplus__JavaTypeConverter.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile::attribute;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> LocalVariable::__thisClassStatic;

	void LocalVariable::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::LocalVariable",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	LocalVariable::LocalVariable(int index, Pointer<String> type, int address) :
		Object() //
		, startPc(0) //
		, endPc(0) //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<StringBuilder> temp_0020;
		this->index = index;
		this->type = type.getValue();
		this->startPc = address;
		this->endPc = 65535;
		temp_0020 = new StringBuilder(createString("local_"));
		Statics::__ClassInit();
		this->name = temp_0020->append(Statics::hexString(address, 4))->toString().getValue();
		return;
	}

	LocalVariable::LocalVariable(Pointer<VariableTableEntry> entry, Pointer<CppClass> cppClass) :
		Object() //
		, startPc(0) //
		, endPc(0) //
		, index(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<StringBuilder> temp_0025;
		Pointer<StringBuilder> temp_003A;
		Pointer<JavaTypeConverter> temp_0066;
		this->startPc = entry->startPc;
		this->endPc = (this->startPc) + (entry->length);
		String::__ClassInit();
		temp_0025 = new StringBuilder(String::valueOf(entry->name.getValue()));
		temp_003A = new StringBuilder(createString("_"));
		Statics::__ClassInit();
		this->name = temp_0025->append((((this->startPc) == 0) ? (((Pointer<String>) new String(""))) : (temp_003A->append(Statics::hexString(this->startPc, 4))->toString())))->toString().getValue();
		this->type = entry->descriptor.getValue();
		temp_0066 = new JavaTypeConverter(this->type, true);
		this->type = temp_0066->getCppType().getValue();
		this->type = cppClass->simplifyType(this->type).getValue();
		this->index = entry->index;
		return;
	}

	Pointer<String> LocalVariable::getName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->name;
	}

	Pointer<String> LocalVariable::getType()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->type;
	}

}
