#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Class.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantUtf8Info.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	Pointer<Class> ConstantPool::__thisClassStatic;

	void ConstantPool::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::constants::ConstantPool",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ConstantPool::ConstantPool() :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	void ConstantPool::addReferencedClasses(Pointer<ReferencedClasses> referencedClasses)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<Constant> c_0014;
		Pointer<ConstantClassInfo> ci_002F;
		Pointer<Constant>  instanceOfPatternExpressionValue_0017;
		Pointer<String> className_0036;
		Pointer<JavaArray<Constant>> local_0005;
		int local_0008 = 0;
		int local_000B = 0;
		Pointer<ConstantClassInfo> temp_0021;
		Pointer<ConstantClassInfo> local_0025;
		Pointer<ConstantClassInfo> temp_0029;
		Pointer<String> local_0061;
		Pointer<StringBuilder> temp_0121;
		Pointer<StringBuilder> temp_013A;
		Pointer<StringBuilder> temp_014E;
		local_0005 = (JavaArray<Constant>*)(this->constants.getValue());
		local_0008 = this->constants->length;
		local_000B = 0;
		goto L0164;
	L000F: //
		c_0014 = local_0005->get(local_000B);
		 instanceOfPatternExpressionValue_0017 = c_0014;
		if (!( instanceOfPatternExpressionValue_0017->instanceOf(ConstantClassInfo::__thisClassStatic)))
			goto L0161;
		temp_0021 = (ConstantClassInfo*)(( instanceOfPatternExpressionValue_0017).getValue());
		temp_0021->checkCast(ConstantClassInfo::__thisClassStatic);
		local_0025 = temp_0021;
		temp_0029 = (ConstantClassInfo*)(( instanceOfPatternExpressionValue_0017).getValue());
		temp_0029->checkCast(ConstantClassInfo::__thisClassStatic);
		if ((temp_0021) != (temp_0029))
			goto L0161;
		className_0036 = ci_002F->getName();
		if (!(className_0036->startsWith(createString("["))))
			goto L005E;
		goto L004B;
	L0043: //
		className_0036 = className_0036->substring(1);
	L004B: //
		if (className_0036->startsWith(createString("[")))
			goto L0043;
		referencedClasses->add(className_0036);
		goto L0161;
	L005E: //
		local_0061 = className_0036;
		switch (className_0036->hashCode())
		{
		case (int)0x99CEF584:
			goto L00B0;
		case (int)0xF843E2FE:
			goto L00BD;
		case (int)0x02C85B0E:
			goto L00CA;
		case (int)0x0BBD0C37:
			goto L00D7;
		case (int)0x109FDC28:
			goto L00E4;
		case (int)0x41D0A6FC:
			goto L00F1;
		case (int)0x41D0BE02:
			goto L00FE;
		case (int)0x444D08AA:
			goto L010B;
		default:
			goto L0147;
		}
	L00B0: //
		if (local_0061->equals(createString("java/util/TreeSet")))
			goto L0131;
		goto L0147;
	L00BD: //
		if (local_0061->equals(createString("java/util/List")))
			goto L0131;
		goto L0147;
	L00CA: //
		if (local_0061->equals(createString("java/util/HashMap")))
			goto L0118;
		goto L0147;
	L00D7: //
		if (local_0061->equals(createString("java/util/ArrayList")))
			goto L0131;
		goto L0147;
	L00E4: //
		if (local_0061->equals(createString("java/util/Stack")))
			goto L0131;
		goto L0147;
	L00F1: //
		if (local_0061->equals(createString("java/util/Map")))
			goto L0118;
		goto L0147;
	L00FE: //
		if (local_0061->equals(createString("java/util/Set")))
			goto L0131;
		goto L0147;
	L010B: //
		if (local_0061->equals(createString("java/util/Map$Entry")))
			goto L0118;
		goto L0147;
	L0118: //
		String::__ClassInit();
		temp_0121 = new StringBuilder(String::valueOf(className_0036.getValue()));
		className_0036 = temp_0121->append(createString("<TK;TV;>"))->toString();
		goto L0147;
	L0131: //
		String::__ClassInit();
		temp_013A = new StringBuilder(String::valueOf(className_0036.getValue()));
		className_0036 = temp_013A->append(createString("<TE;>"))->toString();
	L0147: //
		temp_014E = new StringBuilder(createString("L"));
		referencedClasses->add(temp_014E->append(className_0036)->append(createString(";"))->toString());
	L0161: //
		local_000B += 1;
	L0164: //
		if ((local_000B) < (local_0008))
			goto L000F;
		return;
	}

	void ConstantPool::dump(Pointer<IndentedOutputStream> stream)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_000D = 0;
		Pointer<StringBuilder> temp_0022;
		stream->println(createString("Constants:"));
		stream->indent(1);
		i_000D = 1;
		goto L0041;
	L0010: //
		if ((this->constants->get(i_000D)).getValue() == nullptr)
			goto L003E;
		String::__ClassInit();
		temp_0022 = new StringBuilder(String::valueOf(i_000D));
		stream->iprint(temp_0022->append(createString(": "))->toString());
		this->constants->get(i_000D)->dump(stream);
		stream->println();
	L003E: //
		i_000D += 1;
	L0041: //
		if ((i_000D) < (this->constants->length))
			goto L0010;
		stream->indent(-1);
		return;
	}

	Pointer<Constant> ConstantPool::get(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0017;
		Pointer<ClassFormatError> temp_0030;
		if ((index) < 0)
			goto L000D;
		if ((index) < (this->constants->length))
			goto L0034;
	L000D: //
		temp_0017 = new StringBuilder(createString("Constant index "));
		temp_0030 = new ClassFormatError(temp_0017->append(index)->append(createString(" is out of range 0.."))->append((this->constants->length) - (1))->toString());
		throw temp_0030;
	L0034: //
		return this->constants->get(index);
	}

	Pointer<String> ConstantPool::getString(int index)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<Constant> constant_0006;
		Pointer<ConstantUtf8Info> utf8_0013;
		Pointer<ConstantUtf8Info> temp_000F;
		Pointer<StringBuilder> temp_0022;
		Pointer<ClassFormatError> temp_003B;
		constant_0006 = this->get(index);
		if ((constant_0006->tag) != (1))
			goto L0018;
		temp_000F = (ConstantUtf8Info*)((constant_0006).getValue());
		temp_000F->checkCast(ConstantUtf8Info::__thisClassStatic);
		utf8_0013 = temp_000F;
		return utf8_0013->string();
	L0018: //
		temp_0022 = new StringBuilder(createString("Index "));
		temp_003B = new ClassFormatError(temp_0022->append(index)->append(createString(" is not a string but "))->append(constant_0006->getClass()->getSimpleName())->toString());
		throw temp_003B;
	}

	void ConstantPool::read(Pointer<ByteInputStream> in)
	{
		UsageCounterMaintainer maintainer(this, true);

		int count_0005 = 0;
		int i_000F = 0;
		int tag_0018 = 0;
		Pointer<Constant> constant_001F;
		int i_004D = 0;
		Pointer<JavaArray<Constant>> temp_0007;
		count_0005 = in->u2();
		temp_0007 = new JavaArray<Constant>(count_0005);
		this->constants = temp_0007;
		i_000F = 1;
		goto L0046;
	L0012: //
		tag_0018 = in->u1();
		Constant::__ClassInit();
		constant_001F = Constant::create(tag_0018);
		constant_001F->read(in);
		this->constants->assign(i_000F, constant_001F);
		if (constant_001F->is(5))
			goto L0040;
		if (!(constant_001F->is(6)))
			goto L0043;
	L0040: //
		i_000F += 1;
	L0043: //
		i_000F += 1;
	L0046: //
		if ((i_000F) < (count_0005))
			goto L0012;
		i_004D = 1;
		goto L0066;
	L0050: //
		if ((this->constants->get(i_004D)).getValue() == nullptr)
			goto L0063;
		this->constants->get(i_004D)->fixup(this);
	L0063: //
		i_004D += 1;
	L0066: //
		if ((i_004D) < (count_0005))
			goto L0050;
		return;
	}

	void ConstantPool::verify(int majorVersion, int minorVersion)
	{
		UsageCounterMaintainer maintainer(this, true);

		int i_0002 = 0;
		Pointer<Constant> constant_000D;
		i_0002 = 0;
		goto L001F;
	L0005: //
		constant_000D = this->constants->get(i_0002);
		if ((constant_000D).getValue() == nullptr)
			goto L001C;
		constant_000D->verify(majorVersion, minorVersion, this, i_0002);
	L001C: //
		i_0002 += 1;
	L001F: //
		if ((i_0002) < (this->constants->length))
			goto L0005;
		return;
	}

}
