#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionLOOKUPSWITCH.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionLOOKUPSWITCH::__thisClassStatic;

	void InstructionLOOKUPSWITCH::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionLOOKUPSWITCH",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionLOOKUPSWITCH::InstructionLOOKUPSWITCH(Pointer<ByteInputStream> in) :
		Instruction() //
		, padding(0) //
		, defaultLabel(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		int position_0009 = 0;
		int nPairs_0031 = 0;
		int i_0042 = 0;
		Pointer<JavaRawArray<int>> temp_0033;
		Pointer<JavaRawArray<int>> temp_003A;
		position_0009 = in->getPosition();
		goto L001E;
	L000C: //
		in->u1();
		this->padding = (this->padding) + (1);
		position_0009 += 1;
	L001E: //
		if (((position_0009) & (3)) != 0)
			goto L000C;
		this->defaultLabel = in->s4();
		nPairs_0031 = in->u4();
		temp_0033 = new JavaRawArray<int>(nPairs_0031);
		this->match = temp_0033;
		temp_003A = new JavaRawArray<int>(nPairs_0031);
		this->offset = temp_003A;
		i_0042 = 0;
		goto L005E;
	L0045: //
		this->match->assign(i_0042, in->s4());
		this->offset->assign(i_0042, in->s4());
		i_0042 += 1;
	L005E: //
		if ((i_0042) < (nPairs_0031))
			goto L0045;
		return;
	}

	void InstructionLOOKUPSWITCH::addLabel(int address, Pointer<JavaRawArray<bool>> labels)
	{
		UsageCounterMaintainer maintainer(this, true);

		int offs_0016 = 0;
		Pointer<JavaRawArray<int>> local_0005;
		int local_0008 = 0;
		int local_000B = 0;
		local_0005 = (JavaRawArray<int>*)(this->offset.getValue());
		local_0008 = this->offset->length;
		local_000B = 0;
		goto L001F;
	L0010: //
		offs_0016 = local_0005->get(local_000B);
		labels->assign((address) + (offs_0016), (1) & 1);
		local_000B += 1;
	L001F: //
		if ((local_000B) < (local_0008))
			goto L0010;
		labels->assign((address) + (this->defaultLabel), (1) & 1);
		return;
	}

	void InstructionLOOKUPSWITCH::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_0054 = 0;
		Pointer<StringBuilder> temp_0012;
		Pointer<StringBuilder> temp_0029;
		Pointer<StringBuilder> temp_005E;
		stream->iprintln(createString("lookupswitch"));
		stream->indent(1);
		temp_0012 = new StringBuilder(createString("padding: "));
		stream->iprintln(temp_0012->append(this->padding)->toString());
		temp_0029 = new StringBuilder(createString("cases: "));
		stream->iprintln(temp_0029->append(this->match->length)->toString());
		stream->iprint(createString("default: L"));
		stream->printHex((this->address) + (this->defaultLabel), 4);
		stream->println();
		i_0054 = 0;
		goto L008C;
	L0057: //
		temp_005E = new StringBuilder(createString("case "));
		stream->iprint(temp_005E->append(this->match->get(i_0054))->append(createString(": goto L"))->toString());
		stream->printHex((this->address) + (this->offset->get(i_0054)), 4);
		stream->println();
		i_0054 += 1;
	L008C: //
		if ((i_0054) < (this->match->length))
			goto L0057;
		stream->indent(-1);
		return;
	}

	bool InstructionLOOKUPSWITCH::fallsThrough()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

	int InstructionLOOKUPSWITCH::getCaseCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->match->length;
	}

	Pointer<String> InstructionLOOKUPSWITCH::getDefaultLabel()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0006;
		temp_0006 = new StringBuilder(createString("L"));
		Statics::__ClassInit();
		return temp_0006->append(Statics::hexString((this->address) + (this->defaultLabel), 4))->toString();
	}

	Pointer<String> InstructionLOOKUPSWITCH::getLabel(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0006;
		temp_0006 = new StringBuilder(createString("L"));
		Statics::__ClassInit();
		return temp_0006->append(Statics::hexString((this->address) + (this->offset->get(index)), 4))->toString();
	}

	int InstructionLOOKUPSWITCH::getMatch(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->match->get(index);
	}

	int InstructionLOOKUPSWITCH::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

	int InstructionLOOKUPSWITCH::getTargetAddress(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		if ((index) != (this->getCaseCount()))
			goto L0012;
		return (this->address) + (this->defaultLabel);
	L0012: //
		return (this->address) + (this->offset->get(index));
	}

	int InstructionLOOKUPSWITCH::getTargetCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		return (this->getCaseCount()) + (1);
	}

	int InstructionLOOKUPSWITCH::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return ((((1) + (this->padding)) + (4)) + (4)) + ((this->match->length) * (8));
	}

	void InstructionLOOKUPSWITCH::oneLineDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("lookupswitch "));
		stream->iprintln(temp_0007->append(this->match->length)->append(createString(" cases"))->toString());
		return;
	}

}
