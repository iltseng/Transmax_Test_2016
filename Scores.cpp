#include <fstream>
#include <iostream>

#include "Scores.hpp"

/* Author:  I-Lun Tseng
 * Description:
 *	Insert data into the data structure
 */
void
Scores::insert( string last_name, string first_name, double score )
{
    /* DEBUG */
    //cout << "    last_name: " << last_name << endl;
    //cout << "    first_name: " << first_name << endl;
    //cout << "    score: " << score << endl;

    /* m_scores is empty */
    if ( m_scores.empty() )
    {
	First_Names* fns = new First_Names();
	fns->insert( first_name );

	Names* ns = new Names();
	ns->insert( last_name, fns );

	m_scores.insert( make_pair( score, ns ) );
    }
    else /* m_scores not empty */
    {
	map<double,Names*>::iterator it_s = m_scores.find( score );

	/* no data found for the score */
	if ( it_s == m_scores.end() )
	{
	    First_Names* fns = new First_Names();
	    fns->insert( first_name );

	    Names* ns = new Names();
	    ns->insert( last_name, fns );

	    m_scores.insert( make_pair( score, ns ) );
	}
	else  /* data found for the score */
	{
	    Names* ns = it_s->second;

	    map<string,First_Names*>::iterator it_ns = ns->find( last_name );

	    /* no data found for the last_name */
	    if ( it_ns == ns->end() )
	    {
		First_Names* fns = new First_Names();
		fns->insert( first_name );

		ns->insert( last_name, fns );
	    }
	    else  /* data found for the last_name */
	    {
	    	First_Names* fns = it_ns->second;

		fns->insert( first_name );
	    }
	}
    }
}  /* END of insert() */


void
Scores::print( string file_name )
{
    string  	 last_name, first_name;
    double  	 score;
    Names*  	 ns;
    First_Names* fns;

    string	 output_file_name = file_name + "-graded.txt";

    ofstream ost( output_file_name.c_str() );

    for ( map<double,Names*>::reverse_iterator rit_s = m_scores.rbegin(); rit_s != m_scores.rend(); ++rit_s )
    {
	score = rit_s->first;
	ns    = rit_s->second;

	for ( map<string,First_Names*>::iterator it_ns = ns->begin(); it_ns != ns->end(); ++it_ns )
	{
	    last_name = it_ns->first;
	    fns       = it_ns->second;

	    for ( multiset<string>::iterator it_fns = fns->begin(); it_fns != fns->end(); ++it_fns )
	    {
		first_name = *it_fns;
		
	    	cout << last_name << ", " << first_name << ", " << score << endl;
	    	ost  << last_name << ", " << first_name << ", " << score << endl;

	    	/* DEBUG - first_name */
	    	//cout << first_name << endl;
	    }

	    /* DEBUG - last_name */
	    //cout << last_name << endl;
	}

	/* DEBUG - score */
	//cout << score << endl;

    }  /* END of for-loop */

    ost.close();
    cout << "Finished: created " << output_file_name << endl;
}


