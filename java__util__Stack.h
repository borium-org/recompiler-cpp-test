#pragma once

//using namespace java::lang;

namespace java::util
{
	template<class T>
	class Stack
	{
	public:
		void push(Pointer<T> object)
		{
			data.push_back(object);
		}
		Pointer<T> pop()
		{
			Pointer<T> top = data.back();
			data.pop_back();
			return top;
		}
		////		virtual bool add(Pointer<T> element) = 0;
		virtual Pointer<T> elementAt(int index)
		{
			return data[data.size() - 1 - index];
		}
		virtual int size()
		{
			return (int)data.size();
		}
		virtual Pointer<T> firstElement()
		{
			return data.back();
		}
		////		virtual bool contains(Pointer<T> element) = 0;
		////		virtual Pointer<Iterator<T>> iterator() = 0;
	private:
		std::vector<Pointer<T>> data;
	};
}
