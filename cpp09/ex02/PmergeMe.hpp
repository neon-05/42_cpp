#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

typedef unsigned int uint;

template <typename C>
void fordJhonsonSort( C& arr );

uint jacobsthal( uint n );

#include "PmergeMe.tpp"
#endif