#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__Statement.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "java__util__Iterator.h"
#include "java__util__Stack.h"
#include "org__borium__javarecompiler__Recomp.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"
#include "org__borium__javarecompiler__cplusplus__CppExecutionContext.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> Statement::__thisClassStatic;

	void Statement::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::Statement",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	Statement::Statement(Pointer<CppExecutionContext> executionContext, Pointer<ArrayList<Instruction>> instructions) :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<ArrayList<Object>> temp_0009;
		temp_0009 = new ArrayList<Object>();
		this->instructions = (ArrayList<Instruction>*)temp_0009.getValue();
		this->instructions->addAll(instructions.getValue());
		this->executionContext = executionContext.getValue();
		return;
	}

	void Statement::dumpInstructions(Pointer<IndentedOutputStream> trace)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<Instruction> instruction_0035;
		Pointer<StringBuilder> temp_0007;
		Pointer<Iterator> local_0027;
		Pointer<Instruction> temp_0031;
		temp_0007 = new StringBuilder(createString("// Statement "));
		Statics::__ClassInit();
		trace->println(temp_0007->append(Statics::hexString(this->getAddress(), 4))->toString());
		this->generateLabel(trace);
		local_0027 = this->instructions->iterator();
		goto L0040;
	L002B: //
		temp_0031 = (Instruction*)((local_0027->next()).getValue());
		temp_0031->checkCast(Instruction::__thisClassStatic);
		instruction_0035 = temp_0031;
		trace->iprint(createString("//\t"));
		instruction_0035->oneLineDump(trace);
	L0040: //
		if (local_0027->hasNext())
			goto L002B;
		return;
	}

	void Statement::generateLabel(Pointer<IndentedOutputStream> source)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_001A;
		if (!(this->executionContext->hasLabel(this->getAddress())))
			goto L0038;
		source->indent(-1);
		temp_001A = new StringBuilder(createString("L"));
		Statics::__ClassInit();
		source->iprintln(temp_001A->append(Statics::hexString(this->getAddress(), 4))->append(createString(": //"))->toString());
		source->indent(1);
	L0038: //
		return;
	}

	void Statement::generateSource(Pointer<IndentedOutputStream> source, bool allowLabel)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<Instruction> instruction_0020;
		Pointer<Iterator> local_0010;
		Pointer<Instruction> temp_001C;
		if (!(allowLabel))
			goto L0009;
		this->generateLabel(source);
	L0009: //
		local_0010 = this->instructions->iterator();
		goto L004C;
	L0015: //
		temp_001C = (Instruction*)((local_0010->next()).getValue());
		temp_001C->checkCast(Instruction::__thisClassStatic);
		instruction_0020 = temp_001C;
		Recomp::__ClassInit();
		if (!(Recomp::instructionComments))
			goto L0031;
		source->iprint(createString("//"));
		instruction_0020->oneLineDump(source);
	L0031: //
		this->executionContext->generate(source, instruction_0020);
		Recomp::__ClassInit();
		if (!(Recomp::stackComments))
			goto L004C;
		this->dumpStack(source, this->executionContext->getStack().getValue());
	L004C: //
		if (local_0010->hasNext())
			goto L0015;
		return;
	}

	int Statement::getAddress()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<Instruction> temp_0008;
		temp_0008 = (Instruction*)((this->instructions->get(0)).getValue());
		temp_0008->checkCast(Instruction::__thisClassStatic);
		return temp_0008->address;
	}

	int Statement::getInstructionCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->instructions->size();
	}

	Pointer<ArrayList<Instruction>> Statement::getInstructions()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->instructions;
	}

	Pointer<Instruction> Statement::getLastInstruction()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<Instruction> temp_0010;
		temp_0010 = (Instruction*)((this->instructions->get((this->instructions->size()) - (1))).getValue());
		temp_0010->checkCast(Instruction::__thisClassStatic);
		return temp_0010;
	}

	int Statement::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		int length_0002 = 0;
		Pointer<Instruction> instruction_0017;
		Pointer<Iterator> local_0009;
		Pointer<Instruction> temp_0013;
		length_0002 = 0;
		local_0009 = this->instructions->iterator();
		goto L001E;
	L000D: //
		temp_0013 = (Instruction*)((local_0009->next()).getValue());
		temp_0013->checkCast(Instruction::__thisClassStatic);
		instruction_0017 = temp_0013;
		length_0002 = (length_0002) + (instruction_0017->length());
	L001E: //
		if (local_0009->hasNext())
			goto L000D;
		return length_0002;
	}

	void Statement::merge(Pointer<Statement> nextStatement)
	{
		UsageCounterMaintainer maintainer(this, true);

		Statics::__ClassInit();
		Statics::Assert((((((this->getAddress()) + (this->length())) == (nextStatement->getAddress())) ? (1) : (0))) != 0, createString("Merge: Statements not in sequence"));
		this->instructions->addAll(nextStatement->instructions.getValue());
		return;
	}

	Pointer<Statement> Statement::splitLastInstruction()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ArrayList<Instruction>> newInstructions_0008;
		Pointer<Statement> statement_003E;
		Pointer<ArrayList<Object>> temp_0004;
		Pointer<Instruction> temp_0019;
		Pointer<Statement> temp_003A;
		temp_0004 = new ArrayList<Object>();
		newInstructions_0008 = (ArrayList<Instruction>*)(temp_0004.getValue());
		temp_0019 = (Instruction*)((this->instructions->get((this->instructions->size()) - (1))).getValue());
		temp_0019->checkCast(Instruction::__thisClassStatic);
		newInstructions_0008->add(temp_0019.getValue());
		this->instructions->remove((this->instructions->size()) - (1));
		temp_003A = new Statement(this->executionContext, newInstructions_0008.getValue());
		statement_003E = temp_003A;
		return statement_003E;
	}

	void Statement::dumpStack(Pointer<IndentedOutputStream> source, Pointer<Stack<String>> stack)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_0012 = 0;
		Pointer<StringBuilder> temp_001C;
		Pointer<String> temp_002D;
		if ((stack->size()) != 0)
			goto L0010;
		source->iprintln(createString("//\t\t\t\tstack: empty"));
		goto L0044;
	L0010: //
		i_0012 = 0;
		goto L003C;
	L0015: //
		temp_001C = new StringBuilder(createString("//\t\t\t\tstack["));
		temp_002D = (String*)((stack->elementAt(i_0012)).getValue());
		temp_002D->checkCast(String::__thisClassStatic);
		source->iprintln(temp_001C->append(i_0012)->append(createString("]: "))->append(temp_002D)->toString());
		i_0012 += 1;
	L003C: //
		if ((i_0012) < (stack->size()))
			goto L0015;
	L0044: //
		return;
	}

}
