#pragma once

#include "java__lang__Object.h"
#include "java__util__Iterator.h"
#include "java__util__NoSuchElementException.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class TreeSet : public Object
	{
		class Itr : public Iterator
		{
		public:
			Itr(std::vector<Pointer<Object>>& _data)
				: data(_data)
			{
				cursor = 0;
			}
			virtual Pointer<Object> next()
			{
				if (!hasNext())
					throw new NoSuchElementException();
				Pointer<Object> element = data[cursor++];
				return element;
			}
			virtual bool hasNext()
			{
				return cursor < data.size();
			}
		private:
			std::vector<Pointer<Object>>& data;
			int cursor;
		};
	public:
		virtual Pointer<Iterator> iterator()
		{
			return new Itr(data);
		}
		virtual void add(Pointer<T> element)
		{
			Object* object2 = (Object*)element.getValue();
			bool added = false;
			for (auto iter = data.begin(); iter != data.end(); ++iter)
			{
				Object* object1 = (Object*)(*iter).getValue();
				if (object1->equals(object2))
				{
					added = true;
					break;
				}
				if (*object1 < object2)
					continue;
				data.insert(iter, object2);
				added = true;
				break;
			}
			if (!added)
				data.insert(data.end(), object2);
		}
		virtual void remove(Pointer<T> element)
		{
			Object* object2 = (Object*)element.getValue();
			for (auto iter = data.begin(); iter != data.end(); ++iter)
			{
				Object* object1 = (Object*)(*iter).getValue();
				if (object1->equals(object2))
				{
					data.erase(iter);
					break;
				}
			}
		}
		virtual bool contains(Pointer<T> element)
		{
			Object* object2 = (Object*)element.getValue();
			for (auto iter = data.begin(); iter != data.end(); ++iter)
			{
				Object* object1 = (Object*)(*iter).getValue();
				if (object1->equals(object2))
					return true;
			}
			return false;
		}
		virtual int size()
		{
			return (int)data.size();
		}
	private:
		std::vector<Pointer<Object>> data;
	};
}
