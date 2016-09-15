#include "Names.hpp"


void
Names::insert( string last_name, First_Names* fns )
{
    n.insert( make_pair( last_name, fns ) );
}


map<string,First_Names*>::iterator
Names::find( string last_name )
{
    return( n.find( last_name ) );
}


map<string,First_Names*>::iterator
Names::begin()
{
    return( n.begin() );
}



map<string,First_Names*>::iterator
Names::end()
{
    return( n.end() );
}


