#pragma once

// We allocate stuff in this header code so let's set up new debugging right here
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace java::lang
{
	class Class;
	class Object;
	class String;

	template<class T>
	class Pointer
	{
		template<class T> friend class JavaArray;
	public:
		Pointer()
		{
			pointer = nullptr;
			//		TRACE("Pointer::ctor(%p): pointer = %p\n", this, pointer);
		}
		Pointer(T* data)
		{
			pointer = nullptr;
			//		TRACE("Pointer::Pointer(%p): pointer = %p\n", this, pointer);
			assign(data);
		}
		Pointer(const Pointer<T>& other)
		{
			pointer = nullptr;
			assign((T*)other.pointer);
		}
		void operator = (const Pointer<T>& other)
		{
			assign((T*)other.pointer);
		}
		~Pointer()
		{
			//		TRACE("Pointer::dtor(%p): pointer = %p\n", this, pointer);
			assign(nullptr);
		}
		// This operator must be part of Pointer even if it is expected to be applied
		// to JavaArray that is wrapped as Pointer<JavaArray>
		Pointer<T>& operator [] (int index)
		{
			//TRACE("Object %p Type: %s\n", this, typeid(*pointer).name());
			ASSERT(strncmp(typeid(*pointer).name(), "class java::lang::JavaArray<", 28) == 0);
			JavaArray<T>* array = (JavaArray<T>*)pointer;
			return array->data[index];
		}
		void operator = (Object* object)
		{
			//if (pointer)
			//	TRACE("Object %p %s Type: %s\n", this, typeid(this).name(), typeid(*pointer).name());
			//else
			//	TRACE("Object %p %s Type: nullptr\n", this, typeid(this).name());
			assign((T*)object);
		}
		T* operator -> ()
		{
			return (T*)pointer;
		}
		//	bool operator == (Object* value) const
		//	{
		//		return pointer == value;
		//	}
		// This operator is totally useless for anything other than supporting map indexing.
		virtual bool operator < (const Pointer<T>& other) const
		{
			return getValue() < other.getValue();
		}
		virtual bool operator != (const Pointer<T>& other)
		{
			return getValue() != other.getValue();
		}
		// This one is for cases where we need to access a Pointer<class> and class can be
		// upcast but pointer doesn't allow upcasting. Converter will have to take care of
		// it explicitly some day...
		T* getValue() const
		{
			return (T*)pointer;
		}
	private:
		void assign(T* data)
		{
			if (pointer)
			{
				pointer->usageCounter--;
				//TRACE("Pointer::assign(%p): decrement pointer = %p value = %d\n", this, pointer, pointer->usageCounter);
				ASSERT(pointer->usageCounter >= 0);
				if (pointer->usageCounter == 0)
					delete pointer;
			}
			pointer = (Object*)data;
			if (pointer)
			{
				pointer->usageCounter++;
				//TRACE("Pointer::assign(%p): increment pointer = %p value = %d\n", this, pointer, pointer->usageCounter);
			}
		}
		Object* pointer;
	};

	Pointer<String> createString(const char* string);

	class Object
	{
		// https://stackoverflow.com/questions/3736350/how-to-declare-a-template-class-as-a-friend-in-c
		template<class T> friend class Pointer;

	public:
		static Pointer<Class> __thisClassStatic;

	public:
		Object()
		{
			usageCounter = 0;
			//		TRACE("Object::Object(%p)\n", this);
		}
		virtual ~Object()
		{
			ASSERT(usageCounter == 0);
			//		TRACE("Object::~Object(%p)\n", this);
		}
		static void __ClassInit();
		//	virtual int hashCode()
		//	{
		//		return (int)(size_t)this;
		//	}
		//	//virtual bool equals(Object *other);
		//	virtual Pointer<String> toString();
		Pointer<Class> getClass()
		{
			return __thisClass;
		}
		virtual void checkCast(Pointer<Class> clazz)
		{
			//TODO throw new std::exception("CheckCast not implemented");
		}
		bool instanceOf(Pointer<Class> clazz);
		virtual bool operator < (Object* other) const
		{
			return false;
		}
		virtual Pointer<String> toString()
		{
			std::string result = "Object";
			// TODO
			return createString(result.c_str());
		}
		void Trace(const std::string& name, const std::string& file, int line)
		{
			std::cout << "Object \"" << name << "\" at " << this;
			if (this)
				std::cout << " Usage " << usageCounter;
			std::cout << "\n";
		}
	protected:
		Pointer<Class> __thisClass;
		//private:
	public:
		int usageCounter;
	};

	template<class T>
	class JavaArray : public Object
	{
		template<class T> friend class Pointer;
	public:
		JavaArray(int length)
		{
			this->length = length;
			//		TRACE("JavaArray::ctor(%p) data %p\n", this, data);
			data.resize(length);
		}
		~JavaArray()
		{
			//		TRACE("JavaArray::dtor(%p) data %p\n", this, data);
		}
		void assignString(int index, const char* value)
		{
			data[index] = new String(value);
		}
		void assign(int index, Pointer<T> value)
		{
			data[index] = value;
		}
		Pointer<T> get(int index)
		{
			ASSERT(index >= 0 && index < length);
			return data[index];
		}
		int length;
		void Trace(const std::string& name, const std::string& file, int line)
		{
			std::cout << "JavaArray \"" << name << "\" at " << this;
			if (this)
				std::cout << " Usage " << usageCounter;
			std::cout << "\n";
			if (this)
			{
				for (int i = 0; i < length; i++)
				{
					Pointer<T> element = get(i);
					std::cout << "\tElement[" << i << "] at " << element.getValue();
					if (element.getValue())
						std::cout << " Usage " << element->usageCounter;
					std::cout << "\n";
				}
			}
		}
	private:
		std::vector<Pointer<T>> data;
	};

	template<typename T> class JavaRawArray : public Object
	{
	public:
		JavaRawArray(int size)
		{
			length = size;
			data.resize(size);
		}
		void assign(int index, T value)
		{
			data[index] = value;
		}
		T get(int index)
		{
			return data[index];
		}
		int length;
		std::vector<T>& getData()
		{
			return data;
		}
	private:
		std::vector<T> data;
	};

}

#define TRACE_ARRAY(var) var->Trace(#var, __FILE__, __LINE__)
#define TRACE_OBJECT(var) var->Trace(#var, __FILE__, __LINE__)
