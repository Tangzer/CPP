#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "-- MUTANTSTACK --\n";
		MutantStack<int>	mstack;

		std::cout << std::boolalpha;
		std::cout << "Empty stack ? " << mstack.empty() << std::endl;
		mstack.push(1);
		mstack.push(17);
		std::cout << "Empty stack ? " << mstack.empty() << std::endl;

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << "Mstack iterator\n";
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << "Stack: \n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;

		std::cout << "Mstack const_iterator\n";
		MutantStack<int>::const_iterator c_it = mstack.begin();
		MutantStack<int>::const_iterator c_ite = mstack.end();

		++c_it;
		--c_it;
		std::cout << "Stack: \n";
		while (c_it != c_ite)
		{
			std::cout << *c_it << std::endl;
			++c_it;
		}
		std::cout << std::endl;

		std::cout << "Mstack reverse_iterator\n";
		MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
		MutantStack<int>::reverse_iterator r_ite = mstack.rend();

		++r_it;
		--r_it;
		std::cout << "Stack: \n";
		while (r_it != r_ite)
		{
			std::cout << *r_it << std::endl;
			++r_it;
		}
		std::cout << std::endl;

		std::cout << "Mstack const_reverse_iterator\n";
		MutantStack<int>::const_reverse_iterator cr_it = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator cr_ite = mstack.rend();

		++cr_it;
		--cr_it;
		std::cout << "Stack: \n";
		while (cr_it != cr_ite)
		{
			std::cout << *cr_it << std::endl;
			++cr_it;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-- LIST --\n";
		std::list<int> list;

		std::cout << std::boolalpha;
		std::cout << "Empty stack ? " << list.empty() << std::endl;
		list.push_back(5);
		list.push_back(17);
		std::cout << "Empty stack ? " << list.empty() << std::endl;

		std::cout << "Top: " << list.back() << std::endl;

		list.pop_back();

		std::cout << "Size: " << list.size() << std::endl << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::cout << "list iterator\n";
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;
		std::cout << "Stack: \n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;

		std::cout << "list const_iterator\n";
		std::list<int>::const_iterator c_it = list.begin();
		std::list<int>::const_iterator c_ite = list.end();

		++c_it;
		--c_it;
		std::cout << "Stack: \n";
		while (c_it != c_ite)
		{
			std::cout << *c_it << std::endl;
			++c_it;
		}
		std::cout << std::endl;

		std::cout << "list reverse_iterator\n";
		std::list<int>::reverse_iterator r_it = list.rbegin();
		std::list<int>::reverse_iterator r_ite = list.rend();

		++r_it;
		--r_it;
		std::cout << "Stack: \n";
		while (r_it != r_ite)
		{
			std::cout << *r_it << std::endl;
			++r_it;
		}
		std::cout << std::endl;

		std::cout << "list const_reverse_iterator\n";
		std::list<int>::const_reverse_iterator cr_it = list.rbegin();
		std::list<int>::const_reverse_iterator cr_ite = list.rend();

		++cr_it;
		--cr_it;
		std::cout << "Stack: \n";
		while (cr_it != cr_ite)
		{
			std::cout << *cr_it << std::endl;
			++cr_it;
		}
	}
	return 0;
}