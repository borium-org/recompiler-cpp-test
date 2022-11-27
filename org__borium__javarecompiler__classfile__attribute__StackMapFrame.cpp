#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__attribute__StackMapFrame.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__ClassFormatError.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__attribute__VerificationTypeInfo.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::attribute;

namespace org::borium::javarecompiler::classfile::attribute
{

	Pointer<Class> StackMapFrame::__thisClassStatic;

	void StackMapFrame::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::attribute::StackMapFrame",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	StackMapFrame::StackMapFrame(Pointer<ByteInputStream> in) :
		Object() //
		, frameType(0) //
		, offsetDelta(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		int i_00E9 = 0;
		int numberOfLocals_0120 = 0;
		int i_012A = 0;
		int numberOfStackItems_0148 = 0;
		int i_0153 = 0;
		Pointer<JavaArray<VerificationTypeInfo>> temp_0046;
		Pointer<VerificationTypeInfo> temp_0056;
		Pointer<JavaArray<VerificationTypeInfo>> temp_0071;
		Pointer<VerificationTypeInfo> temp_0081;
		Pointer<JavaArray<VerificationTypeInfo>> temp_00E1;
		Pointer<VerificationTypeInfo> temp_00F6;
		Pointer<JavaArray<VerificationTypeInfo>> temp_0122;
		Pointer<VerificationTypeInfo> temp_0137;
		Pointer<JavaArray<VerificationTypeInfo>> temp_014A;
		Pointer<VerificationTypeInfo> temp_0161;
		Pointer<StringBuilder> temp_017B;
		Pointer<ClassFormatError> temp_0188;
		this->frameType = in->u1();
		if ((this->frameType) < 0)
			goto L0027;
		if ((this->frameType) > (63))
			goto L0027;
		this->offsetDelta = this->frameType;
		goto L018C;
	L0027: //
		if ((this->frameType) < (64))
			goto L005D;
		if ((this->frameType) > (127))
			goto L005D;
		this->offsetDelta = (this->frameType) - (64);
		temp_0046 = new JavaArray<VerificationTypeInfo>(1);
		this->stack = temp_0046;
		temp_0056 = new VerificationTypeInfo(in);
		this->stack->assign(0, temp_0056);
		goto L018C;
	L005D: //
		if ((this->frameType) != (247))
			goto L0088;
		this->offsetDelta = in->u2();
		temp_0071 = new JavaArray<VerificationTypeInfo>(1);
		this->stack = temp_0071;
		temp_0081 = new VerificationTypeInfo(in);
		this->stack->assign(0, temp_0081);
		goto L018C;
	L0088: //
		if ((this->frameType) < (248))
			goto L00A7;
		if ((this->frameType) > (250))
			goto L00A7;
		this->offsetDelta = in->u2();
		goto L018C;
	L00A7: //
		if ((this->frameType) != (251))
			goto L00BC;
		this->offsetDelta = in->u2();
		goto L018C;
	L00BC: //
		if ((this->frameType) < (252))
			goto L0109;
		if ((this->frameType) > (254))
			goto L0109;
		this->offsetDelta = in->u2();
		temp_00E1 = new JavaArray<VerificationTypeInfo>((this->frameType) - (251));
		this->locals = temp_00E1;
		i_00E9 = 0;
		goto L00FD;
	L00EC: //
		temp_00F6 = new VerificationTypeInfo(in);
		this->locals->assign(i_00E9, temp_00F6);
		i_00E9 += 1;
	L00FD: //
		if ((i_00E9) < (this->locals->length))
			goto L00EC;
		goto L018C;
	L0109: //
		if ((this->frameType) != (255))
			goto L0171;
		this->offsetDelta = in->u2();
		numberOfLocals_0120 = in->u2();
		temp_0122 = new JavaArray<VerificationTypeInfo>(numberOfLocals_0120);
		this->locals = temp_0122;
		i_012A = 0;
		goto L013E;
	L012D: //
		temp_0137 = new VerificationTypeInfo(in);
		this->locals->assign(i_012A, temp_0137);
		i_012A += 1;
	L013E: //
		if ((i_012A) < (numberOfLocals_0120))
			goto L012D;
		numberOfStackItems_0148 = in->u2();
		temp_014A = new JavaArray<VerificationTypeInfo>(numberOfStackItems_0148);
		this->stack = temp_014A;
		i_0153 = 0;
		goto L0168;
	L0156: //
		temp_0161 = new VerificationTypeInfo(in);
		this->stack->assign(i_0153, temp_0161);
		i_0153 += 1;
	L0168: //
		if ((i_0153) < (numberOfStackItems_0148))
			goto L0156;
		goto L018C;
	L0171: //
		temp_017B = new StringBuilder(createString("Unsupported frame type "));
		temp_0188 = new ClassFormatError(temp_017B->append(this->frameType)->toString());
		throw temp_0188;
	L018C: //
		return;
	}

}
