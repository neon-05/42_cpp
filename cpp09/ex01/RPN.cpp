#include "RPN.hpp"

static int process_number( int n, std::stack<int>& s );
static int process_operator( int op, std::stack<int>& s );

static int	_add( int a, int b );
static int	_sub( int a, int b );
static int	_mul( int a, int b );
static int	_div( int a, int b );

int process_token( char t, std::stack<int>& s )
{
	int op;
	static const char *set = "+-*/";

	if (std::isdigit(t))
		return process_number(t - '0', s);
	op = strchr(set, t) - set;
	if (op >= 0)
		return process_operator(op, s);
	else
		std::cerr << "invalid token: " << t << std::endl;
	return 1;
}

static int process_number( int n, std::stack<int>& s )
{
	s.push(n);
	return 0;
}

static int process_operator( int op, std::stack<int>& s )
{
	static int (*op_f[])(int, int) = {_add, _sub, _mul, _div};
	if (s.size() < 2)
	{
		std::cerr << "not enough elements in the stack to process an operator" << std::endl;
		return 1;
	}
	int a,b;
	b = s.top();
	s.pop();
	a = s.top();
	s.pop();
	s.push(op_f[op](a, b));
	return 0;
}

static int	_add( int a, int b ) { return a + b; }
static int	_sub( int a, int b ) { return a - b; }
static int	_mul( int a, int b ) { return a * b; }
static int	_div( int a, int b ) { return a / b; }
