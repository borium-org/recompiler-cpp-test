#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__IOException.h"
#include "java__io__PrintStream.h"
#include "java__lang__Integer.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "java__util__Iterator.h"
#include "org__borium__javarecompiler__Statics.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> IndentedOutputStream::__thisClassStatic;

	bool IndentedOutputStream::_disableLocking;

	void IndentedOutputStream::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::IndentedOutputStream",
			java::lang::Object::__thisClassStatic);

		Object::__ClassInit();
		IndentedOutputStream::_disableLocking = false;
		return;
	}

	void IndentedOutputStream::disableLocking()
	{
		__ClassInit();

		IndentedOutputStream::__ClassInit();
		IndentedOutputStream::_disableLocking = true;
		return;
	}

	IndentedOutputStream::IndentedOutputStream(Pointer<String> fileName) :
		Object() //
		, indentLevel(0) //
		, locked(false) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<PrintStream> temp_000F;
		this->indentLevel = 0;
		temp_000F = new PrintStream(fileName);
		this->stream = temp_000F.getValue();
		this->locked = false;
		return;
	}

	void IndentedOutputStream::close()
	{
		if (!(this->locked))
			goto L000B;
		this->unlock();
	L000B: //
		this->stream->close();
		return;
	}

	void IndentedOutputStream::indent(int i)
	{
		this->indentLevel = (this->indentLevel) + (i);
		return;
	}

	void IndentedOutputStream::iprint(Pointer<String> string)
	{
		Pointer<String> output_0003;
		int i_0005 = 0;
		Pointer<StringBuilder> temp_0010;
		Pointer<StringBuilder> temp_002F;
		output_0003 = createString("");
		i_0005 = 0;
		goto L001F;
	L0008: //
		String::__ClassInit();
		temp_0010 = new StringBuilder(String::valueOf(output_0003.getValue()));
		output_0003 = temp_0010->append(createString("\t"))->toString();
		i_0005 += 1;
	L001F: //
		if ((i_0005) < (this->indentLevel))
			goto L0008;
		String::__ClassInit();
		temp_002F = new StringBuilder(String::valueOf(output_0003.getValue()));
		output_0003 = temp_002F->append(string)->toString();
		if (!(this->locked))
			goto L004D;
		this->temporaryOutput->add(output_0003.getValue());
		goto L0055;
	L004D: //
		this->stream->print(output_0003);
	L0055: //
		return;
	}

	void IndentedOutputStream::iprintln(Pointer<JavaRawArray<byte>> info)
	{
		int start_0002 = 0;
		int offset_000D = 0;
		start_0002 = 0;
		goto L0050;
	L0005: //
		this->iprint(createString(""));
		offset_000D = 0;
		goto L0043;
	L0010: //
		if (((start_0002) + (offset_000D)) < (info->length))
			goto L001B;
		goto L0049;
	L001B: //
		this->printHex(info->get((start_0002) + (offset_000D)), 2);
		if ((offset_000D) != (7))
			goto L0034;
		this->print(createString(" | "));
		goto L0040;
	L0034: //
		if ((offset_000D) == (15))
			goto L0040;
		this->print(createString(" "));
	L0040: //
		offset_000D += 1;
	L0043: //
		if ((offset_000D) < (16))
			goto L0010;
	L0049: //
		this->println();
		start_0002 += 16;
	L0050: //
		if ((start_0002) < (info->length))
			goto L0005;
		return;
	}

	void IndentedOutputStream::iprintln(Pointer<JavaRawArray<byte>> info, int start, int length)
	{
		this->iprint(createString(""));
		this->println(info, start, length);
		return;
	}

	void IndentedOutputStream::iprintln(Pointer<String> string)
	{
		this->iprint(string);
		this->println();
		return;
	}

	void IndentedOutputStream::liprintln(int temporaryIndent, Pointer<String> string)
	{
		bool saveLocked_0014 = false;
		int currentIndent_001F = 0;
		IndentedOutputStream::__ClassInit();
		if (IndentedOutputStream::_disableLocking)
			goto L000F;
		Statics::__ClassInit();
		Statics::Assert(this->locked, createString("liprintln() is made for printing into locked files"));
	L000F: //
		saveLocked_0014 = this->locked;
		this->locked = false;
		currentIndent_001F = this->indentLevel;
		this->indentLevel = temporaryIndent;
		this->iprintln(string);
		this->indentLevel = currentIndent_001F;
		this->locked = saveLocked_0014;
		return;
	}

	void IndentedOutputStream::lock()
	{
		Pointer<ArrayList<Object>> temp_0021;
		IndentedOutputStream::__ClassInit();
		if (IndentedOutputStream::_disableLocking)
			goto L0027;
		Statics::__ClassInit();
		Statics::Assert((((this->locked) ? (0) : (1))) != 0, createString("Stream must be unlocked before locking"));
		this->locked = true;
		temp_0021 = new ArrayList<Object>();
		this->temporaryOutput = (ArrayList<String>*)temp_0021.getValue();
	L0027: //
		return;
	}

	void IndentedOutputStream::print(Pointer<String> string)
	{
		if (!(this->locked))
			goto L0013;
		this->temporaryOutput->add(string.getValue());
		goto L001B;
	L0013: //
		this->stream->print(string);
	L001B: //
		return;
	}

	void IndentedOutputStream::printHex(int value, int length)
	{
		Pointer<String> hex_0005;
		Pointer<StringBuilder> temp_000E;
		Integer::__ClassInit();
		hex_0005 = Integer::toHexString(value);
		goto L0019;
	L0008: //
		temp_000E = new StringBuilder(createString("0"));
		hex_0005 = temp_000E->append(hex_0005)->toString();
	L0019: //
		if ((hex_0005->length()) < (length))
			goto L0008;
		hex_0005 = hex_0005->substring((hex_0005->length()) - (length))->toUpperCase();
		if (!(this->locked))
			goto L0042;
		this->temporaryOutput->add(hex_0005.getValue());
		goto L004A;
	L0042: //
		this->stream->print(hex_0005);
	L004A: //
		return;
	}

	void IndentedOutputStream::println()
	{
		if (!(this->locked))
			goto L0014;
		this->temporaryOutput->add(createString("\n"));
		goto L001B;
	L0014: //
		this->stream->println();
	L001B: //
		return;
	}

	void IndentedOutputStream::println(Pointer<JavaRawArray<byte>> info, int start, int length)
	{
		int offset_0003 = 0;
		offset_0003 = start;
		goto L0018;
	L0006: //
		this->printHex(info->get(offset_0003), 2);
		this->print(createString(" "));
		offset_0003 += 1;
	L0018: //
		if ((offset_0003) < ((start) + (length)))
			goto L0006;
		this->println();
		return;
	}

	void IndentedOutputStream::println(Pointer<String> string)
	{
		Pointer<StringBuilder> temp_0013;
		if (!(this->locked))
			goto L0025;
		String::__ClassInit();
		temp_0013 = new StringBuilder(String::valueOf(string.getValue()));
		this->temporaryOutput->add(temp_0013->append(createString("\n"))->toString().getValue());
		goto L002D;
	L0025: //
		this->stream->println(string);
	L002D: //
		return;
	}

	void IndentedOutputStream::unlock()
	{
		Pointer<String> string_0029;
		Pointer<Iterator> local_001B;
		Pointer<String> temp_0025;
		IndentedOutputStream::__ClassInit();
		if (IndentedOutputStream::_disableLocking)
			goto L0058;
		Statics::__ClassInit();
		Statics::Assert(this->locked, createString("Stream must be locked before unlocking"));
		this->locked = false;
		local_001B = this->temporaryOutput->iterator();
		goto L004F;
	L001F: //
		temp_0025 = (String*)((local_001B->next()).getValue());
		temp_0025->checkCast(String::__thisClassStatic);
		string_0029 = temp_0025;
		if (!(string_0029->endsWith(createString("\n"))))
			goto L0047;
		this->stream->println(string_0029->substring(0, (string_0029->length()) - (1)));
		goto L004F;
	L0047: //
		this->stream->print(string_0029);
	L004F: //
		if (local_001B->hasNext())
			goto L001F;
	L0058: //
		return;
	}

}
