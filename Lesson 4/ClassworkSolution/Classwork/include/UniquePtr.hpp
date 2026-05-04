#ifndef UNIQUEPTR_HPP
#define UNIQUEPTR_HPP

namespace smart_pointers
{
	template <class T>
	class UniquePtr
	{
	private:
		T* m_ptr = nullptr;
	public:
		explicit UniquePtr(T* address) : m_ptr(address) {}
		UniquePtr() {}

		UniquePtr(const UniquePtr<T>& obj) = delete;
		UniquePtr(UniquePtr<T>&& obj);

		~UniquePtr();
		T* Release();
		void Swap(UniquePtr<T>& obj);
		T* Get() const;
	};
}

namespace smart_pointers
{
	template <class T>
	UniquePtr<T>::UniquePtr(UniquePtr<T>&& obj)
	{
		m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
	}

	template <class T>
	UniquePtr<T>::~UniquePtr()
	{
		delete m_ptr;
	}

	template <class T>
	T* UniquePtr<T>::Release()
	{
		T* temp = m_ptr;
		m_ptr = nullptr;
		return temp;
	}

	template <class T>
	void UniquePtr<T>::Swap(UniquePtr<T>& obj)
	{
		//std::swap(m_ptr, obj.m_ptr);

		T* temp = m_ptr;
		m_ptr = obj.m_ptr;
		obj.m_ptr = temp;
	}

	template <class T>
	T* UniquePtr<T>::Get() const
	{
		return m_ptr;
	}
}


#endif
