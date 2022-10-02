#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2) // AND
{
	// If one set is empty, intersection will be empty set
	if (s1.empty())
	{
		return s1;
	}
	if (s2.empty())
	{
		return s2;
	}

	// Initializing temp set to be returned
	std::set<T> tempSet;
	
	for (typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it) // Runs in O(n*log(n))
	{
		typename std::set<T>::iterator temp = s2.find(*it); // find() runs in O(log(n))

		// Checking if templates in s1 are also in s2
		if (temp != s2.end()) 
		{
			tempSet.insert(*it);
		}
	}
	return tempSet;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2) // OR
{
	// If one set is empty, union will be the non empty set
	if (s1.empty())
	{
		return s2;
	}
	if (s2.empty())
	{
		return s1;
	}

	// Initializing temp set to be returned
	std::set<T> tempSet = s2;
	
	for (typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it) // Runs in O(n*log(n))
	{
		typename std::set<T>::iterator temp = s2.find(*it); // find() runs in O(log(n))

		// Checking if templates in s1 are also in s2
		if(temp == s2.end())
		{
			tempSet.insert(*it);
		}
	}
	return tempSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
