#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class Serializable;
}

namespace java::lang
{
	class Character;
	class Object;
	class String;
	class StringBuilder;
}

namespace java::util
{
	template <class A> class ArrayList;
}

namespace org::borium::javarecompiler
{
	class Statics;
}

namespace org::borium::javarecompiler::cplusplus
{
	class LocalVariable;
	class LocalVariables;
}

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler::cplusplus
{

	class JavaTypeConverter : public Object
	{
	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Pointer<String> javaType;
		Pointer<String> cppType;
		int index;
		int dimensions;
		int parameterIndex;
		Pointer<LocalVariables> locals;

		static void __ClassInit();
		JavaTypeConverter(Pointer<String> javaType, bool isStatic);
		JavaTypeConverter(Pointer<String> javaType, bool isStatic, Pointer<LocalVariables> locals);
		virtual Pointer<String> getCppType();
		virtual Pointer<JavaArray<String>> parseParameterTypes();
		virtual void parseClass();
		virtual void parseMethod();
		virtual void parseSingleType(bool addParameter);
		virtual void removeTemplateArguments();
	};

}
