#ifndef SMART_SHARED_PTR
#define SMART_SHARED_PTR

#include <iostream>

namespace smart_shared_ptr
{
	template <class T>
	class SharedPtr
	{
	private:
		T* m_pMemory = nullptr;
		size_t* m_pSizeCounter = nullptr;

	public:
		SharedPtr() = default;
		explicit SharedPtr(T* obj) : m_pMemory(obj)
		{
			if (obj)
			{
				m_pSizeCounter = new size_t(1);
			}
		}

		SharedPtr(const SharedPtr<T>& obj)
		{
			m_pMemory = obj.m_pMemory;
			m_pSizeCounter = obj.m_pSizeCounter;

			if (m_pSizeCounter)
			{
				++(*m_pSizeCounter);
			}
		}

		SharedPtr(SharedPtr<T>&& obj)
		{
			m_pMemory = obj.m_pMemory;
			m_pSizeCounter = obj.m_pSizeCounter;

			obj.m_pMemory = obj.m_pSizeCounter = nullptr;
		}

		SharedPtr& operator=(const SharedPtr& obj)
		{
			if (this == &obj)
			{
				return *this;
			}

			if (m_pSizeCounter)
			{
				--(*m_pSizeCounter);
				if (*m_pSizeCounter == 0)
				{
					delete m_pMemory;
					delete m_pSizeCounter;
				}
			}

			m_pMemory = obj.m_pMemory;
			m_pSizeCounter = obj.m_pSizeCounter;

			if (m_pSizeCounter)
			{
				++(*m_pSizeCounter);
			}

			return *this;
		}

		SharedPtr<T>& operator=(SharedPtr<T>&& obj)
		{
			if (this == &obj)
			{
				return *this;
			}

			if (m_pSizeCounter)
			{
				--(*m_pSizeCounter);

				if (*m_pSizeCounter == 0)
				{
					delete m_pMemory;
					delete m_pSizeCounter;
				}
			}

			m_pMemory = obj.m_pMemory;
			m_pSizeCounter = obj.m_pSizeCounter;

			obj.m_pMemory = obj.m_pSizeCounter = nullptr;

			return *this;
		}


		~SharedPtr()
		{
			if (!m_pSizeCounter)
			{
				return;
			}

			--(*m_pSizeCounter);

			if (*m_pSizeCounter == 0)
			{
				delete m_pMemory;
				delete m_pSizeCounter;
			}
		}

		void Reset(T* value = nullptr)
		{
			if (m_pSizeCounter)
			{
				--(*m_pSizeCounter);

				if (*m_pSizeCounter == 0)
				{
					delete m_pMemory;
					delete m_pSizeCounter;
				}
			}

			m_pMemory = value;

			if (m_pMemory != nullptr)
			{
				m_pSizeCounter = new size_t(1);
			}
			else
			{
				m_pSizeCounter = nullptr;
			}
		}
	};
}

#endif