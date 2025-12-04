#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <iostream>
typedef unsigned int uint;

template <typename C>
void fordJhonsonSort( typename C::iterator begin, typename C::iterator end, uint lvl );
uint jacobsthal( uint n );

#include "PmergeMe.tpp"
#endif