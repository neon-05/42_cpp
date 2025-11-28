#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack( void ): std::stack<T, std::deque<T> >() {}

template<typename T>
MutantStack<T>::MutantStack( const MutantStack& other ): std::stack<T, std::deque<T> >(other) {}

template<typename T>
MutantStack<T>::~MutantStack( void ) {}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=( const MutantStack& other ) { std::stack<T, std::deque<T> >::c = other.c; }

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) { return std::stack<T, std::deque<T> >::c.begin(); }

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) { return std::stack<T, std::deque<T> >::c.end(); }

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin( void ) const { return std::stack<T, std::deque<T> >::c.begin(); }

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end( void ) const { return std::stack<T, std::deque<T> >::c.end(); }
