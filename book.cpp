#include <sstream>
#include <iomanip>
#include "book.h"

using namespace std;

book::book(const std::string category, const std::string name, double price, int qty,
						const std::string isbn, const std::string author) :
Product(category, name, price, qty),
ISBN(isbn),
Author(author)
{

}

book::~book()
{

}

// Returns the appropriate keywords that this product should be associated with
std::set<std::string> book::keywords() const
{
	set<string> temp = parseStringToWords(name_);
	temp.insert(ISBN);
	set<string> author = parseStringToWords(Author);
	temp = setUnion<string>(temp, author);

	return temp;
}

// // Allows for a more detailed search beyond simple keywords
// bool book::isMatch(std::vector<std::string>& searchTerms) const
// {
// 	// If nothing in searchTerms, then will return false
// 	if (searchTerms.empty())
// 	{
// 		return false;
// 	}

// 	// Calling keywords() function to get a keyword list
// 	// set<string> tempSet = this.keywords();
	

// 	for (int i = 0; i < (int)searchTerms.size(); i++)
// 	{
// 		if (!(tempSet.in(searchTerms[i])))
// 		{
// 			return false;
// 		}
// 	}
// 	return true;
// }

// Returns a string to display the product info for hits of the search
std::string book::displayString() const
{
	string temp = "";

	// Line 1
	temp += name_ + "\n";

	// Line 2
	temp += "Author: " + Author + " ISBN: " + ISBN + "\n";

	// Line 3
	temp += to_string(price_);
	temp += " " + to_string(qty_) + " left." + "\n";

	return temp;
}

// Outputs the book info in the database format
void book::dump(std::ostream& os) const
{
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
	// category-specific-info
	os << ISBN << endl;	
	os << Author << endl;	
}


