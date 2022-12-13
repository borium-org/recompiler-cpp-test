#include "stdafx.h"
#include "org__borium__javarecompiler__cplusplus__CppClass.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__IOException.h"
#include "java__lang__Character.h"
#include "java__lang__Integer.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuffer.h"
#include "java__lang__StringBuilder.h"
#include "java__util__HashMap.h"
#include "java__util__Iterator.h"
#include "java__util__TreeSet.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ClassField.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "org__borium__javarecompiler__classfile__ClassMethod.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"
#include "org__borium__javarecompiler__cplusplus__CppField.h"
#include "org__borium__javarecompiler__cplusplus__CppMethod.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	Pointer<Class> CppClass::__thisClassStatic;

	void CppClass::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::cplusplus::CppClass",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	CppClass::CppClass(Pointer<ClassFile> classFile) :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

		Pointer<TreeSet<Object>> temp_0009;
		Pointer<TreeSet<Object>> temp_0014;
		temp_0009 = new TreeSet<Object>();
		this->namespaces = (TreeSet<String>*)temp_0009.getValue();
		temp_0014 = new TreeSet<Object>();
		this->multipleClasses = (TreeSet<String>*)temp_0014.getValue();
		this->classFile = classFile.getValue();
		this->extractCppClassName();
		this->extractParentClassName();
		this->extractNamespaces();
		this->extractFields();
		this->extractMethods();
		return;
	}

	Pointer<CppField> CppClass::getField(Pointer<String> fieldName)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<CppField> field_0014;
		Pointer<JavaArray<CppField>> local_0005;
		int local_0008 = 0;
		int local_000B = 0;
		Pointer<StringBuilder> temp_0031;
		local_0005 = (JavaArray<CppField>*)(this->fields.getValue());
		local_0008 = this->fields->length;
		local_000B = 0;
		goto L0024;
	L000F: //
		field_0014 = local_0005->get(local_000B);
		if (!(field_0014->getName()->equals(fieldName.getValue())))
			goto L0021;
		return field_0014;
	L0021: //
		local_000B += 1;
	L0024: //
		if ((local_000B) < (local_0008))
			goto L000F;
		temp_0031 = new StringBuilder(createString("Field "));
		Statics::__ClassInit();
		Statics::Assert(false, temp_0031->append(fieldName)->append(createString(" not found"))->toString());
		// ARETURN: Type mismatch
		return (CppField*)nullptr;
	}

	Pointer<String> CppClass::getFullClassName()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_000B;
		String::__ClassInit();
		temp_000B = new StringBuilder(String::valueOf(this->nameSpace.getValue()));
		return temp_000B->append(createString("::"))->append(this->className)->toString();
	}

	int CppClass::getTemplateParameterCount(Pointer<String> fullClassName)
	{
		UsageCounterMaintainer maintainer(this, true);

		return this->referencedClasses->getTemplateParameterCount(fullClassName);
	}

	bool CppClass::isAssignable(Pointer<String> source, Pointer<String> destination)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> assign_0077;
		Pointer<StringBuilder> temp_0067;
		Pointer<String> local_0079;
		source = this->simplifyType(source);
		destination = this->simplifyType(destination);
		if (!(source->contains(createString("<"))))
			goto L0021;
		source = source->substring(0, source->indexOf(60));
	L0021: //
		if (!(destination->contains(createString("<"))))
			goto L0036;
		destination = destination->substring(0, destination->indexOf(60));
	L0036: //
		if (!(source->equals(destination.getValue())))
			goto L0040;
		return 1;
	L0040: //
		if (!(destination->equals(createString("Object"))))
			goto L004B;
		return 1;
	L004B: //
		if (!(source->equals(createString("nullptr"))))
			goto L005F;
		if (!(destination->endsWith(createString("*"))))
			goto L005F;
		return 1;
	L005F: //
		String::__ClassInit();
		temp_0067 = new StringBuilder(String::valueOf(source.getValue()));
		assign_0077 = temp_0067->append(createString("="))->append(destination)->toString();
		local_0079 = assign_0077;
		switch (assign_0077->hashCode())
		{
		case (int)0x90A3EF9A:
			goto L00C0;
		case (int)0xAAE906B3:
			goto L00CD;
		case (int)0x0AADCE64:
			goto L00DA;
		case (int)0x1B051D2B:
			goto L00E7;
		case (int)0x1FC4DA18:
			goto L00F4;
		case (int)0x1FC53284:
			goto L0101;
		case (int)0x6AFCF349:
			goto L010E;
		default:
			goto L011D;
		}
	L00C0: //
		if (local_0079->equals(createString("byte=int")))
			goto L011B;
		goto L011D;
	L00CD: //
		if (local_0079->equals(createString("class=Class")))
			goto L011B;
		goto L011D;
	L00DA: //
		if (local_0079->equals(createString("ArrayList=List")))
			goto L011B;
		goto L011D;
	L00E7: //
		if (local_0079->equals(createString("ClassFormatError=Exception")))
			goto L011B;
		goto L011D;
	L00F4: //
		if (local_0079->equals(createString("int=bool")))
			goto L011B;
		goto L011D;
	L0101: //
		if (local_0079->equals(createString("int=char")))
			goto L011B;
		goto L011D;
	L010E: //
		if (local_0079->equals(createString("RuntimeException=Exception")))
			goto L011B;
		goto L011D;
	L011B: //
		return 1;
	L011D: //
		return 0;
	}

	void CppClass::writeClass(Pointer<String> outputPath)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<IndentedOutputStream> header_004F;
		Pointer<IndentedOutputStream> source_0076;
		Pointer<IOException> e_008C;
		Pointer<StringBuilder> temp_0013;
		Pointer<StringBuilder> temp_0034;
		Pointer<IndentedOutputStream> temp_004B;
		Pointer<StringBuilder> temp_005B;
		Pointer<IndentedOutputStream> temp_0072;
	L0000: //
		try
		{
			Pointer<IndentedOutputStream> header_004F;
			Pointer<IndentedOutputStream> source_0076;
			String::__ClassInit();
			temp_0013 = new StringBuilder(String::valueOf(this->nameSpace->replace(':', '_').getValue()));
			this->fileName = temp_0013->append(createString("__"))->append(this->className)->toString().getValue();
			String::__ClassInit();
			temp_0034 = new StringBuilder(String::valueOf(outputPath.getValue()));
			temp_004B = new IndentedOutputStream(temp_0034->append('/')->append(this->fileName)->append(createString(".h"))->toString());
			header_004F = temp_004B;
			String::__ClassInit();
			temp_005B = new StringBuilder(String::valueOf(outputPath.getValue()));
			temp_0072 = new IndentedOutputStream(temp_005B->append('/')->append(this->fileName)->append(createString(".cpp"))->toString());
			source_0076 = temp_0072;
			this->generateHeader(header_004F);
			this->generateSource(source_0076);
			header_004F->close();
			source_0076->close();
		L0088: //
			goto L0090;
		}
		catch (IOException* e_008C)
		{
			e_008C->printStackTrace();
		}
	L0090: //
		return;
	}

	Pointer<String> CppClass::simplifyType(Pointer<String> className)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuffer> sb_000C;
		int index_000E = 0;
		Pointer<StringBuffer> component_001B;
		Pointer<String> componentType_009F;
		Pointer<String> componentType_00FC;
		Pointer<StringBuffer> temp_0008;
		Pointer<StringBuffer> temp_0016;
		Pointer<StringBuilder> temp_00C7;
		Pointer<RuntimeException> temp_00DE;
		temp_0008 = new StringBuffer(className->length());
		sb_000C = temp_0008;
		index_000E = 0;
		temp_0016 = new StringBuffer(className->length());
		component_001B = temp_0016;
		goto L00E5;
	L001E: //
		Character::__ClassInit();
		if (Character::isJavaIdentifierPart(className->charAt(index_000E)))
			goto L0033;
		if ((className->charAt(index_000E)) != (58))
			goto L0041;
	L0033: //
		component_001B->append(className->charAt(index_000E));
		goto L00E2;
	L0041: //
		switch (className->charAt(index_000E))
		{
		case (int)0x00000020:
			goto L0098;
		case (int)0x00000028:
			goto L0098;
		case (int)0x00000029:
			goto L0098;
		case (int)0x0000002A:
			goto L0098;
		case (int)0x0000002C:
			goto L0098;
		case (int)0x0000003C:
			goto L0098;
		case (int)0x0000003E:
			goto L0098;
		case (int)0x0000005B:
			goto L0098;
		case (int)0x0000005D:
			goto L0098;
		default:
			goto L00BD;
		}
	L0098: //
		componentType_009F = component_001B->toString();
		sb_000C->append(this->simplifyTypeComponent(componentType_009F));
		component_001B->setLength(0);
		sb_000C->append(className->charAt(index_000E));
		goto L00E2;
	L00BD: //
		temp_00C7 = new StringBuilder(createString("SimplifyType: unexpected \'"));
		temp_00DE = new RuntimeException(temp_00C7->append(className->charAt(index_000E))->append(createString("\' in "))->append(className)->toString());
		throw temp_00DE;
	L00E2: //
		index_000E += 1;
	L00E5: //
		if ((index_000E) < (className->length()))
			goto L001E;
		if ((component_001B->length()) <= 0)
			goto L0107;
		componentType_00FC = component_001B->toString();
		sb_000C->append(this->simplifyTypeComponent(componentType_00FC));
	L0107: //
		return sb_000C->toString();
	}

	void CppClass::generateHeader(Pointer<IndentedOutputStream> header)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0021;
		header->println(createString("#pragma once"));
		header->println();
		this->generateHeaderIncludesAndNamespaces(header);
		this->generateHeaderBeginThisClassNamespace(header);
		header->println();
		temp_0021 = new StringBuilder(createString("class "));
		header->iprintln(temp_0021->append(this->classFile->getClassSimpleName())->append(createString(" : public "))->append(this->simplifyType(this->parentClassName))->toString());
		header->iprintln(createString("{"));
		this->generateHeaderJavaClass(header);
		header->iprintln(createString("public:"));
		header->indent(1);
		this->generateHeaderFields(header);
		this->generateHeaderMethods(header);
		header->indent(-1);
		header->iprintln(createString("};"));
		header->println();
		this->generateHeaderEndThisClassNamespace(header);
		return;
	}

	void CppClass::generateSource(Pointer<IndentedOutputStream> source)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_000F;
		Pointer<StringBuilder> temp_0057;
		source->println(createString("#include \"stdafx.h\""));
		temp_000F = new StringBuilder(createString("#include \""));
		source->println(temp_000F->append(this->nameSpace->replace(':', '_'))->append(createString("__"))->append(this->className)->append(createString(".h\""))->toString());
		source->println(createString("#include \"java__lang__Class.h\""));
		source->println(createString("#include \"java__lang__String.h\""));
		source->println();
		this->generateSourceIncludesAndNamespaces(source);
		temp_0057 = new StringBuilder(createString("namespace "));
		source->println(temp_0057->append(this->nameSpace)->toString());
		source->println(createString("{"));
		source->println();
		source->indent(1);
		this->generateSourceJavaClass(source);
		this->generateSourceStaticFields(source);
		this->generateSourceMethods(source);
		source->indent(-1);
		source->println(createString("}"));
		return;
	}

	void CppClass::extractCppClassName()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> cppName_000B;
		int pos_0012 = 0;
		Pointer<StringBuilder> temp_0022;
		Pointer<RuntimeException> temp_0032;
		Statics::__ClassInit();
		cppName_000B = Statics::dotToNamespace(this->classFile->getClassName());
		pos_0012 = cppName_000B->lastIndexOf(58);
		if ((pos_0012) != (-1))
			goto L0036;
		temp_0022 = new StringBuilder(createString("Not a fully qualified name: \'"));
		temp_0032 = new RuntimeException(temp_0022->append(cppName_000B)->append(createString("\'"))->toString());
		throw temp_0032;
	L0036: //
		this->className = cppName_000B->substring((pos_0012) + (1)).getValue();
		this->nameSpace = cppName_000B->substring(0, (pos_0012) - (1)).getValue();
		return;
	}

	void CppClass::extractFields()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<ClassField>> javaFields_0008;
		int i_0013 = 0;
		Pointer<ClassField> javaField_001A;
		Pointer<CppField> field_0024;
		Pointer<JavaArray<CppField>> temp_000B;
		Pointer<CppField> temp_001F;
		javaFields_0008 = (JavaArray<ClassField>*)(this->classFile->getFields().getValue());
		temp_000B = new JavaArray<CppField>(javaFields_0008->length);
		this->fields = temp_000B;
		i_0013 = 0;
		goto L002F;
	L0016: //
		javaField_001A = javaFields_0008->get(i_0013);
		temp_001F = new CppField(javaField_001A);
		field_0024 = temp_001F;
		this->fields->assign(i_0013, field_0024);
		i_0013 += 1;
	L002F: //
		if ((i_0013) < (javaFields_0008->length))
			goto L0016;
		return;
	}

	void CppClass::extractMethods()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<JavaArray<ClassMethod>> javaMethods_0008;
		int i_0013 = 0;
		Pointer<ClassMethod> javaMethod_001A;
		Pointer<CppMethod> method_0025;
		Pointer<JavaArray<CppMethod>> temp_000B;
		Pointer<CppMethod> temp_0020;
		javaMethods_0008 = (JavaArray<ClassMethod>*)(this->classFile->getMethods().getValue());
		temp_000B = new JavaArray<CppMethod>(javaMethods_0008->length);
		this->methods = temp_000B;
		i_0013 = 0;
		goto L0030;
	L0016: //
		javaMethod_001A = javaMethods_0008->get(i_0013);
		temp_0020 = new CppMethod(this, javaMethod_001A);
		method_0025 = temp_0020;
		this->methods->assign(i_0013, method_0025);
		i_0013 += 1;
	L0030: //
		if ((i_0013) < (javaMethods_0008->length))
			goto L0016;
		return;
	}

	void CppClass::extractNamespaces()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<HashMap<String, String>> classes_0008;
		Pointer<ReferencedClasses> referencedClassNames_0010;
		Pointer<String> referencedClassName_0027;
		Pointer<String> cppClassName_003E;
		int pos_0047 = 0;
		Pointer<String> packageName_0051;
		Pointer<String> namespace_0058;
		Pointer<String> className_006D;
		Pointer<HashMap<Object, Object>> temp_0004;
		Pointer<Iterator> local_0017;
		Pointer<String> temp_0023;
		temp_0004 = new HashMap<Object, Object>();
		classes_0008 = (HashMap<String, String>*)(temp_0004.getValue());
		referencedClassNames_0010 = this->classFile->getReferencedClasses();
		local_0017 = referencedClassNames_0010->getClasses()->iterator();
		goto L0091;
	L001C: //
		temp_0023 = (String*)((local_0017->next()).getValue());
		temp_0023->checkCast(String::__thisClassStatic);
		referencedClassName_0027 = temp_0023;
		if ((referencedClassName_0027->charAt(0)) != (91))
			goto L0034;
		goto L0091;
	L0034: //
		cppClassName_003E = referencedClassName_0027->replace('/', '.');
		pos_0047 = cppClassName_003E->lastIndexOf(46);
		packageName_0051 = cppClassName_003E->substring(0, pos_0047);
		Statics::__ClassInit();
		namespace_0058 = Statics::dotToNamespace(packageName_0051);
		this->namespaces->add(namespace_0058.getValue());
		className_006D = cppClassName_003E->substring((pos_0047) + (1));
		if (!(classes_0008->containsKey(className_006D.getValue())))
			goto L0088;
		if (classes_0008->containsValue(referencedClassName_0027.getValue()))
			goto L0088;
		this->multipleClasses->add(className_006D.getValue());
	L0088: //
		classes_0008->put(className_006D.getValue(), cppClassName_003E.getValue());
	L0091: //
		if (local_0017->hasNext())
			goto L001C;
		return;
	}

	void CppClass::extractParentClassName()
	{
		UsageCounterMaintainer maintainer(this, true);

		Statics::__ClassInit();
		this->parentClassName = Statics::dotToNamespace(this->classFile->getParentClassName()).getValue();
		return;
	}

	void CppClass::generateHeaderBeginThisClassNamespace(Pointer<IndentedOutputStream> header)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0008;
		temp_0008 = new StringBuilder(createString("namespace "));
		header->println(temp_0008->append(this->nameSpace)->toString());
		header->println(createString("{"));
		header->indent(1);
		return;
	}

	void CppClass::generateHeaderClassInitIfNeeded(Pointer<IndentedOutputStream> header)
	{
		UsageCounterMaintainer maintainer(this, true);

		bool classInitFound_0002 = false;
		Pointer<CppMethod> method_0018;
		Pointer<String> methodName_001E;
		Pointer<JavaArray<CppMethod>> local_0007;
		int local_000A = 0;
		int local_000D = 0;
		classInitFound_0002 = 0;
		local_0007 = (JavaArray<CppMethod>*)(this->methods.getValue());
		local_000A = this->methods->length;
		local_000D = 0;
		goto L0031;
	L0012: //
		method_0018 = local_0007->get(local_000D);
		methodName_001E = method_0018->getName();
		if (!(methodName_001E->equals(createString("<clinit>"))))
			goto L002E;
		classInitFound_0002 = 1;
		goto L0038;
	L002E: //
		local_000D += 1;
	L0031: //
		if ((local_000D) < (local_000A))
			goto L0012;
	L0038: //
		if (classInitFound_0002)
			goto L0043;
		header->iprintln(createString("static void __ClassInit();"));
	L0043: //
		return;
	}

	void CppClass::generateHeaderEndThisClassNamespace(Pointer<IndentedOutputStream> header)
	{
		UsageCounterMaintainer maintainer(this, true);

		header->indent(-1);
		header->println(createString("}"));
		return;
	}

	void CppClass::generateHeaderFields(Pointer<IndentedOutputStream> header)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<CppField> field_0014;
		Pointer<String> fieldType_001A;
		Pointer<String> newType_0022;
		Pointer<JavaArray<CppField>> local_0005;
		int local_0008 = 0;
		int local_000B = 0;
		local_0005 = (JavaArray<CppField>*)(this->fields.getValue());
		local_0008 = this->fields->length;
		local_000B = 0;
		goto L0033;
	L000F: //
		field_0014 = local_0005->get(local_000B);
		fieldType_001A = field_0014->getType();
		newType_0022 = this->simplifyType(fieldType_001A);
		if (!(field_0014->isPresentInSource()))
			goto L0030;
		field_0014->generateHeader(header, newType_0022);
	L0030: //
		local_000B += 1;
	L0033: //
		if ((local_000B) < (local_0008))
			goto L000F;
		header->println();
		return;
	}

	void CppClass::generateHeaderIncludesAndNamespaces(Pointer<IndentedOutputStream> header)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> superClassName_0008;
		Pointer<ReferencedClasses> referencedClassNames_0039;
		Pointer<String> packageName_0051;
		Pointer<String> reference_008B;
		Pointer<String> template_0090;
		int pos_00A7 = 0;
		int templateCount_00EA = 0;
		int i_00FC = 0;
		Pointer<String> packageName_01D2;
		Pointer<StringBuilder> temp_0010;
		Pointer<Iterator> local_0040;
		Pointer<String> temp_004C;
		Pointer<StringBuilder> temp_0059;
		Pointer<Iterator> local_007A;
		Pointer<String> temp_0086;
		Pointer<StringBuilder> temp_0108;
		Pointer<StringBuilder> temp_012A;
		Pointer<StringBuilder> temp_0154;
		Pointer<StringBuilder> temp_017C;
		Pointer<String> temp_01CD;
		Pointer<StringBuilder> temp_01DA;
		superClassName_0008 = this->classFile->getParentClassName();
		temp_0010 = new StringBuilder(createString("#include \""));
		Statics::__ClassInit();
		header->println(temp_0010->append(Statics::dotToNamespace(superClassName_0008)->replace(':', '_'))->append(createString(".h\""))->toString());
		header->println();
		referencedClassNames_0039 = this->classFile->getReferencedClasses();
		local_0040 = this->namespaces->iterator();
		goto L01B0;
	L0045: //
		temp_004C = (String*)((local_0040->next()).getValue());
		temp_004C->checkCast(String::__thisClassStatic);
		packageName_0051 = temp_004C;
		temp_0059 = new StringBuilder(createString("namespace "));
		header->println(temp_0059->append(packageName_0051)->toString());
		header->println(createString("{"));
		header->indent(1);
		local_007A = referencedClassNames_0039->getClasses()->iterator();
		goto L0196;
	L007F: //
		temp_0086 = (String*)((local_007A->next()).getValue());
		temp_0086->checkCast(String::__thisClassStatic);
		reference_008B = temp_0086;
		template_0090 = createString("");
		Statics::__ClassInit();
		reference_008B = Statics::dotToNamespace(reference_008B->replace('/', '.'));
		pos_00A7 = reference_008B->lastIndexOf(createString("::"));
		Statics::__ClassInit();
		Statics::Assert(((((pos_00A7) > 0) ? (1) : (0))) != 0, createString("Fully qualified class name expected"));
		if (!(reference_008B->substring(0, pos_00A7)->equals(packageName_0051.getValue())))
			goto L0196;
		pos_00A7 = reference_008B->indexOf(60);
		if ((pos_00A7) < 0)
			goto L0162;
		Integer::__ClassInit();
		templateCount_00EA = Integer::parseInt(reference_008B->substring((pos_00A7) + (1), (reference_008B->length()) - (1)));
		reference_008B = reference_008B->substring(0, pos_00A7);
		template_0090 = createString("template <");
		i_00FC = 0;
		goto L0144;
	L00FF: //
		String::__ClassInit();
		temp_0108 = new StringBuilder(String::valueOf(template_0090.getValue()));
		template_0090 = temp_0108->append((((i_00FC) > 0) ? (((Pointer<String>) new String(", "))) : (((Pointer<String>) new String("")))))->toString();
		String::__ClassInit();
		temp_012A = new StringBuilder(String::valueOf(template_0090.getValue()));
		template_0090 = temp_012A->append(createString("class "))->append((char) ((65) + (i_00FC)))->toString();
		i_00FC += 1;
	L0144: //
		if ((i_00FC) < (templateCount_00EA))
			goto L00FF;
		String::__ClassInit();
		temp_0154 = new StringBuilder(String::valueOf(template_0090.getValue()));
		template_0090 = temp_0154->append(createString("> "))->toString();
	L0162: //
		reference_008B = reference_008B->substring((reference_008B->lastIndexOf(58)) + (1));
		String::__ClassInit();
		temp_017C = new StringBuilder(String::valueOf(template_0090.getValue()));
		header->iprintln(temp_017C->append(createString("class "))->append(reference_008B)->append(createString(";"))->toString());
	L0196: //
		if (local_007A->hasNext())
			goto L007F;
		header->indent(-1);
		header->println(createString("}"));
		header->println();
	L01B0: //
		if (local_0040->hasNext())
			goto L0045;
		local_0040 = this->namespaces->iterator();
		goto L01EE;
	L01C6: //
		temp_01CD = (String*)((local_0040->next()).getValue());
		temp_01CD->checkCast(String::__thisClassStatic);
		packageName_01D2 = temp_01CD;
		temp_01DA = new StringBuilder(createString("using namespace "));
		header->println(temp_01DA->append(packageName_01D2)->append(createString(";"))->toString());
	L01EE: //
		if (local_0040->hasNext())
			goto L01C6;
		header->println();
		return;
	}

	void CppClass::generateHeaderJavaClass(Pointer<IndentedOutputStream> header)
	{
		UsageCounterMaintainer maintainer(this, true);

		header->iprintln(createString("public:"));
		header->indent(1);
		header->iprintln(createString("static Pointer<Class> __thisClassStatic;"));
		header->println();
		header->indent(-1);
		return;
	}

	void CppClass::generateHeaderMethods(Pointer<IndentedOutputStream> header)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<CppMethod> method_0019;
		Pointer<String> methodType_001F;
		Pointer<String> newType_0027;
		Pointer<String> methodName_002D;
		Pointer<JavaArray<CppMethod>> local_000A;
		int local_000D = 0;
		int local_0010 = 0;
		this->generateHeaderClassInitIfNeeded(header);
		local_000A = (JavaArray<CppMethod>*)(this->methods.getValue());
		local_000D = this->methods->length;
		local_0010 = 0;
		goto L0073;
	L0014: //
		method_0019 = local_000A->get(local_0010);
		methodType_001F = method_0019->getType();
		newType_0027 = this->simplifyType(methodType_001F);
		methodName_002D = method_0019->getName();
		if (!(methodName_002D->equals(createString("<init>"))))
			goto L0050;
		methodName_002D = this->className;
		newType_0027 = newType_0027->substring(0, (newType_0027->length()) - (4));
		goto L0060;
	L0050: //
		if (!(methodName_002D->equals(createString("<clinit>"))))
			goto L0060;
		methodName_002D = createString("__ClassInit");
	L0060: //
		if (!(method_0019->isPresentInSource()))
			goto L0070;
		method_0019->generateHeader(header, methodName_002D, newType_0027);
	L0070: //
		local_0010 += 1;
	L0073: //
		if ((local_0010) < (local_000D))
			goto L0014;
		return;
	}

	void CppClass::generateSourceClassInitIfNeeded(Pointer<IndentedOutputStream> source)
	{
		UsageCounterMaintainer maintainer(this, true);

		bool classInitFound_0002 = false;
		Pointer<CppMethod> method_0018;
		Pointer<String> methodName_001E;
		Pointer<JavaArray<CppMethod>> local_0007;
		int local_000A = 0;
		int local_000D = 0;
		Pointer<StringBuilder> temp_0044;
		Pointer<StringBuilder> temp_0077;
		classInitFound_0002 = 0;
		local_0007 = (JavaArray<CppMethod>*)(this->methods.getValue());
		local_000A = this->methods->length;
		local_000D = 0;
		goto L0031;
	L0012: //
		method_0018 = local_0007->get(local_000D);
		methodName_001E = method_0018->getName();
		if (!(methodName_001E->equals(createString("<clinit>"))))
			goto L002E;
		classInitFound_0002 = 1;
		goto L0038;
	L002E: //
		local_000D += 1;
	L0031: //
		if ((local_000D) < (local_000A))
			goto L0012;
	L0038: //
		if (classInitFound_0002)
			goto L0096;
		temp_0044 = new StringBuilder(createString("void "));
		source->iprintln(temp_0044->append(this->className)->append(createString("::__ClassInit()"))->toString());
		source->iprintln(createString("{"));
		source->indent(1);
		CppMethod::__ClassInit();
		CppMethod::generateClassInitDefaultCode(source, this);
		String::__ClassInit();
		temp_0077 = new StringBuilder(String::valueOf(this->parentClassName.getValue()));
		source->iprintln(temp_0077->append(createString("::__ClassInit();"))->toString());
		source->indent(-1);
		source->iprintln(createString("}"));
		source->println();
	L0096: //
		return;
	}

	void CppClass::generateSourceIncludesAndNamespaces(Pointer<IndentedOutputStream> source)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> clazz_002E;
		int pos_0036 = 0;
		Pointer<String> headerName_0057;
		Pointer<String> lastNamespace_009C;
		Pointer<String> clazz_00B6;
		Pointer<String> namespace_00CA;
		Pointer<Iterator> local_0020;
		Pointer<String> temp_002A;
		Pointer<StringBuilder> temp_006A;
		Pointer<Iterator> local_00A6;
		Pointer<String> temp_00B2;
		Pointer<StringBuilder> temp_00E2;
		this->referencedClasses = this->classFile->getReferencedClasses().getValue();
		this->classFile->addReferencedClasses(this->referencedClasses);
		local_0020 = this->referencedClasses->getClasses()->iterator();
		goto L007E;
	L0024: //
		temp_002A = (String*)((local_0020->next()).getValue());
		temp_002A->checkCast(String::__thisClassStatic);
		clazz_002E = temp_002A;
		pos_0036 = clazz_002E->indexOf(60);
		if ((pos_0036) < 0)
			goto L0043;
		clazz_002E = clazz_002E->substring(0, pos_0036);
	L0043: //
		Statics::__ClassInit();
		headerName_0057 = Statics::dotToNamespace(clazz_002E->replace('/', '.'))->replace(':', '_');
		if (headerName_0057->contains(createString("$")))
			goto L007E;
		temp_006A = new StringBuilder(createString("#include \""));
		source->println(temp_006A->append(headerName_0057)->append(createString(".h\""))->toString());
	L007E: //
		if (local_0020->hasNext())
			goto L0024;
		if ((this->referencedClasses->getClasses()->size()) <= 0)
			goto L0098;
		source->println();
	L0098: //
		lastNamespace_009C = createString("");
		local_00A6 = this->referencedClasses->getClasses()->iterator();
		goto L00F9;
	L00AB: //
		temp_00B2 = (String*)((local_00A6->next()).getValue());
		temp_00B2->checkCast(String::__thisClassStatic);
		clazz_00B6 = temp_00B2;
		namespace_00CA = clazz_00B6->substring(0, clazz_00B6->lastIndexOf(47))->replace('/', '.');
		Statics::__ClassInit();
		namespace_00CA = Statics::dotToNamespace(namespace_00CA);
		if (namespace_00CA->equals(lastNamespace_009C.getValue()))
			goto L00F9;
		temp_00E2 = new StringBuilder(createString("using namespace "));
		source->println(temp_00E2->append(namespace_00CA)->append(createString(";"))->toString());
		lastNamespace_009C = namespace_00CA;
	L00F9: //
		if (local_00A6->hasNext())
			goto L00AB;
		if ((this->referencedClasses->getClasses()->size()) <= 0)
			goto L0114;
		source->println();
	L0114: //
		return;
	}

	void CppClass::generateSourceJavaClass(Pointer<IndentedOutputStream> source)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<StringBuilder> temp_0008;
		temp_0008 = new StringBuilder(createString("Pointer<Class> "));
		source->iprintln(temp_0008->append(this->className)->append(createString("::"))->append(createString("__thisClassStatic;"))->toString());
		source->println();
		return;
	}

	void CppClass::generateSourceMethods(Pointer<IndentedOutputStream> source)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<CppMethod> method_0019;
		Pointer<String> methodType_001F;
		Pointer<String> methodName_002D;
		Pointer<JavaArray<CppMethod>> local_000A;
		int local_000D = 0;
		int local_0010 = 0;
		Pointer<StringBuilder> temp_0076;
		this->generateSourceClassInitIfNeeded(source);
		local_000A = (JavaArray<CppMethod>*)(this->methods.getValue());
		local_000D = this->methods->length;
		local_0010 = 0;
		goto L0092;
	L0014: //
		method_0019 = local_000A->get(local_0010);
		methodType_001F = method_0019->getType();
		methodType_001F = this->simplifyType(methodType_001F);
		methodName_002D = method_0019->getName();
		if (!(methodName_002D->equals(createString("<init>"))))
			goto L0052;
		methodName_002D = this->className;
		methodType_001F = methodType_001F->substring(0, (methodType_001F->indexOf(41)) + (1));
		goto L0062;
	L0052: //
		if (!(methodName_002D->equals(createString("<clinit>"))))
			goto L0062;
		methodName_002D = createString("__ClassInit");
	L0062: //
		if (!(method_0019->isPresentInSource()))
			goto L008F;
		String::__ClassInit();
		temp_0076 = new StringBuilder(String::valueOf(this->className.getValue()));
		method_0019->generateSource(source, temp_0076->append(createString("::"))->append(methodName_002D)->toString(), methodType_001F, this->fields);
	L008F: //
		local_0010 += 1;
	L0092: //
		if ((local_0010) < (local_000D))
			goto L0014;
		return;
	}

	void CppClass::generateSourceStaticFields(Pointer<IndentedOutputStream> source)
	{
		UsageCounterMaintainer maintainer(this, true);

		bool newLine_0002 = false;
		Pointer<CppField> field_0018;
		Pointer<String> fieldType_001E;
		Pointer<String> newType_0026;
		Pointer<JavaArray<CppField>> local_0007;
		int local_000A = 0;
		int local_000D = 0;
		newLine_0002 = 0;
		local_0007 = (JavaArray<CppField>*)(this->fields.getValue());
		local_000A = this->fields->length;
		local_000D = 0;
		goto L003E;
	L0012: //
		field_0018 = local_0007->get(local_000D);
		fieldType_001E = field_0018->getType();
		newType_0026 = this->simplifyType(fieldType_001E);
		if (!(field_0018->isPresentInSource()))
			goto L003B;
		newLine_0002 = (newLine_0002) | (field_0018->generateSource(source, this->className, newType_0026));
	L003B: //
		local_000D += 1;
	L003E: //
		if ((local_000D) < (local_000A))
			goto L0012;
		if (!(newLine_0002))
			goto L004D;
		source->println();
	L004D: //
		return;
	}

	Pointer<String> CppClass::simplifyTypeComponent(Pointer<String> fullyQualifiedType)
	{
		UsageCounterMaintainer maintainer(this, true);

		int pos_0007 = 0;
		Pointer<String> simpleType_0016;
		pos_0007 = fullyQualifiedType->lastIndexOf(58);
		if ((pos_0007) != (-1))
			goto L000E;
		return fullyQualifiedType;
	L000E: //
		simpleType_0016 = fullyQualifiedType->substring((pos_0007) + (1));
		if (this->multipleClasses->contains(simpleType_0016.getValue()))
			goto L0023;
		return simpleType_0016;
	L0023: //
		return fullyQualifiedType;
	}

}
