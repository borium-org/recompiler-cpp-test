#include "stdafx.h"
#include "org__borium__javarecompiler__Recomp.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__File.h"
#include "java__io__IOException.h"
#include "java__io__PrintStream.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__lang__System.h"
#include "java__lang__Throwable.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"
#include "java__util__Iterator.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler
{

	Pointer<Class> Recomp::__thisClassStatic;

	bool Recomp::instructionComments;
	bool Recomp::stackComments;
	bool Recomp::dumpInstructions;
	bool Recomp::dumpStatements;
	Pointer<HashMap<String, String>> Recomp::simpleClassNames;

	void Recomp::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::Recomp",
			java::lang::Object::__thisClassStatic);

		Pointer<HashMap<Object, Object>> temp_0014;
		Object::__ClassInit();
		Recomp::instructionComments = false;
		Recomp::stackComments = false;
		Recomp::dumpInstructions = false;
		Recomp::dumpStatements = false;
		temp_0014 = new HashMap<Object, Object>();
		Recomp::simpleClassNames = (HashMap<String, String>*)temp_0014.getValue();
		return;
	}

	Recomp::Recomp() :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<ArrayList<Object>> temp_0009;
		temp_0009 = new ArrayList<Object>();
		this->classPaths = (ArrayList<String>*)temp_0009.getValue();
		return;
	}

	void Recomp::main(Pointer<JavaArray<String>> args)
	{
		__ClassInit();

		Pointer<Recomp> recompiler_0049;
		int argc_004B = 0;
		Pointer<JavaArray<String>> temp_0007;
		Pointer<Recomp> temp_0045;
		Pointer<String> local_0052;
		Pointer<StringBuilder> temp_010A;
		Pointer<RuntimeException> temp_0116;
		if ((args->length) != 0)
			goto L0041;
		temp_0007 = new JavaArray<String>(10);
		temp_0007->assign(0, createString("-classpath"));
		temp_0007->assign(1, createString("../recompiler-java-test/bin"));
		temp_0007->assign(2, createString("-outputpath"));
		temp_0007->assign(3, createString("../recompiler-cpp-test"));
		temp_0007->assign(4, createString("-mainclass"));
		temp_0007->assign(5, createString("org.borium.javarecompiler.Recomp"));
		temp_0007->assign(6, createString("-vs"));
		temp_0007->assign(7, createString("2005"));
		temp_0007->assign(8, createString("-comments"));
		temp_0007->assign(9, createString("all"));
		args = (JavaArray<String>*)(temp_0007.getValue());
	L0041: //
		temp_0045 = new Recomp();
		recompiler_0049 = temp_0045;
		argc_004B = 0;
		goto L011D;
	L004E: //
		local_0052 = args->get(argc_004B);
		switch (args->get(argc_004B)->hashCode())
		{
		case (int)0xE0528093:
			goto L0088;
		case (int)0xE22731D2:
			goto L0094;
		case (int)0xEC1F6121:
			goto L00A0;
		case (int)0xF0617410:
			goto L00AC;
		case (int)0x0000B7AA:
			goto L00B8;
		default:
			goto L0100;
		}
	L0088: //
		if (local_0052->equals(createString("-outputpath")))
			goto L00D0;
		goto L0100;
	L0094: //
		if (local_0052->equals(createString("-mainclass")))
			goto L00DC;
		goto L0100;
	L00A0: //
		if (local_0052->equals(createString("-comments")))
			goto L00F4;
		goto L0100;
	L00AC: //
		if (local_0052->equals(createString("-classpath")))
			goto L00C4;
		goto L0100;
	L00B8: //
		if (local_0052->equals(createString("-vs")))
			goto L00E8;
		goto L0100;
	L00C4: //
		recompiler_0049->addClassPath(args->get((argc_004B) + (1)));
		goto L011A;
	L00D0: //
		recompiler_0049->setOutputPath(args->get((argc_004B) + (1)));
		goto L011A;
	L00DC: //
		recompiler_0049->setMainClass(args->get((argc_004B) + (1)));
		goto L011A;
	L00E8: //
		recompiler_0049->setVisualStudio(args->get((argc_004B) + (1)));
		goto L011A;
	L00F4: //
		recompiler_0049->setCommentLevel(args->get((argc_004B) + (1)));
		goto L011A;
	L0100: //
		temp_010A = new StringBuilder(createString("Unsupported argument "));
		temp_0116 = new RuntimeException(temp_010A->append(args->get(argc_004B))->toString());
		throw temp_0116;
	L011A: //
		argc_004B += 2;
	L011D: //
		if ((argc_004B) < (args->length))
			goto L004E;
		recompiler_0049->run();
		System::__ClassInit();
		System::out->println(createString("Done."));
		return;
	}

	void Recomp::addClassPath(Pointer<String> classPath)
	{
		this->classPaths->add(classPath.getValue());
		return;
	}

	void Recomp::run()
	{
		Pointer<ClassFile> classFile_0022;
		Pointer<StringBuilder> temp_0009;
		System::__ClassInit();
		temp_0009 = new StringBuilder(createString("Processing "));
		System::out->println(temp_0009->append(this->mainClass)->toString());
		classFile_0022 = this->processClassFile(this->mainClass);
		return;
	}

	void Recomp::setMainClass(Pointer<String> mainClass)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		if ((this->mainClass).getValue() == nullptr)
			goto L0030;
		temp_0011 = new StringBuilder(createString("Main class already set to \'"));
		temp_002C = new RuntimeException(temp_0011->append(this->mainClass)->append(createString("\', not setting it to \'"))->append(mainClass)->append(createString("\'"))->toString());
		throw temp_002C;
	L0030: //
		this->mainClass = mainClass.getValue();
		return;
	}

	void Recomp::setOutputPath(Pointer<String> outputPath)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		if ((this->outputPath).getValue() == nullptr)
			goto L0030;
		temp_0011 = new StringBuilder(createString("Output path already set to \'"));
		temp_002C = new RuntimeException(temp_0011->append(this->outputPath)->append(createString("\', not setting it to \'"))->append(outputPath)->append(createString("\'"))->toString());
		throw temp_002C;
	L0030: //
		this->outputPath = outputPath.getValue();
		return;
	}

	void Recomp::setVisualStudio(Pointer<String> visualStudio)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		if ((this->visualStudio).getValue() == nullptr)
			goto L0030;
		temp_0011 = new StringBuilder(createString("Visual Studio already set to \'"));
		temp_002C = new RuntimeException(temp_0011->append(this->visualStudio)->append(createString("\', not setting it to \'"))->append(visualStudio)->append(createString("\'"))->toString());
		throw temp_002C;
	L0030: //
		this->visualStudio = visualStudio.getValue();
		return;
	}

	Pointer<ClassFile> Recomp::processClassFile(Pointer<String> classFileName)
	{
		Pointer<String> classPathFileName_0026;
		Pointer<String> fileName_0028;
		Pointer<String> classPath_0040;
		Pointer<File> file_0061;
		Pointer<ClassFile> classFile_00D7;
		Pointer<StringBuilder> temp_001A;
		Pointer<Iterator> local_002F;
		Pointer<String> temp_003B;
		Pointer<StringBuilder> temp_004D;
		Pointer<File> temp_005C;
		Pointer<StringBuilder> temp_007A;
		Pointer<StringBuilder> temp_00A4;
		Pointer<StringBuilder> temp_00BB;
		Pointer<RuntimeException> temp_00CA;
		Pointer<ClassFile> temp_00D2;
		if (!(classFileName->startsWith(createString("java."))))
			goto L000B;
		// ARETURN: Type mismatch
		return (ClassFile*)nullptr;
	L000B: //
		String::__ClassInit();
		temp_001A = new StringBuilder(String::valueOf(classFileName->replace('.', '/').getValue()));
		classPathFileName_0026 = temp_001A->append(createString(".class"))->toString();
		fileName_0028 = nullptr;
		local_002F = this->classPaths->iterator();
		goto L008D;
	L0034: //
		temp_003B = (String*)((local_002F->next()).getValue());
		temp_003B->checkCast(String::__thisClassStatic);
		classPath_0040 = temp_003B;
		String::__ClassInit();
		temp_004D = new StringBuilder(String::valueOf(classPath_0040.getValue()));
		temp_005C = new File(temp_004D->append(createString("/"))->append(classPathFileName_0026)->toString());
		file_0061 = temp_005C;
		if (!(file_0061->exists()))
			goto L008D;
		if (!(file_0061->isFile()))
			goto L008D;
		String::__ClassInit();
		temp_007A = new StringBuilder(String::valueOf(classPath_0040.getValue()));
		fileName_0028 = temp_007A->append(createString("/"))->append(classPathFileName_0026)->toString();
		goto L0097;
	L008D: //
		if (local_002F->hasNext())
			goto L0034;
	L0097: //
		if ((fileName_0028).getValue() != nullptr)
			goto L00CE;
		System::__ClassInit();
		temp_00A4 = new StringBuilder(createString("Error: "));
		System::out->println(temp_00A4->append(classFileName)->toString());
		temp_00BB = new StringBuilder(createString("Class "));
		temp_00CA = new RuntimeException(temp_00BB->append(classFileName)->append(createString(" not found"))->toString());
		throw temp_00CA;
	L00CE: //
		temp_00D2 = new ClassFile();
		classFile_00D7 = temp_00D2;
	L00D7: //
		try
		{
			classFile_00D7->read(fileName_0028);
		L00DD: //
			goto L00E7;
		}
		catch (ClassFormatError* e_00E2)
		{
			e_00E2->printStackTrace();
		}
		catch (IOException* e_00E2)
		{
			e_00E2->printStackTrace();
		}
	L00E7: //
		System::__ClassInit();
		System::out->println(createString("Read complete"));
		return classFile_00D7;
	}

	void Recomp::setCommentLevel(Pointer<String> commentLevel)
	{
		Pointer<String> local_0002;
		Pointer<StringBuilder> temp_0058;
		Pointer<RuntimeException> temp_0062;
		local_0002 = commentLevel;
		switch (commentLevel->hashCode())
		{
		case (int)0x000179A1:
			goto L0020;
		case (int)0x0033AF38:
			goto L002C;
		default:
			goto L004E;
		}
	L0020: //
		if (local_0002->equals(createString("all")))
			goto L0038;
		goto L004E;
	L002C: //
		if (local_0002->equals(createString("none")))
			goto L0043;
		goto L004E;
	L0038: //
		Recomp::__ClassInit();
		Recomp::instructionComments = true;
		Recomp::__ClassInit();
		Recomp::stackComments = true;
		goto L0066;
	L0043: //
		Recomp::__ClassInit();
		Recomp::instructionComments = false;
		Recomp::__ClassInit();
		Recomp::stackComments = false;
		goto L0066;
	L004E: //
		temp_0058 = new StringBuilder(createString("Unsupported comment level "));
		temp_0062 = new RuntimeException(temp_0058->append(commentLevel)->toString());
		throw temp_0062;
	L0066: //
		return;
	}

}
