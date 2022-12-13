#include "stdafx.h"
#include "java__lang__Character.h"

#include "java__lang__String.h"

namespace java::lang
{
	CString Character::javaIdentifierPart;

	void Character::__ClassInit()
	{
		static bool classInitialized = false;
		if (classInitialized)
			return;
		classInitialized = true;

		javaIdentifierPart = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	}

	Pointer<String> Character::valueOf(char value)
	{
		CString string;
		string.Format("%c", value);
		return new String(string);
	}

	Pointer<String> Character::toString(int value)
	{
		return valueOf(value);
	}

	bool Character::isJavaIdentifierPart(char value)
	{
		return javaIdentifierPart.Find(value) >= 0;
	}
}
