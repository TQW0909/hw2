#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
	// Initializing set and variable
	set<std::string> words;
	string temp = "";

	// Checking if rawWords has 2 or more chars
	if (rawWords.size() < 2)
	{
		return words;
	}

	rawWords = convToLower(rawWords); // Converting all into lower case
	rawWords = trim(rawWords); 				// Trimming the rawWord

	// Going through each char of the string and making substrings
	for (int i = 0; i < (int)rawWords.size(); i++)
	{
		// Checking if a punctuation has been reached (i.e. not a letter)
		// (ranWords[i] < 65 && ranWords[i] > 90) 
		if (rawWords[i] < 97 && rawWords[i] > 122)
		{
			// Checking if substring has 2 or more characters
			if (temp.size() >= 2)
			{
				words.insert(temp);
				temp = "";
			}
		}
		else
		{
				temp += rawWords[i];
		}
	}
	return words;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
