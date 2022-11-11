#pragma once

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	template<class K, class V>
	class Map$Entry : public Object
	{
	public:
		Pointer<K> getKey()
		{
			return k;
		}
		Pointer<K> k;
		//	Pointer<V> v;
	};

	template<class K, class V>
	class Map : public Object
	{
	};
}
