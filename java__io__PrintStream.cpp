#include "stdafx.h"
#include "java__io__PrintStream.h"
#include "java__lang__String.h"

namespace java::io
{

	PrintStream::PrintStream(Pointer<String> fileName)
	{
		ofs = new std::ofstream();
		os = ofs;
	}

	PrintStream::PrintStream(std::ostream& os)
	{
		this->os = &os;
		ofs = nullptr;
	}

	//PrintStream::PrintStream()
	//{
	//}

	//PrintStream::~PrintStream()
	//{
	//}

	void PrintStream::print(Pointer<String> text)
	{
		CString textOut = text->operator CString();
		*os << textOut.GetBuffer();
	}

	void PrintStream::println()
	{
		*os << std::endl;
	}

	void PrintStream::println(const char* text)
	{
		*os << text << std::endl;
	}

	void PrintStream::println(Pointer<String> text)
	{
		CString textOut = text->operator CString();
		*os << textOut.GetBuffer() << std::endl;
	}

}
