#include "main.hpp"

/* -----------------------------------------------------------------------------------------------
 * Main Function
 * -----------------------------------------------------------------------------------------------
 */
int main( int argc, char* argv[] )
{
    /* Check arguments of the program */
    if ( argc < 2 ) {
	cerr << argv[0] << ": no input file" << endl;
	cerr << "Usage: " << argv[0] << " input_file_name" << endl;
	exit(0);
    }
    else if ( argc > 2 ) {
	cerr << "Usage: " << argv[0] << " input_file_name" << endl;
	exit(0);
    }

    string	  input_file_name;
    stringstream  str_stream;

    /* Convert char* to string */
    str_stream << argv[1];
    str_stream >> input_file_name;

    ifstream ifst( input_file_name.c_str() );

    if (!ifst) {
        cerr << "ERROR: Cannot open the input file \"" << input_file_name << "\" !" << endl;
        exit(1);
    } 

    string  str_line;
    string  last_name, first_name, score;

    Scores  all_scores;

    /* Read a line from the input file */
    while ( getline( ifst, str_line ) ) 
    {
 	str_line = trim( str_line );

	if ( str_line == "" ) {
	    /* ignore the blank line */
	    continue;
 	}

	/* DEBUG */
	//cout << "str_line: " << str_line << endl;

	size_t pos1 = str_line.find_first_of(",");
	
	/* DEBUG */
	//cout << "pos1 = " << pos1 << endl;

	last_name = trim( str_line.substr( 0, pos1 ) );

	/* DEBUG */
	//cout << "  last_name = \"" << last_name << "\"" << endl;

	str_line = trim( str_line.substr( pos1+1 ) );

	/* DEBUG */
	//cout << "  str_line: " << str_line << endl;

	size_t pos2 = str_line.find_first_of(",");

	first_name = trim( str_line.substr( 0, pos2 ) );
	
	/* DEBUG */
	//cout << "  first_name = \"" << first_name << "\"" << endl;

	//str_line = trim( str_line.substr( pos2+1 ) );

	score = trim( str_line.substr( pos2+1 ) );

	/* DEBUG */
	//cout << "  score = \"" << score << "\"" << endl;
	
	/* Insert data */
	all_scores.insert( last_name, first_name, string2double( score ) );
    }

    size_t pos = input_file_name.find_last_of(".");
    string file_name;
    if ( pos == string::npos ) {
	file_name = input_file_name;	
    }
    else {
        file_name = trim( input_file_name.substr( 0, input_file_name.find_last_of(".") ) );
    }

    /* DEBUG */
    //cout << "file_name = " << output_file_name << endl;

    all_scores.print( file_name );

}  /* END of main() */


double
string2double( const string &str ) 
{
    double number;
    istringstream(str)>>number ;
    return number;
}


inline string 
trim_right( const string & s )
{
    const string & t = SPACES;
    string d (s);
    string::size_type i (d.find_last_not_of (t));
    if (i == string::npos)
        return "";
    else
        return d.erase (d.find_last_not_of (t) + 1) ;
}  


inline string 
trim_left (const string & s )
{
    const string & t = SPACES;
    string d (s);
    return d.erase (0, s.find_first_not_of (t)) ;
}  


inline string 
trim (const string & s )
{
    string d (s);
    return trim_left( trim_right (d) ) ;
}  


