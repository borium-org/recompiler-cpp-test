#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__CppMethod.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__IOException.h"
#include "java__io__PrintStream.h"
#include "java__lang__Integer.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__lang__System.h"
#include "java__util__ArrayList.h"
#include "java__util__Arrays.h"
#include "java__util__HashMap.h"
#include "java__util__Iterator.h"
#include "java__util__Stack.h"
#include "org__borium__javarecompiler__Recomp.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ClassMethod.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionARETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionASTORE.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionDRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionFRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionGOTO.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionINVOKESPECIAL.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionIRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLRETURN.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionRETURN.h"
#include "org__borium__javarecompiler__cplusplus__CppClass.h"
#include "org__borium__javarecompiler__cplusplus__CppExecutionContext.h"
#include "org__borium__javarecompiler__cplusplus__CppField.h"
#include "org__borium__javarecompiler__cplusplus__ExceptionHandler.h"
#include "org__borium__javarecompiler__cplusplus__ExceptionHandlers.h"
#include "org__borium__javarecompiler__cplusplus__LocalVariable.h"
#include "org__borium__javarecompiler__cplusplus__Statement.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> CppMethod::__thisClassStatic;

	void CppMethod::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::CppMethod",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	void CppMethod::generateClassInitDefaultCode(Pointer<IndentedOutputStream> source, Pointer<CppClass> clazz)
	{
		__ClassInit();

		Pointer<StringBuilder> temp_0029;
		Pointer<StringBuilder> temp_0051;
		source->iprintln(createString("static bool classInitialized = false;"));
		source->iprintln(createString("if (classInitialized)"));
		source->iprintln(createString("\treturn;"));
		source->iprintln(createString("classInitialized = true;"));
		source->println();
		source->iprintln(createString("__thisClassStatic = new Class("));
		temp_0029 = new StringBuilder(createString("\t\""));
		source->iprintln(temp_0029->append(clazz->nameSpace)->append(createString("::"))->append(clazz->className)->append(createString("\","))->toString());
		temp_0051 = new StringBuilder(createString("\t"));
		source->iprintln(temp_0051->append(clazz->parentClassName)->append(createString("::__thisClassStatic);"))->toString());
		source->println();
		return;
	}

	CppMethod::CppMethod(Pointer<CppClass> cppClass, Pointer<ClassMethod> javaMethod) :
		Object() //
		, isStatic(false) //
		, isAbstract(false) //
		, isPresent(false) //
		, parameterCount(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<HashMap<Object, Object>> temp_0009;
		Pointer<CppExecutionContext> temp_001C;
		Pointer<ExceptionHandlers> temp_0062;
		temp_0009 = new HashMap<Object, Object>();
		this->statements = (HashMap<Integer, Statement>*)temp_0009.getValue();
		this->cppClass = cppClass.getValue();
		temp_001C = new CppExecutionContext(this, cppClass, javaMethod);
		this->executionContext = temp_001C.getValue();
		this->isStatic = javaMethod->isStatic();
		this->isAbstract = javaMethod->isAbstract();
		this->isPresent = javaMethod->isPresentInSource();
		this->parameterCount = javaMethod->getParameterCount();
		this->instructions = javaMethod->getInstructions();
		if (this->isAbstract)
			goto L006C;
		if (!(this->isPresent))
			goto L006C;
		temp_0062 = new ExceptionHandlers(javaMethod->getExceptionTable(), cppClass);
		this->exceptionHandlers = temp_0062.getValue();
		this->parseStatements();
	L006C: //
		return;
	}

	bool CppMethod::containsStatementAt(int targetAddress)
	{
		UsageCounterMaintainer maintainer(this, true);

		Integer::__ClassInit();
		return this->statements->containsKey(Integer::valueOf(targetAddress).getValue());
	}

	void CppMethod::generateHeader(Pointer<IndentedOutputStream> header, Pointer<String> newName, Pointer<String> newType)
	{
		UsageCounterMaintainer maintainer(this, true);

		int pos_004B = 0;
		Pointer<StringBuilder> temp_0017;
		Pointer<StringBuilder> temp_005B;
		if (!(newType->endsWith(createString(")"))))
			goto L002C;
		Statics::__ClassInit();
		newType = Statics::addPointersIfNeeded(newType);
		String::__ClassInit();
		temp_0017 = new StringBuilder(String::valueOf(newName.getValue()));
		header->iprintln(temp_0017->append(newType)->append(createString(";"))->toString());
		goto L008B;
	L002C: //
		header->iprint(((this->isStatic) ? (((Pointer<String>) new String("static "))) : (((Pointer<String>) new String("virtual ")))));
		Statics::__ClassInit();
		newType = Statics::addPointersIfNeeded(newType);
		pos_004B = newType->indexOf(41);
		String::__ClassInit();
		temp_005B = new StringBuilder(String::valueOf(newType->substring((pos_004B) + (1)).getValue()));
		header->print(temp_005B->append(createString(" "))->append(newName)->append(newType->substring(0, (pos_004B) + (1)))->toString());
		header->println(((this->isAbstract) ? (((Pointer<String>) new String(" = 0;"))) : (((Pointer<String>) new String(";")))));
	L008B: //
		return;
	}

	void CppMethod::generateSource(Pointer<IndentedOutputStream> source, Pointer<String> newName, Pointer<String> newType, Pointer<JavaArray<CppField>> fields)
	{
		UsageCounterMaintainer maintainer(this, true);

		int pos_0015 = 0;
		Pointer<String> returnType_001F;
		bool isConstructor_002E = false;
		Pointer<ArrayList<Instruction>> invoke_00A5;
		Pointer<InstructionINVOKESPECIAL> special_00B6;
		Pointer<String> constructorClassName_00BD;
		Pointer<String> thisClassName_00C6;
		Pointer<CppField> field_00EC;
		Pointer<String> type_00FB;
		Pointer<String> initializer_0103;
		bool isStaticConstructor_01D1 = false;
		Pointer<StringBuilder> temp_0043;
		Pointer<StringBuilder> temp_005A;
		Pointer<Statement> temp_008A;
		Pointer<Statement> temp_009D;
		Pointer<InstructionINVOKESPECIAL> temp_00B1;
		Pointer<JavaArray<CppField>> local_00DA;
		int local_00DD = 0;
		int local_00E0 = 0;
		Pointer<StringBuilder> temp_0113;
		if (!(this->isAbstract))
			goto L0008;
		return;
	L0008: //
		Statics::__ClassInit();
		newType = Statics::addPointersIfNeeded(newType);
		pos_0015 = newType->indexOf(41);
		returnType_001F = newType->substring((pos_0015) + (1));
		isConstructor_002E = (((returnType_001F->length()) == 0) ? (1) : (0));
		source->iprint(createString(""));
		if (isConstructor_002E)
			goto L0051;
		String::__ClassInit();
		temp_0043 = new StringBuilder(String::valueOf(returnType_001F.getValue()));
		source->print(temp_0043->append(createString(" "))->toString());
	L0051: //
		String::__ClassInit();
		temp_005A = new StringBuilder(String::valueOf(newName.getValue()));
		source->print(temp_005A->append(newType->substring(0, (pos_0015) + (1)))->toString());
		if (!(isConstructor_002E))
			goto L0147;
		source->println(createString(" :"));
		source->indent(1);
		Integer::__ClassInit();
		temp_008A = (Statement*)((this->statements->get(Integer::valueOf(0).getValue())).getValue());
		temp_008A->checkCast(Statement::__thisClassStatic);
		temp_008A->generateSource(source, true);
		Integer::__ClassInit();
		temp_009D = (Statement*)((this->statements->get(Integer::valueOf(0).getValue())).getValue());
		temp_009D->checkCast(Statement::__thisClassStatic);
		invoke_00A5 = (ArrayList<Instruction>*)(temp_009D->getInstructions().getValue());
		temp_00B1 = (InstructionINVOKESPECIAL*)((invoke_00A5->get((invoke_00A5->size()) - (1))).getValue());
		temp_00B1->checkCast(InstructionINVOKESPECIAL::__thisClassStatic);
		special_00B6 = temp_00B1;
		constructorClassName_00BD = special_00B6->getMethodClassName();
		thisClassName_00C6 = this->cppClass->getFullClassName();
		Statics::__ClassInit();
		constructorClassName_00BD = Statics::dotToNamespace(constructorClassName_00BD);
		if (thisClassName_00C6->equals(constructorClassName_00BD.getValue()))
			goto L013F;
		local_00DA = (JavaArray<CppField>*)(fields.getValue());
		local_00DD = fields->length;
		local_00E0 = 0;
		goto L0138;
	L00E5: //
		field_00EC = local_00DA->get(local_00E0);
		if (field_00EC->isStatic())
			goto L0135;
		type_00FB = field_00EC->getType();
		initializer_0103 = this->createInitializer(type_00FB);
		if ((initializer_0103->length()) <= 0)
			goto L0135;
		temp_0113 = new StringBuilder(createString(", "));
		source->iprintln(temp_0113->append(field_00EC->getName())->append(createString("("))->append(initializer_0103)->append(createString(") //"))->toString());
	L0135: //
		local_00E0 += 1;
	L0138: //
		if ((local_00E0) < (local_00DD))
			goto L00E5;
	L013F: //
		source->indent(-1);
		goto L014B;
	L0147: //
		source->println();
	L014B: //
		source->iprintln(createString("{"));
		source->indent(1);
		if (!(isConstructor_002E))
			goto L017C;
		source->iprintln(createString("__ClassInit();"));
		source->iprintln(createString("__thisClass = __thisClassStatic;"));
		source->println();
		source->iprintln(createString("UsageCounterMaintainer maintainer(this, false);"));
		source->println();
		goto L018E;
	L017C: //
		if (this->isStatic)
			goto L018E;
		source->iprintln(createString("UsageCounterMaintainer maintainer(this, true);"));
		source->println();
	L018E: //
		if (!(this->isStatic))
			goto L01AD;
		if (this->getName()->equals(createString("<clinit>")))
			goto L01AD;
		source->iprintln(createString("__ClassInit();"));
		source->println();
	L01AD: //
		if (!(newName->endsWith(createString("::__ClassInit"))))
			goto L01BF;
		CppMethod::__ClassInit();
		CppMethod::generateClassInitDefaultCode(source, this->cppClass);
	L01BF: //
		this->generateLocalVariables(source);
		source->lock();
		isStaticConstructor_01D1 = newName->endsWith(createString("::__ClassInit"));
		this->generateStatementSource(source, isConstructor_002E, isStaticConstructor_01D1);
		source->unlock();
		source->indent(-1);
		source->iprintln(createString("}"));
		source->println();
		return;
	}

	Pointer<JavaArray<Instruction>> CppMethod::getInstructions()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->instructions;
	}

	Pointer<String> CppMethod::getName()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->executionContext->name;
	}

	Pointer<String> CppMethod::getType()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->executionContext->cppType;
	}

	bool CppMethod::isPresentInSource()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->isPresent;
	}

	void CppMethod::combineStatements()
	{
		UsageCounterMaintainer maintainer(this, true);

		bool changed_0002 = false;
		int address_0009 = 0;
		Pointer<Statement> statement_001B;
		Pointer<Instruction> instruction_0033;
		int targets_003A = 0;
		int target_0042 = 0;
		int targetAddress_004E = 0;
		Pointer<Statement> targetStatement_005F;
		int nextAddress_006C = 0;
		Pointer<Statement> nextStatement_009F;
		Pointer<Statement> temp_0017;
		Pointer<Iterator> local_0022;
		Pointer<Instruction> temp_002E;
		Pointer<Statement> temp_005A;
		Pointer<Statement> temp_009A;
		changed_0002 = 1;
		goto L00EE;
	L0005: //
		changed_0002 = 0;
		address_0009 = 0;
		goto L00E3;
	L000C: //
		Integer::__ClassInit();
		temp_0017 = (Statement*)((this->statements->get(Integer::valueOf(address_0009).getValue())).getValue());
		temp_0017->checkCast(Statement::__thisClassStatic);
		statement_001B = temp_0017;
		local_0022 = statement_001B->getInstructions()->iterator();
		goto L00CB;
	L0027: //
		temp_002E = (Instruction*)((local_0022->next()).getValue());
		temp_002E->checkCast(Instruction::__thisClassStatic);
		instruction_0033 = temp_002E;
		targets_003A = instruction_0033->getTargetCount();
		if ((targets_003A) <= 0)
			goto L00C4;
		target_0042 = 0;
		goto L00BD;
	L0045: //
		targetAddress_004E = instruction_0033->getTargetAddress(target_0042);
		Integer::__ClassInit();
		temp_005A = (Statement*)((this->statements->get(Integer::valueOf(targetAddress_004E).getValue())).getValue());
		temp_005A->checkCast(Statement::__thisClassStatic);
		targetStatement_005F = temp_005A;
		if ((targetStatement_005F).getValue() != nullptr)
			goto L00BA;
		nextAddress_006C = (address_0009) + (statement_001B->length());
		if ((targetAddress_004E) < (address_0009))
			goto L007C;
		if ((targetAddress_004E) >= (nextAddress_006C))
			goto L007C;
		goto L00C4;
	L007C: //
		nextAddress_006C = (address_0009) + (statement_001B->length());
		if ((nextAddress_006C) <= (targetAddress_004E))
			goto L008E;
		goto L00B5;
	L008E: //
		Integer::__ClassInit();
		temp_009A = (Statement*)((this->statements->get(Integer::valueOf(nextAddress_006C).getValue())).getValue());
		temp_009A->checkCast(Statement::__thisClassStatic);
		nextStatement_009F = temp_009A;
		statement_001B->merge(nextStatement_009F);
		Integer::__ClassInit();
		this->statements->remove(Integer::valueOf(nextAddress_006C).getValue());
		goto L007C;
	L00B5: //
		changed_0002 = 1;
		goto L00C4;
	L00BA: //
		target_0042 += 1;
	L00BD: //
		if ((target_0042) < (targets_003A))
			goto L0045;
	L00C4: //
		if (!(changed_0002))
			goto L00CB;
		goto L00D5;
	L00CB: //
		if (local_0022->hasNext())
			goto L0027;
	L00D5: //
		if (!(changed_0002))
			goto L00DC;
		goto L00EE;
	L00DC: //
		address_0009 = (address_0009) + (statement_001B->length());
	L00E3: //
		if ((address_0009) < (this->executionContext->getCodeSize()))
			goto L000C;
	L00EE: //
		if (changed_0002)
			goto L0005;
		return;
	}

	Pointer<String> CppMethod::createInitializer(Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> initializer_0004;
		initializer_0004 = createString("0");
		if (!(type->equals(createString("bool"))))
			goto L0012;
		initializer_0004 = createString("false");
	L0012: //
		Statics::__ClassInit();
		type = Statics::addPointerIfNeeded(type);
		if (!(type->startsWith(createString("Pointer<"))))
			goto L0024;
		initializer_0004 = createString("");
	L0024: //
		return initializer_0004;
	}

	void CppMethod::generateLocalVariableInitializer(Pointer<IndentedOutputStream> source, Pointer<LocalVariable> local)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> type_0005;
		Pointer<String> name_000B;
		Pointer<String> initializer_0012;
		Pointer<StringBuilder> temp_0021;
		Pointer<StringBuilder> temp_003A;
		type_0005 = local->getType();
		name_000B = local->getName();
		initializer_0012 = this->createInitializer(type_0005);
		if ((initializer_0012->length()) <= 0)
			goto L002E;
		temp_0021 = new StringBuilder(createString(" = "));
		initializer_0012 = temp_0021->append(initializer_0012)->toString();
	L002E: //
		Statics::__ClassInit();
		String::__ClassInit();
		temp_003A = new StringBuilder(String::valueOf(Statics::addPointerIfNeeded(type_0005).getValue()));
		source->iprintln(temp_003A->append(createString(" "))->append(name_000B)->append(initializer_0012)->append(createString(";"))->toString());
		return;
	}

	void CppMethod::generateLocalVariables(Pointer<IndentedOutputStream> source)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ArrayList<LocalVariable>> locals_0008;
		Pointer<LocalVariable> local_001C;
		Pointer<Iterator> local_000C;
		Pointer<LocalVariable> temp_0018;
		locals_0008 = (ArrayList<LocalVariable>*)(this->executionContext->getLocalVariables().getValue());
		local_000C = locals_0008->iterator();
		goto L003E;
	L0011: //
		temp_0018 = (LocalVariable*)((local_000C->next()).getValue());
		temp_0018->checkCast(LocalVariable::__thisClassStatic);
		local_001C = temp_0018;
		if ((local_001C->index) >= (this->parameterCount))
			goto L002A;
		goto L003E;
	L002A: //
		if ((this->exceptionHandlers->isParameter(local_001C)).getValue() == nullptr)
			goto L0038;
		goto L003E;
	L0038: //
		this->generateLocalVariableInitializer(source, local_001C);
	L003E: //
		if (local_000C->hasNext())
			goto L0011;
		return;
	}

	int CppMethod::generateStatements(Pointer<IndentedOutputStream> source, int address, int endAddress, bool allowLabel)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<Statement> statement_0013;
		Pointer<Statement> temp_000E;
		goto L0036;
	L0003: //
		Integer::__ClassInit();
		temp_000E = (Statement*)((this->statements->get(Integer::valueOf(address).getValue())).getValue());
		temp_000E->checkCast(Statement::__thisClassStatic);
		statement_0013 = temp_000E;
		Statics::__ClassInit();
		Statics::Assert(((((statement_0013).getValue() != nullptr) ? (1) : (0))) != 0, createString("Before try: Null statement"));
		statement_0013->generateSource(source, allowLabel);
		allowLabel = 1;
		address = (address) + (statement_0013->length());
	L0036: //
		if ((address) < (endAddress))
			goto L0003;
		Statics::__ClassInit();
		Statics::Assert(((((address) == (endAddress)) ? (1) : (0))) != 0, createString("End address mismatch"));
		return address;
	}

	void CppMethod::generateStatementSource(Pointer<IndentedOutputStream> source, bool isConstructor, bool isStaticConstructor)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> parentClassName_0015;
		int address_003C = 0;
		int lastAddress_005F = 0;
		Pointer<ExceptionHandler> handler_006D;
		Pointer<Statement> statement_00A0;
		Pointer<Instruction> instruction_012D;
		int endCatch_0140 = 0;
		Pointer<String> exceptionClass_0159;
		Pointer<InstructionASTORE> astore_0196;
		int catchStartPc_01A3 = 0;
		Pointer<LocalVariable> catchParam_01B3;
		Pointer<StringBuilder> temp_002A;
		Pointer<Statement> temp_004D;
		Pointer<Statement> temp_009B;
		Pointer<Statement> temp_00E0;
		Pointer<Iterator> local_0148;
		Pointer<String> temp_0154;
		Pointer<Statement> temp_0165;
		Pointer<InstructionASTORE> temp_0191;
		Pointer<StringBuilder> temp_01CB;
		this->executionContext->isStaticConstructor = isStaticConstructor;
		if (!(isStaticConstructor))
			goto L0039;
		parentClassName_0015 = this->cppClass->parentClassName;
		parentClassName_0015 = this->cppClass->simplifyType(parentClassName_0015);
		String::__ClassInit();
		temp_002A = new StringBuilder(String::valueOf(parentClassName_0015.getValue()));
		source->iprintln(temp_002A->append(createString("::__ClassInit();"))->toString());
	L0039: //
		address_003C = 0;
		if (!(isConstructor))
			goto L0056;
		Integer::__ClassInit();
		temp_004D = (Statement*)((this->statements->get(Integer::valueOf(0).getValue())).getValue());
		temp_004D->checkCast(Statement::__thisClassStatic);
		address_003C = (address_003C) + (temp_004D->length());
	L0056: //
		lastAddress_005F = this->executionContext->getCodeSize();
		goto L021D;
	L0062: //
		handler_006D = this->exceptionHandlers->findHandler(address_003C);
		if ((handler_006D).getValue() != nullptr)
			goto L0080;
		this->generateStatements(source, address_003C, lastAddress_005F, true);
		goto L0224;
	L0080: //
		address_003C = this->generateStatements(source, address_003C, handler_006D->startPc, true);
		Integer::__ClassInit();
		temp_009B = (Statement*)((this->statements->get(Integer::valueOf(address_003C).getValue())).getValue());
		temp_009B->checkCast(Statement::__thisClassStatic);
		statement_00A0 = temp_009B;
		statement_00A0->generateLabel(source);
		source->iprintln(createString("try"));
		source->iprintln(createString("{"));
		source->indent(1);
		this->generateTryBlockVariables(source, address_003C, handler_006D->endPc);
		address_003C = this->generateStatements(source, address_003C, handler_006D->endPc, false);
		Integer::__ClassInit();
		temp_00E0 = (Statement*)((this->statements->get(Integer::valueOf(address_003C).getValue())).getValue());
		temp_00E0->checkCast(Statement::__thisClassStatic);
		statement_00A0 = temp_00E0;
		Statics::__ClassInit();
		Statics::Assert(((((statement_00A0).getValue() != nullptr) ? (1) : (0))) != 0, createString("GOTO: Null statement"));
		statement_00A0->generateSource(source, true);
		address_003C = (address_003C) + (statement_00A0->length());
		source->indent(-1);
		source->iprintln(createString("}"));
		Statics::__ClassInit();
		Statics::Assert(((((statement_00A0->getInstructionCount()) == (1)) ? (1) : (0))) != 0, createString("Try: Single instruction statement expected"));
		instruction_012D = statement_00A0->getLastInstruction();
		Statics::__ClassInit();
		Statics::Assert(instruction_012D->instanceOf(InstructionGOTO::__thisClassStatic), createString("GOTO expected in the end of try block"));
		endCatch_0140 = instruction_012D->getTargetAddress(0);
		local_0148 = handler_006D->exceptionClasses->iterator();
		goto L020F;
	L014D: //
		temp_0154 = (String*)((local_0148->next()).getValue());
		temp_0154->checkCast(String::__thisClassStatic);
		exceptionClass_0159 = temp_0154;
		Integer::__ClassInit();
		temp_0165 = (Statement*)((this->statements->get(Integer::valueOf(address_003C).getValue())).getValue());
		temp_0165->checkCast(Statement::__thisClassStatic);
		statement_00A0 = temp_0165;
		Statics::__ClassInit();
		Statics::Assert(((((statement_00A0->getInstructionCount()) == (1)) ? (1) : (0))) != 0, createString("Catch: Single instruction statement expected"));
		Statics::__ClassInit();
		Statics::Assert(statement_00A0->getLastInstruction()->instanceOf(InstructionASTORE::__thisClassStatic), createString("Catch: ASTORE instruction expected"));
		temp_0191 = (InstructionASTORE*)((statement_00A0->getLastInstruction()).getValue());
		temp_0191->checkCast(InstructionASTORE::__thisClassStatic);
		astore_0196 = temp_0191;
		catchStartPc_01A3 = (astore_0196->address) + (astore_0196->length());
		catchParam_01B3 = this->executionContext->getLocalVariable(astore_0196->getIndex(), catchStartPc_01A3);
		Statics::__ClassInit();
		Statics::Assert(((((catchParam_01B3).getValue() != nullptr) ? (1) : (0))) != 0, createString("Catch: Parameter not found"));
		temp_01CB = new StringBuilder(createString("catch ("));
		source->iprintln(temp_01CB->append(exceptionClass_0159)->append(createString("* "))->append(catchParam_01B3->getName())->append(createString(")"))->toString());
		source->iprintln(createString("{"));
		source->indent(1);
		this->generateStatements(source, catchStartPc_01A3, endCatch_0140, true);
		source->indent(-1);
		source->iprintln(createString("}"));
	L020F: //
		if (local_0148->hasNext())
			goto L014D;
		address_003C = endCatch_0140;
	L021D: //
		if ((address_003C) < (lastAddress_005F))
			goto L0062;
	L0224: //
		return;
	}

	void CppMethod::generateTryBlockVariables(Pointer<IndentedOutputStream> source, int address, int endPc)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ArrayList<LocalVariable>> locals_0009;
		Pointer<LocalVariable> local_001F;
		Pointer<ExceptionHandler> handler_0036;
		Pointer<Iterator> local_000E;
		Pointer<LocalVariable> temp_001A;
		locals_0009 = (ArrayList<LocalVariable>*)(this->executionContext->getLocalVariables().getValue());
		local_000E = locals_0009->iterator();
		goto L005F;
	L0013: //
		temp_001A = (LocalVariable*)((local_000E->next()).getValue());
		temp_001A->checkCast(LocalVariable::__thisClassStatic);
		local_001F = temp_001A;
		if ((local_001F->endPc) == (endPc))
			goto L002B;
		goto L005F;
	L002B: //
		handler_0036 = this->exceptionHandlers->isTryVariable(local_001F);
		if ((handler_0036).getValue() != nullptr)
			goto L003E;
		goto L005F;
	L003E: //
		if ((local_001F->startPc) <= (handler_0036->startPc))
			goto L005F;
		if ((local_001F->endPc) != (handler_0036->endPc))
			goto L005F;
		this->generateLocalVariableInitializer(source, local_001F);
	L005F: //
		if (local_000E->hasNext())
			goto L0013;
		return;
	}

	void CppMethod::parseStatements()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<Instruction>> code_0008;
		Pointer<JavaRawArray<int>> depth_000F;
		Pointer<JavaRawArray<bool>> processed_001D;
		Pointer<Stack<Integer>> parseStack_0058;
		int address_0080 = 0;
		int entry_00B6 = 0;
		int stackDepth_00BD = 0;
		int address_00C5 = 0;
		Pointer<Instruction> instruction_0114;
		int nextAddress_011E = 0;
		int targetCount_0167 = 0;
		int i_016A = 0;
		int targetAddress_0176 = 0;
		int i_020E = 0;
		Pointer<String> traceFileName_027F;
		Pointer<IndentedOutputStream> trace_031E;
		int i_0321 = 0;
		Pointer<Instruction> instruction_032A;
		int stackDepth_037C = 0;
		Pointer<ArrayList<Instruction>> instructions_0385;
		int address_0388 = 0;
		Pointer<Instruction> instruction_0391;
		int nextAddress_03A8 = 0;
		Pointer<Statement> statement_03C2;
		int address_03EE = 0;
		Pointer<Instruction> instruction_03F7;
		int address_0483 = 0;
		Pointer<Instruction> xReturn_048B;
		int statementAddress_04C4 = 0;
		Pointer<Statement> statement_04E2;
		Pointer<Statement> catchStatement_04F9;
		Pointer<String> traceFileName_0521;
		int address_05B0 = 0;
		Pointer<IndentedOutputStream> trace_05BB;
		Pointer<Statement> statement_05CC;
		Pointer<JavaRawArray<int>> temp_000C;
		Pointer<JavaRawArray<bool>> temp_001A;
		Pointer<StringBuilder> temp_002C;
		Pointer<Stack<Object>> temp_0053;
		Pointer<Iterator> local_006C;
		Pointer<Integer> temp_0078;
		Pointer<Integer> temp_00AE;
		Pointer<StringBuilder> temp_00DA;
		Pointer<StringBuilder> temp_019C;
		Pointer<StringBuilder> temp_0223;
		Pointer<StringBuilder> temp_024E;
		Pointer<String> local_0287;
		Pointer<StringBuilder> temp_02DE;
		Pointer<StringBuilder> temp_02FA;
		Pointer<IndentedOutputStream> temp_0319;
		Pointer<StringBuilder> temp_033E;
		Pointer<ArrayList<Object>> temp_0380;
		Pointer<Statement> temp_03BD;
		Pointer<StringBuilder> temp_040C;
		Pointer<StringBuilder> temp_0443;
		Pointer<Iterator> local_046F;
		Pointer<Integer> temp_047B;
		Pointer<Statement> temp_04DD;
		Pointer<String> local_0529;
		Pointer<StringBuilder> temp_057E;
		Pointer<StringBuilder> temp_059A;
		Pointer<IndentedOutputStream> temp_05B6;
		Pointer<Statement> temp_05C7;
		code_0008 = (JavaArray<Instruction>*)(this->executionContext->instructions.getValue());
		temp_000C = new JavaRawArray<int>((code_0008->length) + (1));
		depth_000F = (JavaRawArray<int>*)(temp_000C.getValue());
		Arrays::__ClassInit();
		Arrays::fill(depth_000F, -1);
		depth_000F->assign(0, 0);
		temp_001A = new JavaRawArray<bool>(code_0008->length);
		processed_001D = (JavaRawArray<bool>*)(temp_001A.getValue());
		Arrays::__ClassInit();
		Arrays::fill(processed_001D, false);
		System::__ClassInit();
		temp_002C = new StringBuilder(createString("Parsing instructions for "));
		System::out->println(temp_002C->append(this->cppClass->className)->append(createString("."))->append(this->executionContext->name)->toString());
		temp_0053 = new Stack<Object>();
		parseStack_0058 = (Stack<Integer>*)(temp_0053.getValue());
		Integer::__ClassInit();
		parseStack_0058->push(Integer::valueOf(0).getValue());
		local_006C = this->exceptionHandlers->getCatchAddresses()->iterator();
		goto L0094;
	L0071: //
		temp_0078 = (Integer*)((local_006C->next()).getValue());
		temp_0078->checkCast(Integer::__thisClassStatic);
		address_0080 = temp_0078->intValue();
		Integer::__ClassInit();
		parseStack_0058->push(Integer::valueOf((65536) + (address_0080)).getValue());
		depth_000F->assign(address_0080, 1);
	L0094: //
		if (local_006C->hasNext())
			goto L0071;
		System::__ClassInit();
		System::out->print(createString(""));
		goto L0203;
	L00A9: //
		temp_00AE = (Integer*)((parseStack_0058->pop()).getValue());
		temp_00AE->checkCast(Integer::__thisClassStatic);
		entry_00B6 = temp_00AE->intValue();
		stackDepth_00BD = _sarx_i32(entry_00B6, (16) & 0x1F);
		address_00C5 = (entry_00B6) & (65535);
		temp_00DA = new StringBuilder(createString("Stack depth at "));
		Statics::__ClassInit();
		Statics::__ClassInit();
		Statics::Assert(((((depth_000F->get(address_00C5)) == (stackDepth_00BD)) ? (1) : (0))) != 0, temp_00DA->append(Statics::hexString(address_00C5, 4))->append(createString(" is not "))->append(stackDepth_00BD)->append(createString(" but "))->append(depth_000F->get(address_00C5))->toString());
	L0104: //
		if (!(processed_001D->get(address_00C5)))
			goto L010E;
		goto L0203;
	L010E: //
		instruction_0114 = code_0008->get(address_00C5);
		nextAddress_011E = (address_00C5) + (instruction_0114->length());
		stackDepth_00BD = (stackDepth_00BD) + (instruction_0114->getStackDepthChange());
		if ((nextAddress_011E) >= (depth_000F->length))
			goto L0140;
		if (!(instruction_0114->fallsThrough()))
			goto L0140;
		depth_000F->assign(nextAddress_011E, stackDepth_00BD);
		goto L0160;
	L0140: //
		if ((nextAddress_011E) != ((depth_000F->length) - (1)))
			goto L0152;
		depth_000F->assign(nextAddress_011E, stackDepth_00BD);
		goto L0160;
	L0152: //
		if ((nextAddress_011E) <= (code_0008->length))
			goto L0160;
		Statics::__ClassInit();
		Statics::Assert(false, createString("Instruction control flow past code array"));
	L0160: //
		targetCount_0167 = instruction_0114->getTargetCount();
		i_016A = 0;
		goto L01E1;
	L016D: //
		targetAddress_0176 = instruction_0114->getTargetAddress(i_016A);
		if ((depth_000F->get(targetAddress_0176)) != (-1))
			goto L0187;
		depth_000F->assign(targetAddress_0176, stackDepth_00BD);
		goto L01C6;
	L0187: //
		temp_019C = new StringBuilder(createString("Stack depth at target "));
		Statics::__ClassInit();
		Statics::__ClassInit();
		Statics::Assert(((((depth_000F->get(targetAddress_0176)) == (stackDepth_00BD)) ? (1) : (0))) != 0, temp_019C->append(Statics::hexString(targetAddress_0176, 4))->append(createString(" is not "))->append(stackDepth_00BD)->append(createString(" but "))->append(depth_000F->get(targetAddress_0176))->toString());
	L01C6: //
		if (processed_001D->get(targetAddress_0176))
			goto L01DE;
		Integer::__ClassInit();
		parseStack_0058->push(Integer::valueOf((_shlx_u32(stackDepth_00BD, (16) & 0x1F)) | (targetAddress_0176)).getValue());
	L01DE: //
		i_016A += 1;
	L01E1: //
		if ((i_016A) < (targetCount_0167))
			goto L016D;
		processed_001D->assign(address_00C5, (1) & 1);
		if (instruction_0114->fallsThrough())
			goto L01F8;
		goto L0203;
	L01F8: //
		address_00C5 = nextAddress_011E;
		if ((address_00C5) != (code_0008->length))
			goto L0104;
	L0203: //
		if ((parseStack_0058->size()) > 0)
			goto L00A9;
		i_020E = 0;
		goto L0269;
	L0211: //
		if ((code_0008->get(i_020E)).getValue() == nullptr)
			goto L0266;
		temp_0223 = new StringBuilder(createString("Instruction at "));
		Statics::__ClassInit();
		Statics::__ClassInit();
		Statics::Assert(processed_001D->get(i_020E), temp_0223->append(Statics::hexString(i_020E, 4))->append(createString(" was not processed"))->toString());
		temp_024E = new StringBuilder(createString("Stack depth at "));
		Statics::__ClassInit();
		Statics::__ClassInit();
		Statics::Assert(((((depth_000F->get(i_020E)) >= 0) ? (1) : (0))) != 0, temp_024E->append(Statics::hexString(i_020E, 4))->append(createString(" was not processed"))->toString());
	L0266: //
		i_020E += 1;
	L0269: //
		if ((i_020E) < (code_0008->length))
			goto L0211;
		Recomp::__ClassInit();
		if (!(Recomp::dumpInstructions))
			goto L0379;
		traceFileName_027F = this->executionContext->name;
		local_0287 = this->executionContext->name;
		switch (this->executionContext->name->hashCode())
		{
		case (int)0x8C160EA9:
			goto L02A8;
		case (int)0x6C5E0272:
			goto L02B6;
		default:
			goto L02EC;
		}
	L02A8: //
		if (local_0287->equals(createString("<clinit>")))
			goto L02D0;
		goto L02EC;
	L02B6: //
		if (local_0287->equals(createString("<init>")))
			goto L02C4;
		goto L02EC;
	L02C4: //
		traceFileName_027F = this->cppClass->className;
		goto L02EC;
	L02D0: //
		String::__ClassInit();
		temp_02DE = new StringBuilder(String::valueOf(this->cppClass->className.getValue()));
		traceFileName_027F = temp_02DE->append(createString("_Class"))->toString();
	L02EC: //
		String::__ClassInit();
		temp_02FA = new StringBuilder(String::valueOf(this->cppClass->className.getValue()));
		traceFileName_027F = temp_02FA->append(createString("."))->append(traceFileName_027F)->append(createString(".insn.txt"))->toString();
	L0313: //
		try
		{
			Pointer<IndentedOutputStream> trace_031E;
			temp_0319 = new IndentedOutputStream(traceFileName_027F);
			trace_031E = temp_0319;
			i_0321 = 0;
			goto L0363;
		L0324: //
			instruction_032A = code_0008->get(i_0321);
			if ((instruction_032A).getValue() == nullptr)
				goto L0360;
			Statics::__ClassInit();
			String::__ClassInit();
			temp_033E = new StringBuilder(String::valueOf(Statics::hexString(i_0321, 4).getValue()));
			trace_031E->print(temp_033E->append(createString(" "))->append(depth_000F->get(i_0321))->append(createString("  "))->toString());
			instruction_032A->oneLineDump(trace_031E);
		L0360: //
			i_0321 += 1;
		L0363: //
			if ((i_0321) < (code_0008->length))
				goto L0324;
			trace_031E->close();
		L036F: //
			goto L0379;
		}
		catch (IOException* e_0374)
		{
			e_0374->printStackTrace();
		}
	L0379: //
		stackDepth_037C = 0;
		temp_0380 = new ArrayList<Object>();
		instructions_0385 = (ArrayList<Instruction>*)(temp_0380.getValue());
		address_0388 = 0;
		goto L03DC;
	L038B: //
		instruction_0391 = code_0008->get(address_0388);
		if ((instruction_0391).getValue() == nullptr)
			goto L03D9;
		instructions_0385->add(instruction_0391.getValue());
		nextAddress_03A8 = (address_0388) + (instruction_0391->length());
		stackDepth_037C = depth_000F->get(nextAddress_03A8);
		if ((stackDepth_037C) != 0)
			goto L03D9;
		temp_03BD = new Statement(this->executionContext, instructions_0385.getValue());
		statement_03C2 = temp_03BD;
		Integer::__ClassInit();
		this->statements->put(Integer::valueOf(statement_03C2->getAddress()).getValue(), statement_03C2.getValue());
		instructions_0385->clear();
	L03D9: //
		address_0388 += 1;
	L03DC: //
		if ((address_0388) < (code_0008->length))
			goto L038B;
		if ((instructions_0385->size()) == 0)
			goto L0461;
		address_03EE = 0;
		goto L0432;
	L03F1: //
		instruction_03F7 = code_0008->get(address_03EE);
		if ((instruction_03F7).getValue() == nullptr)
			goto L042F;
		System::__ClassInit();
		Statics::__ClassInit();
		String::__ClassInit();
		temp_040C = new StringBuilder(String::valueOf(Statics::hexString(address_03EE, 4).getValue()));
		System::out->println(temp_040C->append(createString(" "))->append(depth_000F->get(address_03EE))->append(createString("  "))->append(instruction_03F7->toString())->toString());
	L042F: //
		address_03EE += 1;
	L0432: //
		if ((address_03EE) < (code_0008->length))
			goto L03F1;
		System::__ClassInit();
		temp_0443 = new StringBuilder(createString("Java stack depth is not 0 but "));
		System::err->println(temp_0443->append(stackDepth_037C)->append(createString(" at the end of instruction array in "))->append(this->executionContext->name)->toString());
	L0461: //
		this->combineStatements();
		local_046F = this->exceptionHandlers->getCatchAddresses()->iterator();
		goto L0508;
	L0474: //
		temp_047B = (Integer*)((local_046F->next()).getValue());
		temp_047B->checkCast(Integer::__thisClassStatic);
		address_0483 = temp_047B->intValue();
		xReturn_048B = code_0008->get((address_0483) - (1));
		if (xReturn_048B->instanceOf(InstructionRETURN::__thisClassStatic))
			goto L0508;
		if (xReturn_048B->instanceOf(InstructionARETURN::__thisClassStatic))
			goto L0508;
		if (xReturn_048B->instanceOf(InstructionDRETURN::__thisClassStatic))
			goto L0508;
		if (xReturn_048B->instanceOf(InstructionFRETURN::__thisClassStatic))
			goto L0508;
		if (xReturn_048B->instanceOf(InstructionIRETURN::__thisClassStatic))
			goto L0508;
		if (!(xReturn_048B->instanceOf(InstructionLRETURN::__thisClassStatic)))
			goto L04BE;
		goto L0508;
	L04BE: //
		statementAddress_04C4 = (address_0483) - (3);
		Statics::__ClassInit();
		Statics::Assert(code_0008->get(statementAddress_04C4)->instanceOf(InstructionGOTO::__thisClassStatic), createString("GOTO expected"));
		Integer::__ClassInit();
		temp_04DD = (Statement*)((this->statements->get(Integer::valueOf(statementAddress_04C4).getValue())).getValue());
		temp_04DD->checkCast(Statement::__thisClassStatic);
		statement_04E2 = temp_04DD;
		Statics::__ClassInit();
		Statics::Assert(((((statement_04E2).getValue() != nullptr) ? (1) : (0))) != 0, createString("Statement expected at the end of try block"));
		catchStatement_04F9 = statement_04E2->splitLastInstruction();
		Integer::__ClassInit();
		this->statements->put(Integer::valueOf(address_0483).getValue(), catchStatement_04F9.getValue());
	L0508: //
		if (local_046F->hasNext())
			goto L0474;
		Recomp::__ClassInit();
		if (!(Recomp::dumpStatements))
			goto L05F7;
		traceFileName_0521 = this->executionContext->name;
		local_0529 = this->executionContext->name;
		switch (this->executionContext->name->hashCode())
		{
		case (int)0x8C160EA9:
			goto L0548;
		case (int)0x6C5E0272:
			goto L0556;
		default:
			goto L058C;
		}
	L0548: //
		if (local_0529->equals(createString("<clinit>")))
			goto L0570;
		goto L058C;
	L0556: //
		if (local_0529->equals(createString("<init>")))
			goto L0564;
		goto L058C;
	L0564: //
		traceFileName_0521 = this->cppClass->className;
		goto L058C;
	L0570: //
		String::__ClassInit();
		temp_057E = new StringBuilder(String::valueOf(this->cppClass->className.getValue()));
		traceFileName_0521 = temp_057E->append(createString("_Class"))->toString();
	L058C: //
		String::__ClassInit();
		temp_059A = new StringBuilder(String::valueOf(this->cppClass->className.getValue()));
		traceFileName_0521 = temp_059A->append(traceFileName_0521)->append(createString(".stmt.txt"))->toString();
		address_05B0 = 0;
	L05B0: //
		try
		{
			Pointer<IndentedOutputStream> trace_05BB;
			temp_05B6 = new IndentedOutputStream(traceFileName_0521);
			trace_05BB = temp_05B6;
		L05BB: //
			Integer::__ClassInit();
			temp_05C7 = (Statement*)((this->statements->get(Integer::valueOf(address_05B0).getValue())).getValue());
			temp_05C7->checkCast(Statement::__thisClassStatic);
			statement_05CC = temp_05C7;
			if ((statement_05CC).getValue() != nullptr)
				goto L05D4;
			goto L05E8;
		L05D4: //
			statement_05CC->dumpInstructions(trace_05BB);
			address_05B0 = (address_05B0) + (statement_05CC->length());
			goto L05BB;
		L05E8: //
			trace_05BB->close();
		L05ED: //
			goto L05F7;
		}
		catch (IOException* e_05F2)
		{
			e_05F2->printStackTrace();
		}
	L05F7: //
		return;
	}

}
