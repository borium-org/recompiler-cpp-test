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
#include "java__util__TreeSet.h"
#include "org__borium__javarecompiler__Statics.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler
{

	Pointer<Class> Recomp::__thisClassStatic;

	bool Recomp::instructionComments;
	bool Recomp::stackComments;
	bool Recomp::dumpInstructions;
	bool Recomp::dumpStatements;
	Pointer<HashMap<String, ClassFile>> Recomp::processedClasses;
	Pointer<ArrayList<String>> Recomp::processedClassNames;
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
		Pointer<ArrayList<Object>> temp_001E;
		Pointer<HashMap<Object, Object>> temp_0028;
		Object::__ClassInit();
		Recomp::instructionComments = false;
		Recomp::stackComments = false;
		Recomp::dumpInstructions = false;
		Recomp::dumpStatements = false;
		temp_0014 = new HashMap<Object, Object>();
		Recomp::processedClasses = (HashMap<String, ClassFile>*)temp_0014.getValue();
		temp_001E = new ArrayList<Object>();
		Recomp::processedClassNames = (ArrayList<String>*)temp_001E.getValue();
		temp_0028 = new HashMap<Object, Object>();
		Recomp::simpleClassNames = (HashMap<String, String>*)temp_0028.getValue();
		return;
	}

	Recomp::Recomp() :
		Object() //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		UsageCounterMaintainer maintainer(this, false);

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
		UsageCounterMaintainer maintainer(this, true);

		this->classPaths->add(classPath.getValue());
		return;
	}

	void Recomp::run()
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ClassFile> classFile_0022;
		Pointer<ArrayList<String>> newClassNames_002F;
		Pointer<StringBuilder> temp_0009;
		Pointer<ArrayList<Object>> temp_002B;
		System::__ClassInit();
		temp_0009 = new StringBuilder(createString("Processing "));
		System::out->println(temp_0009->append(this->mainClass)->toString());
		classFile_0022 = this->processClassFile(this->mainClass);
		this->addNewClass(classFile_0022);
		temp_002B = new ArrayList<Object>();
		newClassNames_002F = (ArrayList<String>*)(temp_002B.getValue());
		this->addReferencedClasses(newClassNames_002F.getValue(), classFile_0022);
		return;
	}

	void Recomp::setMainClass(Pointer<String> mainClass)
	{
		UsageCounterMaintainer maintainer(this, true);

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
		UsageCounterMaintainer maintainer(this, true);

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
		UsageCounterMaintainer maintainer(this, true);

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

	void Recomp::addNewClass(Pointer<ClassFile> classFile)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> className_0005;
		Pointer<String> simpleClassName_0023;
		Pointer<StringBuilder> temp_0038;
		className_0005 = classFile->getClassName();
		Recomp::__ClassInit();
		Recomp::processedClasses->put(className_0005.getValue(), classFile.getValue());
		Recomp::__ClassInit();
		Recomp::processedClassNames->add(className_0005.getValue());
		simpleClassName_0023 = className_0005->substring((className_0005->lastIndexOf(46)) + (1));
		Recomp::__ClassInit();
		temp_0038 = new StringBuilder(createString("Duplicate simple class name "));
		Statics::__ClassInit();
		Statics::Assert((((Recomp::simpleClassNames->containsKey(simpleClassName_0023.getValue())) ? (0) : (1))) != 0, temp_0038->append(simpleClassName_0023)->toString());
		Recomp::__ClassInit();
		Recomp::simpleClassNames->put(simpleClassName_0023.getValue(), className_0005.getValue());
		return;
	}

	void Recomp::addReferencedClasses(Pointer<ArrayList<String>> newClassNames, Pointer<ClassFile> classFile)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<ReferencedClasses> allReferences_0005;
		Pointer<String> reference_001D;
		Pointer<String> ref_0035;
		Pointer<Iterator> local_000C;
		Pointer<String> temp_0018;
		allReferences_0005 = classFile->getReferencedClasses();
		local_000C = allReferences_0005->getClasses()->iterator();
		goto L0050;
	L0011: //
		temp_0018 = (String*)((local_000C->next()).getValue());
		temp_0018->checkCast(String::__thisClassStatic);
		reference_001D = temp_0018;
		if (!(reference_001D->startsWith(createString("java/"))))
			goto L002A;
		goto L0050;
	L002A: //
		ref_0035 = reference_001D->replace('/', '.');
		Recomp::__ClassInit();
		if (Recomp::processedClasses->containsKey(ref_0035.getValue()))
			goto L0050;
		if (newClassNames->contains(ref_0035.getValue()))
			goto L0050;
		newClassNames->add(ref_0035.getValue());
	L0050: //
		if (local_000C->hasNext())
			goto L0011;
		return;
	}

	Pointer<ClassFile> Recomp::processClassFile(Pointer<String> classFileName)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> classPathFileName_0028;
		Pointer<String> fileName_002A;
		Pointer<String> classPath_0042;
		Pointer<File> file_0064;
		Pointer<ClassFile> classFile_00DE;
		Pointer<IndentedOutputStream> stream_0115;
		Pointer<StringBuilder> temp_001B;
		Pointer<Iterator> local_0031;
		Pointer<String> temp_003D;
		Pointer<StringBuilder> temp_004F;
		Pointer<File> temp_005F;
		Pointer<StringBuilder> temp_007D;
		Pointer<StringBuilder> temp_00A9;
		Pointer<StringBuilder> temp_00C1;
		Pointer<RuntimeException> temp_00D1;
		Pointer<ClassFile> temp_00D9;
		Pointer<StringBuilder> temp_0104;
		Pointer<IndentedOutputStream> temp_0110;
		if (!(classFileName->startsWith(createString("java."))))
			goto L000C;
		// ARETURN: Type mismatch
		return (ClassFile*)nullptr;
	L000C: //
		String::__ClassInit();
		temp_001B = new StringBuilder(String::valueOf(classFileName->replace('.', '/').getValue()));
		classPathFileName_0028 = temp_001B->append(createString(".class"))->toString();
		fileName_002A = nullptr;
		local_0031 = this->classPaths->iterator();
		goto L0091;
	L0036: //
		temp_003D = (String*)((local_0031->next()).getValue());
		temp_003D->checkCast(String::__thisClassStatic);
		classPath_0042 = temp_003D;
		String::__ClassInit();
		temp_004F = new StringBuilder(String::valueOf(classPath_0042.getValue()));
		temp_005F = new File(temp_004F->append(createString("/"))->append(classPathFileName_0028)->toString());
		file_0064 = temp_005F;
		if (!(file_0064->exists()))
			goto L0091;
		if (!(file_0064->isFile()))
			goto L0091;
		String::__ClassInit();
		temp_007D = new StringBuilder(String::valueOf(classPath_0042.getValue()));
		fileName_002A = temp_007D->append(createString("/"))->append(classPathFileName_0028)->toString();
		goto L009B;
	L0091: //
		if (local_0031->hasNext())
			goto L0036;
	L009B: //
		if ((fileName_002A).getValue() != nullptr)
			goto L00D5;
		System::__ClassInit();
		temp_00A9 = new StringBuilder(createString("Error: "));
		System::out->println(temp_00A9->append(classFileName)->toString());
		temp_00C1 = new StringBuilder(createString("Class "));
		temp_00D1 = new RuntimeException(temp_00C1->append(classFileName)->append(createString(" not found"))->toString());
		throw temp_00D1;
	L00D5: //
		temp_00D9 = new ClassFile();
		classFile_00DE = temp_00D9;
	L00DE: //
		try
		{
			classFile_00DE->read(fileName_002A);
		L00E4: //
			goto L00EE;
		}
		catch (ClassFormatError* e_00E9)
		{
			e_00E9->printStackTrace();
		}
		catch (IOException* e_00E9)
		{
			e_00E9->printStackTrace();
		}
	L00EE: //
		try
		{
			Pointer<IndentedOutputStream> stream_0115;
			String::__ClassInit();
			temp_0104 = new StringBuilder(String::valueOf(fileName_002A->substring(0, (fileName_002A->length()) - (5)).getValue()));
			temp_0110 = new IndentedOutputStream(temp_0104->append(createString("txt"))->toString());
			stream_0115 = temp_0110;
			classFile_00DE->dump(stream_0115);
			stream_0115->close();
		L0121: //
			goto L012B;
		}
		catch (IOException* e_0126)
		{
			e_0126->printStackTrace();
		}
	L012B: //
		System::__ClassInit();
		System::out->println(createString("Read complete"));
		return classFile_00DE;
	}

	void Recomp::setCommentLevel(Pointer<String> commentLevel)
	{
		UsageCounterMaintainer maintainer(this, true);

		Pointer<String> local_0002;
		Pointer<StringBuilder> temp_005A;
		Pointer<RuntimeException> temp_0064;
		local_0002 = commentLevel;
		switch (commentLevel->hashCode())
		{
		case (int)0x000179A1:
			goto L0020;
		case (int)0x0033AF38:
			goto L002C;
		default:
			goto L004F;
		}
	L0020: //
		if (local_0002->equals(createString("all")))
			goto L0039;
		goto L004F;
	L002C: //
		if (local_0002->equals(createString("none")))
			goto L0044;
		goto L004F;
	L0039: //
		Recomp::__ClassInit();
		Recomp::instructionComments = true;
		Recomp::__ClassInit();
		Recomp::stackComments = true;
		goto L0068;
	L0044: //
		Recomp::__ClassInit();
		Recomp::instructionComments = false;
		Recomp::__ClassInit();
		Recomp::stackComments = false;
		goto L0068;
	L004F: //
		temp_005A = new StringBuilder(createString("Unsupported comment level "));
		temp_0064 = new RuntimeException(temp_005A->append(commentLevel)->toString());
		throw temp_0064;
	L0068: //
		return;
	}

}
