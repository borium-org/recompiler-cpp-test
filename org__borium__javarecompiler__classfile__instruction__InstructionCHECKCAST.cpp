#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__instruction__InstructionCHECKCAST.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::instruction
{

	Pointer<Class> InstructionCHECKCAST::__thisClassStatic;

	void InstructionCHECKCAST::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::instruction::InstructionCHECKCAST",
			org::borium::javarecompiler::classfile::instruction::InstructionWithTypeIndex::__thisClassStatic);

		org::borium::javarecompiler::classfile::instruction::InstructionWithTypeIndex::__ClassInit();
	}

	InstructionCHECKCAST::InstructionCHECKCAST(Pointer<ByteInputStream> in, Pointer<ConstantPool> cp) :
		InstructionWithTypeIndex(in, cp) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		if (!(this->className->startsWith(createString("["))))
			goto L0016;
		this->convertArray();
	L0016: //
		return;
	}

	int InstructionCHECKCAST::getStackDepthChange()
	{
		UsageCounterMaintainer maintainer(this, true);

		return 0;
	}

	void InstructionCHECKCAST::convertArray()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0005;
		int indexCount_0007 = 0;
		Pointer<StringBuilder> temp_0048;
		className_0005 = this->className;
		indexCount_0007 = 0;
		goto L0013;
	L000A: //
		className_0005 = className_0005->substring(1);
		indexCount_0007 += 1;
	L0013: //
		if ((className_0005->charAt(0)) == (91))
			goto L000A;
		Statics::__ClassInit();
		Statics::Assert(((((className_0005->charAt(0)) == (76)) ? (1) : (0))) != 0, createString("CHECKCAST: Array of objects expected"));
		className_0005 = className_0005->substring(1, (className_0005->length()) - (1));
		goto L0054;
	L0040: //
		String::__ClassInit();
		temp_0048 = new StringBuilder(String::valueOf(className_0005.getValue()));
		className_0005 = temp_0048->append(createString("[]"))->toString();
	L0054: //
		indexCount_0007 += -1;
		if ((indexCount_0007) > 0)
			goto L0040;
		this->className = className_0005.getValue();
		return;
	}

}
