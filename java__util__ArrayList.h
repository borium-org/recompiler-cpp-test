#pragma once

#include "java__util__List.h"
#include "java__util__Iterator.h"
#include "java__util__NoSuchElementException.h"

namespace java::util
{
	template<class T>
	class ArrayList : public List<T>
	{
		class Itr : public Iterator
		{
		public:
			Itr(std::vector<Pointer<Object>>& _arrayList)
				: arrayList(_arrayList)
			{
				cursor = 0;
			}
			virtual Pointer<Object> next()
			{
				if (!hasNext())
					throw new NoSuchElementException();
				Pointer<Object> element = arrayList[cursor++];
				return element;
			}
			virtual bool hasNext()
			{
				return cursor < arrayList.size();
			}
		private:
			std::vector<Pointer<Object>>& arrayList;
			int cursor;
		};
	public:
		ArrayList()
		{
			data.reserve(10);
		}
		//	virtual ~ArrayList()
		//	{
		//		delete[] data;
		//	}
		virtual bool add(Pointer<T> element)
		{
			data.push_back((Object*)element.getValue());
			return true;
		}
		virtual void addAll(Pointer<ArrayList<T>> elements)
		{
			for (int i = 0; i < elements->size(); i++)
				add(elements->get(i));
		}
		virtual Pointer<T> get(int index)
		{
			ASSERT(index >= 0 && index < size());
			return (T*)data[index].getValue();
		}
		virtual Pointer<T> remove(int index)
		{
			ASSERT(index >= 0 && index < size());
			Pointer<T> removed = (T*)data[index].getValue();
			data.erase(data.begin() + index);
			return removed;
		}
		virtual bool contains(Pointer<T> element)
		{
			for (Pointer<Object> el : data)
			{
				if ((T*)el.getValue() == (T*)element.getValue())
					return true;
			}
			return false;
		}
		virtual int size()
		{
			return (int)data.size();
		}
		virtual Pointer<Iterator> iterator()
		{
			return new Itr(data);
		}
		virtual Pointer<JavaArray<T>> toArray(Pointer<JavaArray<T>> array)
		{
			for (int i = 0; i < array->length; i++)
			{
				array->assign(i, (T*)data[i].getValue());
			}
			return array;
		}
		virtual void clear()
		{
			for (int i = 0; i < data.size(); i++)
				data[i] = nullptr;
			data.clear();
		}
	private:
		std::vector<Pointer<Object>> data;
	};
}
