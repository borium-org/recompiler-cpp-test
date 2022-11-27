#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Integer.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__Iterator.h"
#include "java__util__TreeSet.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ReferencedClasses::__thisClassStatic;

	void ReferencedClasses::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ReferencedClasses",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ReferencedClasses::ReferencedClasses(Pointer<ConstantPool> cp) :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<TreeSet<Object>> temp_0009;
		temp_0009 = new TreeSet<Object>();
		this->referencedClasses = (TreeSet<String>*)temp_0009.getValue();
		cp->addReferencedClasses(this);
		return;
	}

	void ReferencedClasses::add(Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		char prefix_0009 = 0;
		Pointer<StringBuilder> temp_00BC;
		Pointer<RuntimeException> temp_00CB;
		goto L00CF;
	L0003: //
		prefix_0009 = type->charAt(0);
		type = type->substring(1);
		switch (prefix_0009)
		{
		case (int)0x00000028:
			goto L0094;
		case (int)0x00000029:
			goto L0094;
		case (int)0x0000003C:
			goto L00A9;
		case (int)0x00000042:
			goto L0094;
		case (int)0x00000043:
			goto L0094;
		case (int)0x00000044:
			goto L0094;
		case (int)0x00000046:
			goto L0094;
		case (int)0x00000049:
			goto L0094;
		case (int)0x0000004A:
			goto L0094;
		case (int)0x0000004C:
			goto L00A0;
		case (int)0x00000053:
			goto L0094;
		case (int)0x00000054:
			goto L0097;
		case (int)0x00000056:
			goto L0094;
		case (int)0x0000005A:
			goto L0094;
		case (int)0x0000005B:
			goto L0094;
		default:
			goto L00B2;
		}
	L0094: //
		goto L00CF;
	L0097: //
		type = this->skipClass(type);
		goto L00CF;
	L00A0: //
		type = this->addClass(type);
		goto L00CF;
	L00A9: //
		type = this->addTemplateBaseClasses(type);
		goto L00CF;
	L00B2: //
		temp_00BC = new StringBuilder(createString("Bad prefix \'"));
		temp_00CB = new RuntimeException(temp_00BC->append(prefix_0009)->append(createString("\'"))->toString());
		throw temp_00CB;
	L00CF: //
		if ((type->length()) > 0)
			goto L0003;
		return;
	}

	Pointer<TreeSet<String>> ReferencedClasses::getClasses()
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->referencedClasses;
	}

	int ReferencedClasses::getTemplateParameterCount(Pointer<String> fullClassName)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> referencedClass_0015;
		int pos_0029 = 0;
		Pointer<String> baseName_0046;
		Pointer<String> templateCount_0077;
		Pointer<Iterator> local_0007;
		Pointer<String> temp_0011;
		Pointer<StringBuilder> temp_0057;
		local_0007 = this->referencedClasses->iterator();
		goto L007D;
	L000B: //
		temp_0011 = (String*)((local_0007->next()).getValue());
		temp_0011->checkCast(String::__thisClassStatic);
		referencedClass_0015 = temp_0011;
		Statics::__ClassInit();
		referencedClass_0015 = Statics::javaToCppClass(referencedClass_0015->replace('/', '.'));
		pos_0029 = referencedClass_0015->indexOf(60);
		Statics::__ClassInit();
		Statics::Assert(((((pos_0029) != 0) ? (1) : (0))) != 0, createString("\'<\' at the beginning of class name"));
		if ((pos_0029) < 0)
			goto L007D;
		baseName_0046 = referencedClass_0015->substring(0, pos_0029);
		if (baseName_0046->equals(fullClassName.getValue()))
			goto L0067;
		temp_0057 = new StringBuilder(createString("::"));
		if (!(baseName_0046->endsWith(temp_0057->append(fullClassName)->toString())))
			goto L007D;
	L0067: //
		templateCount_0077 = referencedClass_0015->substring((pos_0029) + (1), (referencedClass_0015->length()) - (1));
		Integer::__ClassInit();
		return Integer::parseInt(templateCount_0077);
	L007D: //
		if (local_0007->hasNext())
			goto L000B;
		return 0;
	}

	void ReferencedClasses::removeClass(Pointer<String> className)
	{
		UsageCounterMaintainer maintainer(this, true);

		this->referencedClasses->remove(className->replace('.', '/').getValue());
		return;
	}

	Pointer<String> ReferencedClasses::addClass(Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0003;
		int parameterCount_0049 = 0;
		bool isClass_005D = false;
		Pointer<StringBuilder> temp_000E;
		Pointer<StringBuilder> temp_0096;
		className_0003 = createString("");
		goto L0023;
	L0006: //
		String::__ClassInit();
		temp_000E = new StringBuilder(String::valueOf(className_0003.getValue()));
		className_0003 = temp_000E->append(type->charAt(0))->toString();
		type = type->substring(1);
	L0023: //
		if ((type->charAt(0)) == (59))
			goto L0037;
		if ((type->charAt(0)) != (60))
			goto L0006;
	L0037: //
		if ((type->charAt(0)) != (60))
			goto L00E7;
		type = type->substring(1);
		parameterCount_0049 = 0;
		goto L007A;
	L004C: //
		isClass_005D = (((type->charAt(0)) == (76)) ? (1) : (0));
		type = type->substring(1);
		if (!(isClass_005D))
			goto L0071;
		type = this->addClass(type);
		goto L0077;
	L0071: //
		type = this->skipClass(type);
	L0077: //
		parameterCount_0049 += 1;
	L007A: //
		if ((type->charAt(0)) == (76))
			goto L004C;
		if ((type->charAt(0)) == (84))
			goto L004C;
		String::__ClassInit();
		temp_0096 = new StringBuilder(String::valueOf(className_0003.getValue()));
		className_0003 = temp_0096->append(createString("<"))->append(parameterCount_0049)->append(createString(">"))->toString();
		this->insert(className_0003);
		Statics::__ClassInit();
		Statics::Assert(((((type->charAt(0)) == (62)) ? (1) : (0))) != 0, createString("Template terminator expected"));
		type = type->substring(1);
		Statics::__ClassInit();
		Statics::Assert(((((type->charAt(0)) == (59)) ? (1) : (0))) != 0, createString("Class terminator expected"));
		type = type->substring(1);
		goto L00FC;
	L00E7: //
		if ((type->charAt(0)) != (59))
			goto L00FC;
		type = type->substring(1);
		this->insert(className_0003);
	L00FC: //
		return type;
	}

	Pointer<String> ReferencedClasses::addTemplateBaseClasses(Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		goto L0037;
	L0003: //
		type = type->substring(1);
	L0009: //
		if ((type->charAt(0)) != (58))
			goto L0003;
		type = type->substring(1);
		Statics::__ClassInit();
		Statics::Assert(((((type->charAt(0)) == (76)) ? (1) : (0))) != 0, createString("Template base class expected"));
		type = this->addClass(type->substring(1));
	L0037: //
		if ((type->charAt(0)) != (62))
			goto L0009;
		return type->substring(1);
	}

	void ReferencedClasses::insert(Pointer<String> className)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> rawTemplate_0021;
		Pointer<String> template_0048;
		Pointer<String> clazz_005F;
		Pointer<StringBuilder> temp_003C;
		Pointer<Iterator> local_004F;
		Pointer<String> temp_005B;
		if (!(this->referencedClasses->contains(className.getValue())))
			goto L000C;
		return;
	L000C: //
		if (!(className->contains(createString("<"))))
			goto L0034;
		rawTemplate_0021 = className->substring(0, className->indexOf(60));
		this->referencedClasses->remove(rawTemplate_0021.getValue());
		this->referencedClasses->add(className.getValue());
		return;
	L0034: //
		String::__ClassInit();
		temp_003C = new StringBuilder(String::valueOf(className.getValue()));
		template_0048 = temp_003C->append(createString("<"))->toString();
		local_004F = this->referencedClasses->iterator();
		goto L0068;
	L0054: //
		temp_005B = (String*)((local_004F->next()).getValue());
		temp_005B->checkCast(String::__thisClassStatic);
		clazz_005F = temp_005B;
		if (!(clazz_005F->startsWith(template_0048)))
			goto L0068;
		return;
	L0068: //
		if (local_004F->hasNext())
			goto L0054;
		this->referencedClasses->add(className.getValue());
		return;
	}

	Pointer<String> ReferencedClasses::skipClass(Pointer<String> type)
	{
		UsageCounterMaintainer maintainer(this, true);

		goto L0009;
	L0003: //
		type = type->substring(1);
	L0009: //
		if ((type->charAt(0)) == (59))
			goto L001D;
		if ((type->charAt(0)) != (60))
			goto L0003;
	L001D: //
		if ((type->charAt(0)) != (60))
			goto L007D;
		type = type->substring(1);
		goto L003C;
	L0030: //
		type = type->substring(1);
		type = this->skipClass(type);
	L003C: //
		if ((type->charAt(0)) == (76))
			goto L0030;
		Statics::__ClassInit();
		Statics::Assert(((((type->charAt(0)) == (62)) ? (1) : (0))) != 0, createString("Template terminator expected"));
		type = type->substring(1);
		Statics::__ClassInit();
		Statics::Assert(((((type->charAt(0)) == (59)) ? (1) : (0))) != 0, createString("Class terminator expected"));
		type = type->substring(1);
		goto L008D;
	L007D: //
		if ((type->charAt(0)) != (59))
			goto L008D;
		type = type->substring(1);
	L008D: //
		return type;
	}

}
