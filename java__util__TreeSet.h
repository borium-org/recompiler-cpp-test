#pragma once

#include "java__lang__Object.h"
#include "java__util__Iterator.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class TreeSet : public Object
	{
		class Itr : public Iterator
		{
		public:
			Itr(std::set<Pointer<Object>>* set)
			{
				data = set;
				iter = data->begin();
			}
			virtual Pointer<Object> next()
			{
				Pointer<Object> obj = *iter;
				iter++;
				return obj;
			}
			virtual bool hasNext()
			{
				return iter != data->end();
			}
		private:
			std::set<Pointer<Object>>* data;
			std::set<Pointer<Object>>::iterator iter;
		};
	public:
		virtual Pointer<Iterator> iterator()
		{
			return new Itr(&data);
		}
		virtual void add(Pointer<T> element)
		{
			Pointer<Object> object = element.getValue();
			data.insert(object);
		}
		virtual void remove(Pointer<T> element)
		{
			Pointer<Object> object = element.getValue();
			data.erase(object);
		}
		virtual bool contains(Pointer<T> element)
		{
			Pointer<Object> object = element.getValue();
			return data.contains(object);
		}
		virtual int size()
		{
			return (int)data.size();
		}
	private:
		std::set<Pointer<Object>> data;
	};
}
