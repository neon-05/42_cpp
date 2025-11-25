#ifndef NUTANTSTACK_HPP
#define NUTANTSTACK_HPP
#include <stack>

template<typename T>
class MutantStack: public std::stack<T, std::deque<T> >
{
public:
	typedef typename MutantStack::container_type::const_iterator iterator;
	MutantStack( void );
	MutantStack( const MutantStack& );
	~MutantStack( void );
	MutantStack&	operator=( const MutantStack& );

	iterator	begin( void ) const;
	iterator	end( void ) const;
};

#include "MutantStack.tpp"
#endif