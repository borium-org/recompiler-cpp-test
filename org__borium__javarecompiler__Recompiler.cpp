#include "stdafx.h"
#include "org__borium__javarecompiler__Recompiler.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__PrintStream.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__lang__System.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;

namespace org::borium::javarecompiler
{

	Pointer<Class> Recompiler::__thisClassStatic;

	bool Recompiler::instructionComments;
	bool Recompiler::stackComments;
	bool Recompiler::dumpInstructions;
	bool Recompiler::dumpStatements;
	Pointer<HashMap<String, String>> Recompiler::simpleClassNames;

	void Recompiler::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::Recompiler",
			java::lang::Object::__thisClassStatic);

		Pointer<HashMap<Object, Object>> temp_0014;
		Object::__ClassInit();
		//		iconst 0
		//				stack[0]: int	0
		//		putstatic instructionComments Z
		Recompiler::instructionComments = false;
		//				stack: empty
		//		iconst 0
		//				stack[0]: int	0
		//		putstatic stackComments Z
		Recompiler::stackComments = false;
		//				stack: empty
		//		iconst 0
		//				stack[0]: int	0
		//		putstatic dumpInstructions Z
		Recompiler::dumpInstructions = false;
		//				stack: empty
		//		iconst 0
		//				stack[0]: int	0
		//		putstatic dumpStatements Z
		Recompiler::dumpStatements = false;
		//				stack: empty
		//		new java.util.HashMap
		//				stack[0]: HashMap	new
		//		dup
		//				stack[0]: HashMap	new
		//				stack[1]: HashMap	new
		//		invokespecial java.util.HashMap.<init>
		temp_0014 = new HashMap<Object, Object>();
		//				stack[0]: HashMap<Object, Object>	temp_0014
		//		putstatic simpleClassNames Ljava/util/HashMap;
		Recompiler::simpleClassNames = (HashMap<String, String>*)temp_0014.getValue();
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	Recompiler::Recompiler() :
		//		aload 0
		//				stack[0]: Recompiler	this
		//		invokespecial java.lang.Object.<init>
		Object() //
		//				stack: empty
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<ArrayList<Object>> temp_0009;
		//		aload 0
		//				stack[0]: Recompiler	this
		//		new java.util.ArrayList
		//				stack[0]: Recompiler	this
		//				stack[1]: ArrayList	new
		//		dup
		//				stack[0]: Recompiler	this
		//				stack[1]: ArrayList	new
		//				stack[2]: ArrayList	new
		//		invokespecial java.util.ArrayList.<init>
		temp_0009 = new ArrayList<Object>();
		//				stack[0]: Recompiler	this
		//				stack[1]: ArrayList<Object>	temp_0009
		//		putfield classPaths Ljava/util/ArrayList;
		this->classPaths = (ArrayList<String>*)temp_0009.getValue();
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::main(Pointer<JavaArray<String>> args)
	{
		__ClassInit();

		Pointer<Recompiler> recompiler_0049;
		int argc_004B = 0;
		Pointer<JavaArray<String>> temp_0007;
		Pointer<Recompiler> temp_0045;
		Pointer<String> local_0052;
		Pointer<StringBuilder> temp_010A;
		Pointer<RuntimeException> temp_0116;
		//		aload 0
		//				stack[0]: JavaArray<String>	args
		//		arraylength
		//				stack[0]: int	args->length
		//		ifne L0041
		if ((args->length) != 0)
			goto L0041;
		//				stack: empty
		//		bipush 10
		//				stack[0]: int	10
		//		anewarray java.lang.String
		temp_0007 = new JavaArray<String>(10);
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		iconst 0
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	0
		//		ldc "-classpath"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	0
		//				stack[3]: String	"-classpath"
		//		aastore
		temp_0007->assign(0, "-classpath");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		iconst 1
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	1
		//		ldc "../recompiler-java-test/bin"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	1
		//				stack[3]: String	"../recompiler-java-test/bin"
		//		aastore
		temp_0007->assign(1, "../recompiler-java-test/bin");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		iconst 2
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	2
		//		ldc "-outputpath"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	2
		//				stack[3]: String	"-outputpath"
		//		aastore
		temp_0007->assign(2, "-outputpath");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		iconst 3
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	3
		//		ldc "../recompiler-cpp-test"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	3
		//				stack[3]: String	"../recompiler-cpp-test"
		//		aastore
		temp_0007->assign(3, "../recompiler-cpp-test");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		iconst 4
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	4
		//		ldc "-mainclass"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	4
		//				stack[3]: String	"-mainclass"
		//		aastore
		temp_0007->assign(4, "-mainclass");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		iconst 5
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	5
		//		ldc "org.borium.javarecompiler.Recompiler"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	5
		//				stack[3]: String	"org.borium.javarecompiler.Recompiler"
		//		aastore
		temp_0007->assign(5, "org.borium.javarecompiler.Recompiler");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		bipush 6
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	6
		//		ldc "-vs"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	6
		//				stack[3]: String	"-vs"
		//		aastore
		temp_0007->assign(6, "-vs");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		bipush 7
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	7
		//		ldc "2005"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	7
		//				stack[3]: String	"2005"
		//		aastore
		temp_0007->assign(7, "2005");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		bipush 8
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	8
		//		ldc "-comments"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	8
		//				stack[3]: String	"-comments"
		//		aastore
		temp_0007->assign(8, "-comments");
		//				stack[0]: JavaArray<String>	temp_0007
		//		dup
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//		bipush 9
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	9
		//		ldc "all"
		//				stack[0]: JavaArray<String>	temp_0007
		//				stack[1]: JavaArray<String>	temp_0007
		//				stack[2]: int	9
		//				stack[3]: String	"all"
		//		aastore
		temp_0007->assign(9, "all");
		//				stack[0]: JavaArray<String>	temp_0007
		//		astore 0
		args = (JavaArray<String>*)(temp_0007.getValue());
		//				stack: empty
	L0041: //
		//		new org.borium.javarecompiler.Recompiler
		//				stack[0]: Recompiler	new
		//		dup
		//				stack[0]: Recompiler	new
		//				stack[1]: Recompiler	new
		//		invokespecial org.borium.javarecompiler.Recompiler.<init>
		temp_0045 = new Recompiler();
		//				stack[0]: Recompiler	temp_0045
		//		astore 1
		recompiler_0049 = temp_0045;
		//				stack: empty
		//		iconst 0
		//				stack[0]: int	0
		//		istore 2
		argc_004B = 0;
		//				stack: empty
		//		goto L011D
		goto L011D;
		//				stack: empty
	L004E: //
		//		aload 0
		//				stack[0]: JavaArray<String>	args
		//		iload 2
		//				stack[0]: JavaArray<String>	args
		//				stack[1]: int	argc_004B
		//		aaload
		//				stack[0]: String	args->get(argc_004B)
		//		dup
		//				stack[0]: String	args->get(argc_004B)
		//				stack[1]: String	args->get(argc_004B)
		//		astore 3
		local_0052 = args->get(argc_004B);
		//				stack[0]: String	args->get(argc_004B)
		//		invokevirtual java.lang.String.hashCode
		//				stack[0]: int	args->get(argc_004B)->hashCode()
		//		lookupswitch 5 cases
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
		//				stack: empty
	L0088: //
		//		aload 3
		//				stack[0]: String	local_0052
		//		ldc "-outputpath"
		//				stack[0]: String	local_0052
		//				stack[1]: String	"-outputpath"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool	local_0052->equals(createString("-outputpath"))
		//		ifne L00D0
		if (local_0052->equals(createString("-outputpath")))
			goto L00D0;
		//				stack: empty
		//		goto L0100
		goto L0100;
		//				stack: empty
	L0094: //
		//		aload 3
		//				stack[0]: String	local_0052
		//		ldc "-mainclass"
		//				stack[0]: String	local_0052
		//				stack[1]: String	"-mainclass"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool	local_0052->equals(createString("-mainclass"))
		//		ifne L00DC
		if (local_0052->equals(createString("-mainclass")))
			goto L00DC;
		//				stack: empty
		//		goto L0100
		goto L0100;
		//				stack: empty
	L00A0: //
		//		aload 3
		//				stack[0]: String	local_0052
		//		ldc "-comments"
		//				stack[0]: String	local_0052
		//				stack[1]: String	"-comments"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool	local_0052->equals(createString("-comments"))
		//		ifne L00F4
		if (local_0052->equals(createString("-comments")))
			goto L00F4;
		//				stack: empty
		//		goto L0100
		goto L0100;
		//				stack: empty
	L00AC: //
		//		aload 3
		//				stack[0]: String	local_0052
		//		ldc "-classpath"
		//				stack[0]: String	local_0052
		//				stack[1]: String	"-classpath"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool	local_0052->equals(createString("-classpath"))
		//		ifne L00C4
		if (local_0052->equals(createString("-classpath")))
			goto L00C4;
		//				stack: empty
		//		goto L0100
		goto L0100;
		//				stack: empty
	L00B8: //
		//		aload 3
		//				stack[0]: String	local_0052
		//		ldc "-vs"
		//				stack[0]: String	local_0052
		//				stack[1]: String	"-vs"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool	local_0052->equals(createString("-vs"))
		//		ifne L00E8
		if (local_0052->equals(createString("-vs")))
			goto L00E8;
		//				stack: empty
		//		goto L0100
		goto L0100;
		//				stack: empty
	L00C4: //
		//		aload 1
		//				stack[0]: Recompiler	recompiler_0049
		//		aload 0
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//		iload 2
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//		iconst 1
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//				stack[3]: int	1
		//		iadd
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	(argc_004B) + (1)
		//		aaload
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: String	args->get((argc_004B) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.addClassPath
		recompiler_0049->addClassPath(args->get((argc_004B) + (1)));
		//				stack: empty
		//		goto L011A
		goto L011A;
		//				stack: empty
	L00D0: //
		//		aload 1
		//				stack[0]: Recompiler	recompiler_0049
		//		aload 0
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//		iload 2
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//		iconst 1
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//				stack[3]: int	1
		//		iadd
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	(argc_004B) + (1)
		//		aaload
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: String	args->get((argc_004B) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.setOutputPath
		recompiler_0049->setOutputPath(args->get((argc_004B) + (1)));
		//				stack: empty
		//		goto L011A
		goto L011A;
		//				stack: empty
	L00DC: //
		//		aload 1
		//				stack[0]: Recompiler	recompiler_0049
		//		aload 0
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//		iload 2
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//		iconst 1
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//				stack[3]: int	1
		//		iadd
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	(argc_004B) + (1)
		//		aaload
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: String	args->get((argc_004B) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.setMainClass
		recompiler_0049->setMainClass(args->get((argc_004B) + (1)));
		//				stack: empty
		//		goto L011A
		goto L011A;
		//				stack: empty
	L00E8: //
		//		aload 1
		//				stack[0]: Recompiler	recompiler_0049
		//		aload 0
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//		iload 2
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//		iconst 1
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//				stack[3]: int	1
		//		iadd
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	(argc_004B) + (1)
		//		aaload
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: String	args->get((argc_004B) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.setVisualStudio
		recompiler_0049->setVisualStudio(args->get((argc_004B) + (1)));
		//				stack: empty
		//		goto L011A
		goto L011A;
		//				stack: empty
	L00F4: //
		//		aload 1
		//				stack[0]: Recompiler	recompiler_0049
		//		aload 0
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//		iload 2
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//		iconst 1
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	argc_004B
		//				stack[3]: int	1
		//		iadd
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: JavaArray<String>	args
		//				stack[2]: int	(argc_004B) + (1)
		//		aaload
		//				stack[0]: Recompiler	recompiler_0049
		//				stack[1]: String	args->get((argc_004B) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.setCommentLevel
		recompiler_0049->setCommentLevel(args->get((argc_004B) + (1)));
		//				stack: empty
		//		goto L011A
		goto L011A;
		//				stack: empty
	L0100: //
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//		new java.lang.StringBuilder
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//		ldc "Unsupported argument "
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//				stack[4]: String	"Unsupported argument "
		//		invokespecial java.lang.StringBuilder.<init>
		temp_010A = new StringBuilder(createString("Unsupported argument "));
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_010A
		//		aload 0
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_010A
		//				stack[3]: JavaArray<String>	args
		//		iload 2
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_010A
		//				stack[3]: JavaArray<String>	args
		//				stack[4]: int	argc_004B
		//		aaload
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_010A
		//				stack[3]: String	args->get(argc_004B)
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_010A->append(args->get(argc_004B))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: String	temp_010A->append(args->get(argc_004B))->toString()
		//		invokespecial java.lang.RuntimeException.<init>
		temp_0116 = new RuntimeException(temp_010A->append(args->get(argc_004B))->toString());
		//				stack[0]: RuntimeException	temp_0116
		//		athrow
		throw temp_0116;
		//				stack: empty
	L011A: //
		//		iinc 2 2
		argc_004B += 2;
		//				stack: empty
	L011D: //
		//		iload 2
		//				stack[0]: int	argc_004B
		//		aload 0
		//				stack[0]: int	argc_004B
		//				stack[1]: JavaArray<String>	args
		//		arraylength
		//				stack[0]: int	argc_004B
		//				stack[1]: int	args->length
		//		if_icmplt L004E
		if ((argc_004B) < (args->length))
			goto L004E;
		//				stack: empty
		//		getstatic out Ljava/io/PrintStream;
		//				stack[0]: PrintStream	GetStatic(System::__ClassInit, System::out)
		//		ldc "Done."
		//				stack[0]: PrintStream	GetStatic(System::__ClassInit, System::out)
		//				stack[1]: String	"Done."
		//		invokevirtual java.io.PrintStream.println
		GetStatic(System::__ClassInit, System::out)->println(createString("Done."));
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::addClassPath(Pointer<String> classPath)
	{
		//		aload 0
		//				stack[0]: Recompiler	this
		//		getfield classPaths Ljava/util/ArrayList;
		//				stack[0]: ArrayList<String>	this->classPaths
		//		aload 1
		//				stack[0]: ArrayList<String>	this->classPaths
		//				stack[1]: String	classPath
		//		invokevirtual java.util.ArrayList.add
		//				stack[0]: bool	this->classPaths->add(classPath.getValue())
		//		pop
		this->classPaths->add(classPath.getValue());
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::setMainClass(Pointer<String> mainClass)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		//		aload 0
		//				stack[0]: Recompiler	this
		//		getfield mainClass Ljava/lang/String;
		//				stack[0]: String	this->mainClass
		//		ifnull L0030
		if ((this->mainClass).getValue() == nullptr)
			goto L0030;
		//				stack: empty
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//		new java.lang.StringBuilder
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//		ldc "Main class already set to \'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//				stack[4]: String	"Main class already set to \'"
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0011 = new StringBuilder(createString("Main class already set to \'"));
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//		aload 0
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//				stack[3]: Recompiler	this
		//		getfield mainClass Ljava/lang/String;
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//				stack[3]: String	this->mainClass
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->mainClass)
		//		ldc "\', not setting it to \'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->mainClass)
		//				stack[3]: String	"\', not setting it to \'"
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->mainClass)->append(createString("\', not setting it to \'"))
		//		aload 1
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->mainClass)->append(createString("\', not setting it to \'"))
		//				stack[3]: String	mainClass
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->mainClass)->append(createString("\', not setting it to \'"))->append(mainClass)
		//		ldc "\'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->mainClass)->append(createString("\', not setting it to \'"))->append(mainClass)
		//				stack[3]: String	"\'"
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->mainClass)->append(createString("\', not setting it to \'"))->append(mainClass)->append(createString("\'"))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: String	temp_0011->append(this->mainClass)->append(createString("\', not setting it to \'"))->append(mainClass)->append(createString("\'"))->toString()
		//		invokespecial java.lang.RuntimeException.<init>
		temp_002C = new RuntimeException(temp_0011->append(this->mainClass)->append(createString("\', not setting it to \'"))->append(mainClass)->append(createString("\'"))->toString());
		//				stack[0]: RuntimeException	temp_002C
		//		athrow
		throw temp_002C;
		//				stack: empty
	L0030: //
		//		aload 0
		//				stack[0]: Recompiler	this
		//		aload 1
		//				stack[0]: Recompiler	this
		//				stack[1]: String	mainClass
		//		putfield mainClass Ljava/lang/String;
		this->mainClass = mainClass.getValue();
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::setOutputPath(Pointer<String> outputPath)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		//		aload 0
		//				stack[0]: Recompiler	this
		//		getfield outputPath Ljava/lang/String;
		//				stack[0]: String	this->outputPath
		//		ifnull L0030
		if ((this->outputPath).getValue() == nullptr)
			goto L0030;
		//				stack: empty
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//		new java.lang.StringBuilder
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//		ldc "Output path already set to \'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//				stack[4]: String	"Output path already set to \'"
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0011 = new StringBuilder(createString("Output path already set to \'"));
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//		aload 0
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//				stack[3]: Recompiler	this
		//		getfield outputPath Ljava/lang/String;
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//				stack[3]: String	this->outputPath
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->outputPath)
		//		ldc "\', not setting it to \'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->outputPath)
		//				stack[3]: String	"\', not setting it to \'"
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->outputPath)->append(createString("\', not setting it to \'"))
		//		aload 1
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->outputPath)->append(createString("\', not setting it to \'"))
		//				stack[3]: String	outputPath
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->outputPath)->append(createString("\', not setting it to \'"))->append(outputPath)
		//		ldc "\'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->outputPath)->append(createString("\', not setting it to \'"))->append(outputPath)
		//				stack[3]: String	"\'"
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->outputPath)->append(createString("\', not setting it to \'"))->append(outputPath)->append(createString("\'"))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: String	temp_0011->append(this->outputPath)->append(createString("\', not setting it to \'"))->append(outputPath)->append(createString("\'"))->toString()
		//		invokespecial java.lang.RuntimeException.<init>
		temp_002C = new RuntimeException(temp_0011->append(this->outputPath)->append(createString("\', not setting it to \'"))->append(outputPath)->append(createString("\'"))->toString());
		//				stack[0]: RuntimeException	temp_002C
		//		athrow
		throw temp_002C;
		//				stack: empty
	L0030: //
		//		aload 0
		//				stack[0]: Recompiler	this
		//		aload 1
		//				stack[0]: Recompiler	this
		//				stack[1]: String	outputPath
		//		putfield outputPath Ljava/lang/String;
		this->outputPath = outputPath.getValue();
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::setVisualStudio(Pointer<String> visualStudio)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		//		aload 0
		//				stack[0]: Recompiler	this
		//		getfield visualStudio Ljava/lang/String;
		//				stack[0]: String	this->visualStudio
		//		ifnull L0030
		if ((this->visualStudio).getValue() == nullptr)
			goto L0030;
		//				stack: empty
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//		new java.lang.StringBuilder
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//		ldc "Visual Studio already set to \'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//				stack[4]: String	"Visual Studio already set to \'"
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0011 = new StringBuilder(createString("Visual Studio already set to \'"));
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//		aload 0
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//				stack[3]: Recompiler	this
		//		getfield visualStudio Ljava/lang/String;
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011
		//				stack[3]: String	this->visualStudio
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->visualStudio)
		//		ldc "\', not setting it to \'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->visualStudio)
		//				stack[3]: String	"\', not setting it to \'"
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->visualStudio)->append(createString("\', not setting it to \'"))
		//		aload 1
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->visualStudio)->append(createString("\', not setting it to \'"))
		//				stack[3]: String	visualStudio
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->visualStudio)->append(createString("\', not setting it to \'"))->append(visualStudio)
		//		ldc "\'"
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->visualStudio)->append(createString("\', not setting it to \'"))->append(visualStudio)
		//				stack[3]: String	"\'"
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0011->append(this->visualStudio)->append(createString("\', not setting it to \'"))->append(visualStudio)->append(createString("\'"))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: String	temp_0011->append(this->visualStudio)->append(createString("\', not setting it to \'"))->append(visualStudio)->append(createString("\'"))->toString()
		//		invokespecial java.lang.RuntimeException.<init>
		temp_002C = new RuntimeException(temp_0011->append(this->visualStudio)->append(createString("\', not setting it to \'"))->append(visualStudio)->append(createString("\'"))->toString());
		//				stack[0]: RuntimeException	temp_002C
		//		athrow
		throw temp_002C;
		//				stack: empty
	L0030: //
		//		aload 0
		//				stack[0]: Recompiler	this
		//		aload 1
		//				stack[0]: Recompiler	this
		//				stack[1]: String	visualStudio
		//		putfield visualStudio Ljava/lang/String;
		this->visualStudio = visualStudio.getValue();
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::setCommentLevel(Pointer<String> commentLevel)
	{
		Pointer<String> local_0002;
		Pointer<StringBuilder> temp_0058;
		Pointer<RuntimeException> temp_0062;
		//		aload 1
		//				stack[0]: String	commentLevel
		//		dup
		//				stack[0]: String	commentLevel
		//				stack[1]: String	commentLevel
		//		astore 2
		local_0002 = commentLevel;
		//				stack[0]: String	commentLevel
		//		invokevirtual java.lang.String.hashCode
		//				stack[0]: int	commentLevel->hashCode()
		//		lookupswitch 2 cases
		switch (commentLevel->hashCode())
		{
		case (int)0x000179A1:
			goto L0020;
		case (int)0x0033AF38:
			goto L002C;
		default:
			goto L004E;
		}
		//				stack: empty
	L0020: //
		//		aload 2
		//				stack[0]: String	local_0002
		//		ldc "all"
		//				stack[0]: String	local_0002
		//				stack[1]: String	"all"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool	local_0002->equals(createString("all"))
		//		ifne L0038
		if (local_0002->equals(createString("all")))
			goto L0038;
		//				stack: empty
		//		goto L004E
		goto L004E;
		//				stack: empty
	L002C: //
		//		aload 2
		//				stack[0]: String	local_0002
		//		ldc "none"
		//				stack[0]: String	local_0002
		//				stack[1]: String	"none"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool	local_0002->equals(createString("none"))
		//		ifne L0043
		if (local_0002->equals(createString("none")))
			goto L0043;
		//				stack: empty
		//		goto L004E
		goto L004E;
		//				stack: empty
	L0038: //
		//		iconst 1
		//				stack[0]: int	1
		//		putstatic instructionComments Z
		Recompiler::__ClassInit();
		Recompiler::instructionComments = true;
		//				stack: empty
		//		iconst 1
		//				stack[0]: int	1
		//		putstatic stackComments Z
		Recompiler::__ClassInit();
		Recompiler::stackComments = true;
		//				stack: empty
		//		goto L0066
		goto L0066;
		//				stack: empty
	L0043: //
		//		iconst 0
		//				stack[0]: int	0
		//		putstatic instructionComments Z
		Recompiler::__ClassInit();
		Recompiler::instructionComments = false;
		//				stack: empty
		//		iconst 0
		//				stack[0]: int	0
		//		putstatic stackComments Z
		Recompiler::__ClassInit();
		Recompiler::stackComments = false;
		//				stack: empty
		//		goto L0066
		goto L0066;
		//				stack: empty
	L004E: //
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//		new java.lang.StringBuilder
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//		dup
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//		ldc "Unsupported comment level "
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	new
		//				stack[3]: StringBuilder	new
		//				stack[4]: String	"Unsupported comment level "
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0058 = new StringBuilder(createString("Unsupported comment level "));
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0058
		//		aload 1
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0058
		//				stack[3]: String	commentLevel
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: StringBuilder	temp_0058->append(commentLevel)
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: RuntimeException	new
		//				stack[1]: RuntimeException	new
		//				stack[2]: String	temp_0058->append(commentLevel)->toString()
		//		invokespecial java.lang.RuntimeException.<init>
		temp_0062 = new RuntimeException(temp_0058->append(commentLevel)->toString());
		//				stack[0]: RuntimeException	temp_0062
		//		athrow
		throw temp_0062;
		//				stack: empty
	L0066: //
		//		return
		return;
		//				stack: empty
	}

}
