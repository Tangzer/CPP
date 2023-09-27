#ifndef HUTANTSTACK_HPP
#define HUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack<T>();
	MutantStack<T>( MutantStack<T> const &other );
	MutantStack<T> &operator=( MutantStack<T> const &other );
	~MutantStack<T>();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator               begin();
	const_iterator         begin() const;
	reverse_iterator       rbegin();
	const_reverse_iterator rbegin() const;
	iterator               end();
	const_iterator         end() const;
	reverse_iterator       rend();
	const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif