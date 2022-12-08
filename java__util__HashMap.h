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
		virtual Pointer<V> put(Pointer<K> key, Pointer<V> value)
		{
			Pointer<V> element;
			Object* object2 = (Object*)key.getValue();
			if (map.size() == 0)
				map[key] = value;
			else
			{
				for (auto iter = map.begin(); iter != map.end(); ++iter)
				{
					Object* object1 = (Object*)iter->first.getValue();
					if (object1->equals(object2))
					{
						element = iter->second;
						iter->second = value;
						break;
					}
				}
			}
			return element;
		}
		virtual Pointer<V> get(Pointer<K> key)
		{
			Pointer<V> element;
			Object* object2 = (Object*)key.getValue();
			for (auto iter = map.begin(); iter != map.end(); ++iter)
			{
				Object* object1 = (Object*)iter->first.getValue();
				if (object1->equals(object2))
				{
					element = iter->second;
					break;
				}
			}
			return element;
		}
		virtual Pointer<V> remove(Pointer<K> key)
		{
			Pointer<V> removed;
			Object* object2 = (Object*)key.getValue();
			for (auto iter = map.begin(); iter != map.end(); ++iter)
			{
				Object* object1 = (Object*)iter->first.getValue();
				if (object1->equals(object2))
				{
					removed = iter->second;
					map.erase(iter);
					break;
				}
			}
			return removed;
		}
		virtual bool containsKey(Pointer<K> key)
		{
			Object* object2 = (Object*)key.getValue();
			for (auto iter = map.begin(); iter != map.end(); ++iter)
			{
				Object* object1 = (Object*)iter->first.getValue();
				if (object1->equals(object2))
					return true;
			}
			return false;
		}
		virtual bool containsValue(Pointer<V> value)
		{
			for (auto iter = map.begin(); iter != map.end(); ++iter)
			{
				Object* object1 = (Object*)iter->second.getValue();
				Object* object2 = (Object*)value.getValue();
				if (object1->equals(object2))
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
