#ifndef __FIRST_NAMES_HPP__
#define __FIRST_NAMES_HPP__


#include <set>
#include <string>

using namespace std;


class First_Names
{
    public:
	/* Constructor */
	First_Names()		{}

	void	insert( string s );

	multiset<string>::iterator
		begin();

	multiset<string>::iterator
		end();

    private:
	multiset<string>	fn;

};


#endif


