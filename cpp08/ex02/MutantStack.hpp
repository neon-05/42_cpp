#ifndef NUTANTSTACK_HPP
#define NUTANTSTACK_HPP
#include <stack>

template<typename T>
class MutantStack: public std::stack<T, std::deque<T> >
{
public:
	typedef typename MutantStack::container_type::iterator iterator;
	typedef typename MutantStack::container_type::const_iterator const_iterator;
	MutantStack( void );
	MutantStack( const MutantStack& );
	~MutantStack( void );
	MutantStack&	operator=( const MutantStack& );

	iterator	begin( void );
	iterator	end( void );

	const_iterator	begin( void ) const;
	const_iterator	end( void ) const;
};

#include "MutantStack.tpp"
#endif