#ifndef __SCORES_HPP__
#define __SCORES_HPP__


#include <set>
#include <string>

#include "Names.hpp"

using namespace std;


class Scores
{
    public:
	/* Constructor */
	Scores()		{}

	void            	insert( string last_name, string first_name, double score );

	void			print( string file_name );

    private:
	map< double, Names* >	m_scores;

};


#endif


