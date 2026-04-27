#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

namespace my_vector
{
	template <typename T>
	class Vector
	{
	private:
		size_t m_size = 0;
		size_t m_capacity = 0;

		T* m_arrayData = nullptr;
	public:
		Vector();
		~Vector();
		Vector(const Vector<T>& obj);
		Vector& operator=(const Vector<T>& obj);

		void PushBack(T);
		void Clear();
		size_t size() const;
		size_t Capacity() const;

		T& operator[](const size_t index);
		T& At(const size_t index);

		Vector(Vector<T>&& obj) noexcept;
		Vector& operator=(Vector<T>&& obj) noexcept;

	};
}

// realization

namespace my_vector
{
	template <typename T>
	Vector<T>::Vector()
	{
		
	}

	template <typename T>
	Vector<T>::~Vector()
	{
		delete m_arrayData;
	}

	template <typename T>
	Vector<T>::Vector(const Vector<T>& obj)
	{
		m_size = obj.m_size;
		m_capacity = obj.m_capacity;

		if (m_capacity != 0)
		{
			m_arrayData = new int[m_capacity];
			
			for (size_t i = 0; i < m_size; ++i)
			{
				m_arrayData[i] = obj.m_arrayData[i];
			}
		}
	}

	template <typename T>
	Vector<T>& Vector<T>::operator=(const Vector<T>& obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		
		delete m_arrayData;

		m_size = obj.m_size;
		m_capacity = obj.m_capacity;

		if (m_capacity != 0)
		{
			m_arrayData = new int[m_capacity];

			for (size_t i = 0; i < m_size; ++i)
			{
				m_arrayData[i] = obj.m_arrayData[i];
			}
		}
		else
		{
			m_arrayData = nullptr;
		}

		return *this;
	}

	template <typename T>
	void Vector<T>::PushBack(T element)
	{
		if (m_size == m_capacity)
		{
			m_capacity += 10;

			T* tmp = new T[m_capacity];

			for (size_t i = 0; i < m_size; ++i)
			{
				tmp[i] = m_arrayData[i];
			}

			delete[] m_arrayData;

			m_arrayData = tmp;
		}

		m_arrayData[m_size] = element;
		++m_size;
	}

	template <typename T>
	size_t Vector<T>::size() const
	{
		return m_size;
	}

	template <typename T>
	size_t Vector<T>::Capacity() const
	{
		return m_capacity;
	}

	template <typename T>
	void Vector<T>::Clear()
	{
		/*
		 *delete[] m_arrayData;
		 *m_arrayData = nullptr;
		 *m_size = m_capacity;
		*/

		m_size = 0;
	}

	template <typename T>
	T& Vector<T>::operator[](const size_t index)
	{
		return m_arrayData[index];
	}

	template <typename T>
	T& Vector<T>::At(const size_t index)
	{
		if (index < m_size)
		{
			return m_arrayData[index];
		}
		else
		{
			throw std::out_of_range("Index out of range");
		}
	}

	template <typename T>
	Vector<T>::Vector(Vector<T>&& obj) noexcept
	{
		m_size = obj.m_size;
		m_capacity = obj.m_capacity;

		if (obj.m_arrayData != nullptr)
		{
			m_arrayData = obj.m_arrayData;
			obj.m_arrayData = nullptr;

			obj.m_size = obj.m_capacity = 0;
		}
	}

	template <typename T>
	Vector<T>& Vector<T>::operator=(Vector<T>&& obj) noexcept
	{
		if (this == &obj)
		{
			return *this;
		}

		m_size = obj.m_size;
		m_capacity = obj.Capacity;

		delete[] m_arrayData;
		m_arrayData = obj.m_arrayData;

		obj.m_arrayData = nullptr;
		m_size = obj.m_capacity = 0;

		return *this;
	}
}

#endif