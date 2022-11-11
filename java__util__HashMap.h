#pragma once

#include "java__util__Map.h"

using namespace java::lang;

namespace java::util
{
	template<class K, class V>
	class HashMap : public Map<K, V>
	{
	public:
		HashMap()
		{
		}
		//	virtual ~HashMap();
		//	//{
		//	//	while (map.GetCount() > 0)
		//	//	{
		//	//		POSITION pos = map.GetStartPosition();
		//	//		Pointer<K> key;
		//	//		Pointer<V> value;
		//	//		map.GetNextAssoc(pos, key, value);
		//	//		map.RemoveKey(key);
		//	//		// make sure these Pointer objects are deactivated
		//	//		key = nullptr;
		//	//		value = nullptr;
		//	//	}
		//	//}
		virtual Pointer<V> put(Pointer<K> key, Pointer<V> value)
		{
			Pointer<V> previous;
			if (map.contains(key))
				previous = map[key];
			map[key] = value;
			return previous;
		}
		virtual Pointer<V> get(Pointer<K> key)
		{
			if (!map.contains(key))
				return (V*)nullptr;
			return map[key];
		}
		virtual Pointer<V> remove(Pointer<K> key)
		{
			Pointer<V> removed;
			if (map.contains(key))
			{
				removed = map[key];
				map.erase(key);
			}
			return removed;
		}
		virtual bool containsKey(Pointer<K> key)
		{
			return map.contains(key);
		}
		virtual bool containsValue(Pointer<V> value)
		{
			for (auto iter = map.begin(); iter != map.end(); ++iter)
			{
				if (iter->second.getValue() == value.getValue())
					return true;
			}
			return false;
		}
		virtual int size()
		{
			return (int)map.size();
		}
	private:
		std::map<Pointer<K>, Pointer<V>> map;
	};
}
