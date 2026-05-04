#include "../include/UniquePtr.hpp"
#include "../include/A.hpp"

#include <iostream>
#include <memory>


int main()
{
	// std::unique_ptr<int> upPtr(new int(100));

	/*std::unique_ptr<A> upPtr(new A);
	 *
	 *std::unique_ptr<A> upPtr2(upPtr.release());
	 *
	 *upPtr = std::move(upPtr2);
	 *
	 *upPtr2->Test();
	 *
	 *
	 *{
	 *	std::unique_ptr<A> upPtr(new A[10]);
	 *}
	 */

	smart_pointers::UniquePtr<A> p1(new A);
	p1.Get()->Test();

	smart_pointers::UniquePtr<A> p2(std::move(p1));

	if (p1.Get() == nullptr)
	{
		std::cout << "p1 is empty\n";
	}

	if (p2.Get())
	{
		p2.Get()->Test();
	}

	smart_pointers::UniquePtr<A> p3(new A);
	p2.Swap(p3);

	if (p2.Get())
	{
		p2.Get()->Test();
	}

	if (p3.Get())
	{
		p3.Get()->Test();
	}

	A* raw = p3.Release();
	if (p3.Get() == nullptr)
		std::cout << "p3 released ownership\n";

	delete raw;
	
	
	return 0;
}
