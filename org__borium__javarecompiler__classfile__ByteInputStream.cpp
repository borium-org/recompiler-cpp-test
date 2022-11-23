#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "java__lang__Class.h"
#include "java__lang__String.h"

#include "java__io__ByteArrayInputStream.h"
#include "java__io__IOException.h"
#include "java__io__UnsupportedEncodingException.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__Double.h"
#include "java__lang__Float.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"

using namespace java::io;
using namespace java::lang;

namespace org::borium::javarecompiler::classfile
{

	Pointer<Class> ByteInputStream::__thisClassStatic;

	void ByteInputStream::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		__thisClassStatic = new Class(
			"org::borium::javarecompiler::classfile::ByteInputStream",
			java::lang::Object::__thisClassStatic);

		java::lang::Object::__ClassInit();
	}

	ByteInputStream::ByteInputStream(Pointer<JavaRawArray<byte>> data) :
		Object() //
		, length(0) //
	{
		__ClassInit();
		__thisClass = __thisClassStatic;

		Pointer<ByteArrayInputStream> temp_000A;
		temp_000A = new ByteArrayInputStream(data);
		this->in = temp_000A.getValue();
		this->length = data->length;
		return;
	}

	int ByteInputStream::available()
	{
		return this->in->available();
	}

	void ByteInputStream::close()
	{
		Pointer<IOException> e_0032;
		Pointer<StringBuilder> temp_0011;
		Pointer<ClassFormatError> temp_0023;
	L0000: //
		try
		{
			if ((this->available()) <= 0)
				goto L0027;
			temp_0011 = new StringBuilder(createString("Closing with "));
			temp_0023 = new ClassFormatError(temp_0011->append(this->available())->append(createString(" bytes available"))->toString());
			throw temp_0023;
		L0027: //
			this->in->close();
		L002E: //
			goto L0036;
		}
		catch (IOException* e_0032)
		{
			e_0032->printStackTrace();
		}
	L0036: //
		return;
	}

	double ByteInputStream::f4()
	{
		int data_0017 = 0;
		double value_001D = 0;
		Pointer<ClassFormatError> temp_000E;
		if ((this->available()) >= (4))
			goto L0012;
		temp_000E = new ClassFormatError(createString("Not enough data available to read a float"));
		throw temp_000E;
	L0012: //
		data_0017 = this->s4();
		Float::__ClassInit();
		value_001D = (double) (Float::intBitsToFloat(data_0017));
		return value_001D;
	}

	double ByteInputStream::f8()
	{
		INT64 data_0018 = 0;
		double value_001D = 0;
		Pointer<ClassFormatError> temp_000F;
		if ((this->available()) >= (8))
			goto L0013;
		temp_000F = new ClassFormatError(createString("Not enough data available to read a double"));
		throw temp_000F;
	L0013: //
		data_0018 = this->u8();
		Double::__ClassInit();
		value_001D = Double::longBitsToDouble(data_0018);
		return value_001D;
	}

	int ByteInputStream::getPosition()
	{
		return (this->length) - (this->in->available());
	}

	Pointer<JavaRawArray<byte>> ByteInputStream::read(int length)
	{
		Pointer<JavaRawArray<byte>> data_0024;
		Pointer<IOException> e_0031;
		Pointer<StringBuilder> temp_0012;
		Pointer<ClassFormatError> temp_001C;
		Pointer<JavaRawArray<byte>> temp_0021;
		Pointer<ClassFormatError> temp_0037;
		if ((this->available()) >= (length))
			goto L0020;
		temp_0012 = new StringBuilder(createString("Not enough data available to read, needed "));
		temp_001C = new ClassFormatError(temp_0012->append(length)->toString());
		throw temp_001C;
	L0020: //
		temp_0021 = new JavaRawArray<byte>(length);
		data_0024 = (JavaRawArray<byte>*)(temp_0021.getValue());
	L0024: //
		try
		{
			this->in->read(data_0024);
		L002D: //
			goto L003B;
		}
		catch (IOException* e_0031)
		{
			temp_0037 = new ClassFormatError(createString("Can\'t read byte array"));
			throw temp_0037;
		}
	L003B: //
		return data_0024;
	}

	int ByteInputStream::s1()
	{
		int value_001A = 0;
		Pointer<ClassFormatError> temp_000E;
		if ((this->available()) >= (1))
			goto L0012;
		temp_000E = new ClassFormatError(createString("Not enough data available to read a byte"));
		throw temp_000E;
	L0012: //
		value_001A = this->in->read();
		if ((value_001A) < (128))
			goto L0027;
		value_001A += -256;
	L0027: //
		return value_001A;
	}

	int ByteInputStream::s2()
	{
		int value_0025 = 0;
		Pointer<ClassFormatError> temp_000E;
		if ((this->available()) >= (2))
			goto L0012;
		temp_000E = new ClassFormatError(createString("Not enough data available to read a short"));
		throw temp_000E;
	L0012: //
		value_0025 = (_shlx_u32(this->in->read(), (8) & 0x1F)) | (this->in->read());
		if ((value_0025) < (32768))
			goto L0030;
		value_0025 = (value_0025) - (65536);
	L0030: //
		return value_0025;
	}

	int ByteInputStream::s4()
	{
		Pointer<ClassFormatError> temp_000E;
		if ((this->available()) >= (4))
			goto L0012;
		temp_000E = new ClassFormatError(createString("Not enough data available to read an int"));
		throw temp_000E;
	L0012: //
		return this->u4();
	}

	int ByteInputStream::u1()
	{
		Pointer<ClassFormatError> temp_000E;
		if ((this->available()) >= (1))
			goto L0012;
		temp_000E = new ClassFormatError(createString("Not enough data available to read a byte"));
		throw temp_000E;
	L0012: //
		return this->in->read();
	}

	int ByteInputStream::u2()
	{
		int byte1_001A = 0;
		int byte2_0022 = 0;
		Pointer<ClassFormatError> temp_000E;
		if ((this->available()) >= (2))
			goto L0012;
		temp_000E = new ClassFormatError(createString("Not enough data available to read an ushort"));
		throw temp_000E;
	L0012: //
		byte1_001A = this->in->read();
		byte2_0022 = this->in->read();
		return (_shlx_u32(byte1_001A, (8) & 0x1F)) | (byte2_0022);
	}

	int ByteInputStream::u4()
	{
		int byte1_001A = 0;
		int byte2_0022 = 0;
		int byte3_002A = 0;
		int byte4_0033 = 0;
		Pointer<ClassFormatError> temp_000E;
		if ((this->available()) >= (4))
			goto L0012;
		temp_000E = new ClassFormatError(createString("Not enough data available to read an uint"));
		throw temp_000E;
	L0012: //
		byte1_001A = this->in->read();
		byte2_0022 = this->in->read();
		byte3_002A = this->in->read();
		byte4_0033 = this->in->read();
		return (((_shlx_u32(byte1_001A, (24) & 0x1F)) | (_shlx_u32(byte2_0022, (16) & 0x1F))) | (_shlx_u32(byte3_002A, (8) & 0x1F))) | (byte4_0033);
	}

	INT64 ByteInputStream::u8()
	{
		INT64 byte1_001C = 0;
		INT64 byte2_0025 = 0;
		INT64 byte3_002F = 0;
		INT64 byte4_0039 = 0;
		INT64 byte5_0043 = 0;
		INT64 byte6_004D = 0;
		INT64 byte7_0057 = 0;
		INT64 byte8_0061 = 0;
		Pointer<ClassFormatError> temp_000F;
		if ((this->available()) >= (8))
			goto L0013;
		temp_000F = new ClassFormatError(createString("Not enough data available to read an ulong"));
		throw temp_000F;
	L0013: //
		byte1_001C = (INT64) (this->in->read());
		byte2_0025 = (INT64) (this->in->read());
		byte3_002F = (INT64) (this->in->read());
		byte4_0039 = (INT64) (this->in->read());
		byte5_0043 = (INT64) (this->in->read());
		byte6_004D = (INT64) (this->in->read());
		byte7_0057 = (INT64) (this->in->read());
		byte8_0061 = (INT64) (this->in->read());
		return (((((((_shlx_u64(byte1_001C, (56) & 0x3F)) | (_shlx_u64(byte2_0025, (48) & 0x3F))) | (_shlx_u64(byte3_002F, (40) & 0x3F))) | (_shlx_u64(byte4_0039, (32) & 0x3F))) | (_shlx_u64(byte5_0043, (24) & 0x3F))) | (_shlx_u64(byte6_004D, (16) & 0x3F))) | (_shlx_u64(byte7_0057, (8) & 0x3F))) | (byte8_0061);
	}

	Pointer<String> ByteInputStream::utf8()
	{
		int length_0017 = 0;
		Pointer<JavaRawArray<byte>> bytes_001D;
		Pointer<String> result_0028;
		Pointer<String> result_0037;
		Pointer<ClassFormatError> temp_000E;
		Pointer<String> temp_0024;
		Pointer<ClassFormatError> temp_0033;
		if ((this->available()) >= (2))
			goto L0012;
		temp_000E = new ClassFormatError(createString("Not enough data available to read UTF8 length"));
		throw temp_000E;
	L0012: //
		length_0017 = this->u2();
		bytes_001D = (JavaRawArray<byte>*)(this->read(length_0017).getValue());
	L001D: //
		try
		{
			temp_0024 = new String(bytes_001D, createString("UTF-8"));
			result_0028 = temp_0024;
		L0028: //
			goto L0037;
		}
		catch (UnsupportedEncodingException* e_002D)
		{
			temp_0033 = new ClassFormatError(createString("UTF-8 exception"));
			throw temp_0033;
		}
	L0037: //
		return result_0037;
	}

}
