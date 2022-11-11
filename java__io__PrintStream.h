#pragma once

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::io
{
	class PrintStream : public Object
	{
	public:
		//	PrintStream();
		PrintStream(std::ostream& os);
		PrintStream(Pointer<String> fileName);
		~PrintStream()
		{
			if (ofs)
				delete ofs;
			else if (os)
				delete os;
		}
		virtual void close()
		{
			if (ofs)
				ofs->close();
		}
		virtual void print(Pointer<String> text);
		virtual void println();
		virtual void println(const char* text);
		virtual void println(Pointer<String> text);
	private:
		std::ostream* os;
		std::ofstream* ofs;
	};
}
