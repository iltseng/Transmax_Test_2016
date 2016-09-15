#ifndef __NAMES_HPP__
#define __NAMES_HPP__


#include <map>
#include <string>
#include "First_Names.hpp"

using namespace std;


class Names
{
    public:
	/* Constructor */
	Names()					{}

	void	insert( string last_name, First_Names* fns );

	map<string,First_Names*>::iterator
		find( string last_name );

	map<string,First_Names*>::iterator
		begin();

	map<string,First_Names*>::iterator
		end();

    private:
	map< string, First_Names* >		n;	
						/* Key:  Last Name
					 	 * Data: First Name(s) 
					 	 */
};


#endif


