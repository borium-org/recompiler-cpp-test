#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Object;
	class String;
}

using namespace java::lang;

namespace org::borium::javarecompiler::cplusplus
{

	class TernaryOperator : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<String> condition;
		int falsePathAddress;
		int endAddress;
		int endOfTruePath;

		static void __ClassInit();
		TernaryOperator();
	};

}
