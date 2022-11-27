#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionTABLESWITCH.h"
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

	Pointer<Class> InstructionTABLESWITCH::__thisClassStatic;

	void InstructionTABLESWITCH::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionTABLESWITCH",
			org::borium::javarecompiler::classfile::instruction::Instruction::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::Instruction::__ClassInit();
	}

	InstructionTABLESWITCH::InstructionTABLESWITCH(Pointer<ByteInputStream> in) :
		Instruction() //
		, padding(0) //
		, defaultLabel(0) //
		, low(0) //
		, high(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		int position_0009 = 0;
		int nPairs_0048 = 0;
		int i_0052 = 0;
		Pointer<JavaRawArray<int>> temp_004A;
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
		this->low = in->s4();
		this->high = in->s4();
		nPairs_0048 = ((this->high) - (this->low)) + (1);
		temp_004A = new JavaRawArray<int>(nPairs_0048);
		this->offset = temp_004A;
		i_0052 = 0;
		goto L0063;
	L0055: //
		this->offset->assign(i_0052, in->s4());
		i_0052 += 1;
	L0063: //
		if ((i_0052) < (nPairs_0048))
			goto L0055;
		return;
	}

	void InstructionTABLESWITCH::addLabel(int address, Pointer<JavaRawArray<bool>> labels)
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

	void InstructionTABLESWITCH::detailedDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_0082 = 0;
		Pointer<StringBuilder> temp_0012;
		Pointer<StringBuilder> temp_0029;
		Pointer<StringBuilder> temp_0040;
		Pointer<StringBuilder> temp_0057;
		Pointer<StringBuilder> temp_008C;
		stream->iprintln(createString("tableswitch"));
		stream->indent(1);
		temp_0012 = new StringBuilder(createString("padding: "));
		stream->iprintln(temp_0012->append(this->padding)->toString());
		temp_0029 = new StringBuilder(createString("low: "));
		stream->iprintln(temp_0029->append(this->low)->toString());
		temp_0040 = new StringBuilder(createString("high: "));
		stream->iprintln(temp_0040->append(this->high)->toString());
		temp_0057 = new StringBuilder(createString("cases: "));
		stream->iprintln(temp_0057->append(this->offset->length)->toString());
		stream->iprint(createString("default: L"));
		stream->printHex((this->address) + (this->defaultLabel), 4);
		stream->println();
		i_0082 = 0;
		goto L00BA;
	L0085: //
		temp_008C = new StringBuilder(createString("case "));
		stream->iprint(temp_008C->append((this->low) + (i_0082))->append(createString(": goto L"))->toString());
		stream->printHex((this->address) + (this->offset->get(i_0082)), 4);
		stream->println();
		i_0082 += 1;
	L00BA: //
		if ((i_0082) < (this->offset->length))
			goto L0085;
		stream->indent(-1);
		return;
	}

	bool InstructionTABLESWITCH::fallsThrough()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

	int InstructionTABLESWITCH::getCaseCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->offset->length;
	}

	Pointer<String> InstructionTABLESWITCH::getDefaultLabel()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0006;
		temp_0006 = new StringBuilder(createString("L"));
		Statics::__ClassInit();
		return temp_0006->append(Statics::hexString((this->address) + (this->defaultLabel), 4))->toString();
	}

	int InstructionTABLESWITCH::getFirstValue()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->low;
	}

	Pointer<String> InstructionTABLESWITCH::getLabel(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0006;
		temp_0006 = new StringBuilder(createString("L"));
		Statics::__ClassInit();
		return temp_0006->append(Statics::hexString((this->address) + (this->offset->get(index)), 4))->toString();
	}

	int InstructionTABLESWITCH::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return -1;
	}

	int InstructionTABLESWITCH::getTargetAddress(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		if ((index) != (this->getCaseCount()))
			goto L0012;
		return (this->address) + (this->defaultLabel);
	L0012: //
		return (this->address) + (this->offset->get(index));
	}

	int InstructionTABLESWITCH::getTargetCount()
	{
		UsageCounterMaintainer maintainer(this, true);

		return (this->getCaseCount()) + (1);
	}

	int InstructionTABLESWITCH::length()
	{
		UsageCounterMaintainer maintainer(this, true);

		return (((((1) + (this->padding)) + (4)) + (4)) + (4)) + ((this->offset->length) * (4));
	}

	void InstructionTABLESWITCH::oneLineDump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0007;
		temp_0007 = new StringBuilder(createString("tableswitch "));
		stream->iprintln(temp_0007->append(this->offset->length)->append(createString(" cases"))->toString());
		return;
	}

}
