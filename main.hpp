#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "Scores.hpp"

#define SPACES " \t\r\n"

using namespace std;

double string2double( const string &str );	/* Convert string into double */
inline string trim_right (const string & s );
inline string trim_left (const string & s );
inline string trim (const string & s );

