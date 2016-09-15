#include "First_Names.hpp"


void 
First_Names::insert( string s )
{
    fn.insert( s );
}


multiset<string>::iterator
First_Names::begin()
{
    return( fn.begin() );
}


multiset<string>::iterator
First_Names::end()
{
    return( fn.end() );
}
