#pragma once

#include "org__borium__javarecompiler__classfile__instruction__Instruction.h"

namespace java::lang
{
	class String;
	class StringBuilder;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::instruction
{
	class Instruction;
}

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::instruction;

namespace org::borium::javarecompiler::classfile::instruction
{

	class InstructionTABLESWITCH : public Instruction
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		int padding;
		int defaultLabel;
		int low;
		int high;
		Pointer<JavaRawArray<int>> offset;

		static void __ClassInit();
		InstructionTABLESWITCH(Pointer<ByteInputStream> in);
		virtual void addLabel(int address, Pointer<JavaRawArray<bool>> labels);
		virtual void detailedDump(Pointer<IndentedOutputStream> stream);
		virtual bool fallsThrough();
		virtual int getCaseCount();
		virtual Pointer<String> getDefaultLabel();
		virtual int getFirstValue();
		virtual Pointer<String> getLabel(int index);
		virtual int getStackDepthChange();
		virtual int getTargetAddress(int index);
		virtual int getTargetCount();
		virtual int length();
		virtual void oneLineDump(Pointer<IndentedOutputStream> stream);
	};

}
