#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <cctype>
#include <cstring>
#include <iostream>

int process_token( char t, std::stack<int>& s );

#endif