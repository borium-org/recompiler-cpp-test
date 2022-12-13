#include "stdafx.h"
#include "org__borium__javarecompiler__Statics.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__lang__Integer.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__cplusplus__JavaTypeConverter.h"

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler
{

	Pointer<Class> Statics::__thisClassStatic;

	void Statics::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::Statics",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	Statics::Statics() :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		return;
	}

	Pointer<String> Statics::addPointerIfNeeded(Pointer<String> type)
	{
		__ClassInit();

		Pointer<String> local_0002;
		Pointer<StringBuilder> temp_00CC;
		local_0002 = type;
		switch (type->hashCode())
		{
		case (int)0xB0F77BD1:
			goto L0058;
		case (int)0x000197EF:
			goto L0064;
		case (int)0x002E3AEA:
			goto L0070;
		case (int)0x002E6108:
			goto L007C;
		case (int)0x002E9356:
			goto L0088;
		case (int)0x00375194:
			goto L0094;
		case (int)0x04296ACD:
			goto L00A0;
		case (int)0x05D0225C:
			goto L00AC;
		case (int)0x0685847C:
			goto L00B8;
		default:
			goto L00C6;
		}
	L0058: //
		if (local_0002->equals(createString("double")))
			goto L00C4;
		goto L00C6;
	L0064: //
		if (local_0002->equals(createString("int")))
			goto L00C4;
		goto L00C6;
	L0070: //
		if (local_0002->equals(createString("bool")))
			goto L00C4;
		goto L00C6;
	L007C: //
		if (local_0002->equals(createString("byte")))
			goto L00C4;
		goto L00C6;
	L0088: //
		if (local_0002->equals(createString("char")))
			goto L00C4;
		goto L00C6;
	L0094: //
		if (local_0002->equals(createString("void")))
			goto L00C4;
		goto L00C6;
	L00A0: //
		if (local_0002->equals(createString("INT64")))
			goto L00C4;
		goto L00C6;
	L00AC: //
		if (local_0002->equals(createString("float")))
			goto L00C4;
		goto L00C6;
	L00B8: //
		if (local_0002->equals(createString("short")))
			goto L00C4;
		goto L00C6;
	L00C4: //
		return type;
	L00C6: //
		temp_00CC = new StringBuilder(createString("Pointer<"));
		return temp_00CC->append(type)->append(createString(">"))->toString();
	}

	Pointer<String> Statics::addPointersIfNeeded(Pointer<String> methodType)
	{
		__ClassInit();

		Pointer<String> signature_0002;
		Pointer<String> result_0010;
		int pos_0020 = 0;
		Pointer<String> type_0036;
		Pointer<StringBuilder> temp_003E;
		Pointer<StringBuilder> temp_0065;
		Pointer<StringBuilder> temp_00A0;
		Pointer<StringBuilder> temp_00C3;
		Pointer<StringBuilder> temp_00E4;
		signature_0002 = methodType;
		Statics::__ClassInit();
		Statics::Assert(signature_0002->startsWith(createString("(")), createString("Method type: Method() expected"));
		result_0010 = createString("(");
		signature_0002 = signature_0002->substring(1);
		goto L00B2;
	L0019: //
		pos_0020 = signature_0002->indexOf(32);
		Statics::__ClassInit();
		Statics::Assert(((((pos_0020) > 0) ? (1) : (0))) != 0, createString("Method type: Space between type and name not found"));
		type_0036 = signature_0002->substring(0, pos_0020);
		String::__ClassInit();
		temp_003E = new StringBuilder(String::valueOf(result_0010.getValue()));
		Statics::__ClassInit();
		result_0010 = temp_003E->append(Statics::addPointerIfNeeded(type_0036))->append(createString(" "))->toString();
		signature_0002 = signature_0002->substring((pos_0020) + (1));
		goto L007B;
	L005D: //
		String::__ClassInit();
		temp_0065 = new StringBuilder(String::valueOf(result_0010.getValue()));
		result_0010 = temp_0065->append(signature_0002->substring(0, 1))->toString();
		signature_0002 = signature_0002->substring(1);
	L007B: //
		if ((signature_0002->charAt(0)) == (44))
			goto L008F;
		if ((signature_0002->charAt(0)) != (41))
			goto L005D;
	L008F: //
		if (!(signature_0002->startsWith(createString(", "))))
			goto L00B2;
		String::__ClassInit();
		temp_00A0 = new StringBuilder(String::valueOf(result_0010.getValue()));
		result_0010 = temp_00A0->append(createString(", "))->toString();
		signature_0002 = signature_0002->substring(2);
	L00B2: //
		if (!(signature_0002->startsWith(createString(")"))))
			goto L0019;
		String::__ClassInit();
		temp_00C3 = new StringBuilder(String::valueOf(result_0010.getValue()));
		result_0010 = temp_00C3->append(')')->toString();
		signature_0002 = signature_0002->substring(1);
		if ((signature_0002->length()) <= 0)
			goto L00F2;
		String::__ClassInit();
		temp_00E4 = new StringBuilder(String::valueOf(result_0010.getValue()));
		Statics::__ClassInit();
		result_0010 = temp_00E4->append(Statics::addPointerIfNeeded(signature_0002))->toString();
	L00F2: //
		return result_0010;
	}

	void Statics::Assert(bool condition, Pointer<String> errorMessage)
	{
		__ClassInit();

		Pointer<RuntimeException> temp_0009;
		if (condition)
			goto L000D;
		temp_0009 = new RuntimeException(errorMessage);
		throw temp_0009;
	L000D: //
		return;
	}

	void Statics::Check(Pointer<IndentedOutputStream> stream, bool condition, Pointer<String> errorMessage)
	{
		__ClassInit();

		Pointer<StringBuilder> temp_000B;
		if (condition)
			goto L0018;
		temp_000B = new StringBuilder(createString("// "));
		stream->iprintln(temp_000B->append(errorMessage)->toString());
	L0018: //
		return;
	}

	Pointer<String> Statics::commaSeparatedList(Pointer<JavaArray<String>> values)
	{
		__ClassInit();

		Pointer<String> result_0003;
		Pointer<String> separator_0006;
		Pointer<String> param_0019;
		Pointer<JavaArray<String>> local_0008;
		int local_000B = 0;
		int local_000E = 0;
		Pointer<StringBuilder> temp_0021;
		result_0003 = createString("");
		separator_0006 = createString("");
		local_0008 = (JavaArray<String>*)(values.getValue());
		local_000B = values->length;
		local_000E = 0;
		goto L0036;
	L0013: //
		param_0019 = local_0008->get(local_000E);
		String::__ClassInit();
		temp_0021 = new StringBuilder(String::valueOf(result_0003.getValue()));
		result_0003 = temp_0021->append(separator_0006)->append(param_0019)->toString();
		separator_0006 = createString(", ");
		local_000E += 1;
	L0036: //
		if ((local_000E) < (local_000B))
			goto L0013;
		return result_0003;
	}

	Pointer<String> Statics::dotToNamespace(Pointer<String> dots)
	{
		__ClassInit();

		String::__ClassInit();
		return String::join(createString("::"), dots->split(createString("[.]")).getValue());
	}

	Pointer<String> Statics::escapeCharacters(Pointer<String> string)
	{
		__ClassInit();

		Pointer<StringBuilder> sb_0008;
		int i_000A = 0;
		char ch_0013 = 0;
		Pointer<StringBuilder> temp_0004;
		temp_0004 = new StringBuilder();
		sb_0008 = temp_0004;
		i_000A = 0;
		goto L0095;
	L000D: //
		ch_0013 = string->charAt(i_000A);
		switch (ch_0013)
		{
		case (int)0x00000009:
			goto L0064;
		case (int)0x0000000A:
			goto L0050;
		case (int)0x0000000D:
			goto L005A;
		case (int)0x00000022:
			goto L0078;
		case (int)0x00000027:
			goto L006E;
		case (int)0x0000005C:
			goto L0082;
		default:
			goto L008C;
		}
	L0050: //
		sb_0008->append(createString("\\n"));
		goto L0092;
	L005A: //
		sb_0008->append(createString("\\r"));
		goto L0092;
	L0064: //
		sb_0008->append(createString("\\t"));
		goto L0092;
	L006E: //
		sb_0008->append(createString("\\\'"));
		goto L0092;
	L0078: //
		sb_0008->append(createString("\\\""));
		goto L0092;
	L0082: //
		sb_0008->append(createString("\\\\"));
		goto L0092;
	L008C: //
		sb_0008->append(ch_0013);
	L0092: //
		i_000A += 1;
	L0095: //
		if ((i_000A) < (string->length()))
			goto L000D;
		return sb_0008->toString();
	}

	int Statics::getParameterCount(Pointer<String> javaDescriptor)
	{
		__ClassInit();

		Pointer<JavaRawArray<int>> data_001B;
		Pointer<RuntimeException> temp_000F;
		Pointer<JavaRawArray<int>> temp_0014;
		if (javaDescriptor->startsWith(createString("(")))
			goto L0013;
		temp_000F = new RuntimeException(createString("Get parameter count for non-method"));
		throw temp_000F;
	L0013: //
		temp_0014 = new JavaRawArray<int>(2);
		temp_0014->assign(0, 1);
		data_001B = (JavaRawArray<int>*)(temp_0014.getValue());
		goto L0023;
	L001E: //
		Statics::__ClassInit();
		Statics::parseSingleType(javaDescriptor, data_001B);
	L0023: //
		if ((javaDescriptor->charAt(data_001B->get(0))) != (41))
			goto L001E;
		return data_001B->get(1);
	}

	Pointer<String> Statics::hexString(int value, int length)
	{
		__ClassInit();

		Pointer<String> result_0014;
		Pointer<StringBuilder> temp_0006;
		temp_0006 = new StringBuilder(createString("00000000"));
		Integer::__ClassInit();
		result_0014 = temp_0006->append(Integer::toHexString(value))->toString();
		result_0014 = result_0014->substring((result_0014->length()) - (length));
		return result_0014->toUpperCase();
	}

	bool Statics::isTemplate(Pointer<String> type)
	{
		__ClassInit();

		int index_0007 = 0;
		index_0007 = type->indexOf(60);
		Statics::__ClassInit();
		Statics::Assert(((((index_0007) != 0) ? (1) : (0))) != 0, createString("Template: Starts with \'<\'"));
		if ((index_0007) <= 0)
			goto L001B;
		return 1;
	L001B: //
		return 0;
	}

	Pointer<String> Statics::javaToCppClass(Pointer<String> javaClassName)
	{
		__ClassInit();

		Pointer<JavaArray<String>> split_0007;
		split_0007 = (JavaArray<String>*)(javaClassName->split(createString("[.]")).getValue());
		String::__ClassInit();
		return String::join(createString("::"), split_0007.getValue());
	}

	Pointer<String> Statics::parseJavaReturnType(Pointer<String> javaMethodSignature)
	{
		__ClassInit();

		int pos_0007 = 0;
		Pointer<String> type_001E;
		int dimensions_0020 = 0;
		Pointer<String> returnType_003A;
		bool rawType_003D = false;
		Pointer<JavaTypeConverter> temp_00F5;
		Pointer<StringBuilder> temp_0121;
		Pointer<StringBuilder> temp_013E;
		Pointer<StringBuilder> temp_0162;
		pos_0007 = javaMethodSignature->indexOf(41);
		Statics::__ClassInit();
		Statics::Assert(((((pos_0007) >= (1)) ? (1) : (0))) != 0, createString("Method with no return type"));
		type_001E = javaMethodSignature->substring((pos_0007) + (1));
		dimensions_0020 = 0;
		goto L002C;
	L0023: //
		dimensions_0020 += 1;
		type_001E = type_001E->substring(1);
	L002C: //
		if ((type_001E->charAt(0)) == (91))
			goto L0023;
		returnType_003A = createString("");
		rawType_003D = 1;
		switch (type_001E->charAt(0))
		{
		case 66:
			goto L00B4;
		case 67:
			goto L00BB;
		case 68:
			goto L00C2;
		case 69:
			goto L011A;
		case 70:
			goto L00C9;
		case 71:
			goto L011A;
		case 72:
			goto L011A;
		case 73:
			goto L00D0;
		case 74:
			goto L00D7;
		case 75:
			goto L011A;
		case 76:
			goto L00EC;
		case 77:
			goto L011A;
		case 78:
			goto L011A;
		case 79:
			goto L011A;
		case 80:
			goto L011A;
		case 81:
			goto L011A;
		case 82:
			goto L011A;
		case 83:
			goto L00DE;
		case 84:
			goto L0100;
		case 85:
			goto L011A;
		case 86:
			goto L0113;
		case 87:
			goto L011A;
		case 88:
			goto L011A;
		case 89:
			goto L011A;
		case 90:
			goto L00E5;
		default:
			goto L011A;
		}
	L00B4: //
		returnType_003A = createString("byte");
		goto L012E;
	L00BB: //
		returnType_003A = createString("char");
		goto L012E;
	L00C2: //
		returnType_003A = createString("double");
		goto L012E;
	L00C9: //
		returnType_003A = createString("float");
		goto L012E;
	L00D0: //
		returnType_003A = createString("int");
		goto L012E;
	L00D7: //
		returnType_003A = createString("INT64");
		goto L012E;
	L00DE: //
		returnType_003A = createString("short");
		goto L012E;
	L00E5: //
		returnType_003A = createString("bool");
		goto L012E;
	L00EC: //
		rawType_003D = 0;
		temp_00F5 = new JavaTypeConverter(type_001E, false);
		returnType_003A = temp_00F5->getCppType();
		goto L012E;
	L0100: //
		rawType_003D = 0;
		returnType_003A = type_001E->substring(1, (type_001E->length()) - (1));
		goto L012E;
	L0113: //
		returnType_003A = createString("void");
		goto L012E;
	L011A: //
		temp_0121 = new StringBuilder(createString("Unhandled type "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_0121->append(type_001E)->toString());
	L012E: //
		temp_013E = new StringBuilder(createString("Too many dimensions: "));
		Statics::__ClassInit();
		Statics::Assert(((((dimensions_0020) <= (1)) ? (1) : (0))) != 0, temp_013E->append(dimensions_0020)->toString());
		if ((dimensions_0020) <= 0)
			goto L017C;
		String::__ClassInit();
		temp_0162 = new StringBuilder(String::valueOf(((rawType_003D) ? (((Pointer<String>) new String("JavaRawArray"))) : (((Pointer<String>) new String("JavaArray")))).getValue()));
		returnType_003A = temp_0162->append(createString("<"))->append(returnType_003A)->append(createString(">"))->toString();
		dimensions_0020 += -1;
	L017C: //
		return returnType_003A;
	}

	Pointer<String> Statics::removeJavaArray(Pointer<String> javaArray)
	{
		__ClassInit();

		if (!(javaArray->startsWith(createString("JavaArray<"))))
			goto L0016;
		return javaArray->substring(10, (javaArray->length()) - (1));
	L0016: //
		if (!(javaArray->startsWith(createString("JavaRawArray<"))))
			goto L002C;
		return javaArray->substring(13, (javaArray->length()) - (1));
	L002C: //
		Statics::__ClassInit();
		Statics::Assert(false, createString("JavaArray<> or JavaRawArray<> expected"));
		// ARETURN: Type mismatch
		return (String*)nullptr;
	}

	Pointer<String> Statics::removePointerWrapper(Pointer<String> wrappedObject)
	{
		__ClassInit();

		Statics::__ClassInit();
		Statics::Assert(wrappedObject->startsWith(createString("Pointer<")), createString("Pointer<> expected"));
		return wrappedObject->substring(8, (wrappedObject->length()) - (1));
	}

	void Statics::parseClass(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data)
	{
		__ClassInit();

		Pointer<RuntimeException> temp_0034;
		goto L000A;
	L0003: //
		data->assign(0, (data->get(0)) + (1));
	L000A: //
		if ((descriptor->charAt(data->get(0))) == (59))
			goto L0022;
		if ((descriptor->charAt(data->get(0))) != (60))
			goto L0003;
	L0022: //
		if ((descriptor->charAt(data->get(0))) != (60))
			goto L0038;
		temp_0034 = new RuntimeException(createString("Templates not supported"));
		throw temp_0034;
	L0038: //
		if ((descriptor->charAt(data->get(0))) != (59))
			goto L004B;
		data->assign(0, (data->get(0)) + (1));
	L004B: //
		return;
	}

	void Statics::parseSingleType(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data)
	{
		__ClassInit();

		goto L000A;
	L0003: //
		data->assign(0, (data->get(0)) + (1));
	L000A: //
		if ((descriptor->charAt(data->get(0))) == (91))
			goto L0003;
		switch (descriptor->charAt(data->get(0)))
		{
		case 66:
			goto L0090;
		case 67:
			goto L0090;
		case 68:
			goto L0090;
		case 69:
			goto L00BE;
		case 70:
			goto L0090;
		case 71:
			goto L00BE;
		case 72:
			goto L00BE;
		case 73:
			goto L0090;
		case 74:
			goto L0090;
		case 75:
			goto L00BE;
		case 76:
			goto L00A1;
		case 77:
			goto L00BE;
		case 78:
			goto L00BE;
		case 79:
			goto L00BE;
		case 80:
			goto L00BE;
		case 81:
			goto L00BE;
		case 82:
			goto L00BE;
		case 83:
			goto L0090;
		case 84:
			goto L00BE;
		case 85:
			goto L00BE;
		case 86:
			goto L00B7;
		case 87:
			goto L00BE;
		case 88:
			goto L00BE;
		case 89:
			goto L00BE;
		case 90:
			goto L0090;
		default:
			goto L00BE;
		}
	L0090: //
		data->assign(0, (data->get(0)) + (1));
		data->assign(1, (data->get(1)) + (1));
		goto L00BE;
	L00A1: //
		data->assign(0, (data->get(0)) + (1));
		data->assign(1, (data->get(1)) + (1));
		Statics::__ClassInit();
		Statics::parseClass(descriptor, data);
		goto L00BE;
	L00B7: //
		data->assign(0, (data->get(0)) + (1));
	L00BE: //
		return;
	}

}
