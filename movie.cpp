#include <sstream>
#include <iomanip>
#include "movie.h"

using namespace std;

movie::movie(const std::string category, const std::string name, double price, int qty,
						const std::string genre, const std::string rating) :
Product(category, name, price, qty),
Genre(genre),
Rating(rating)
{

}

// Returns the appropriate keywords that this product should be associated with
std::set<std::string> movie::keywords() const
{
	set<string> temp = parseStringToWords(name_);
	temp.insert(Genre);
	temp.insert(Rating);

	return temp;
}

// Returns a string to display the product info for hits of the search
std::string movie::displayString() const
{
	string temp = "";

	// Line 1
	temp += name_ + "\n";

	// Line 2
	temp += "Genre: " + Genre + " Rating: " + Rating + "\n";

	// Line 3
	temp += to_string(price_);
	temp += " " + to_string(qty_) + " left." + "\n";

	return temp;
}

// Outputs the movie info in the database format
void movie::dump(std::ostream& os) const
{
	// category-specific-info
	os << Genre << endl;	
	os << Rating << endl;	
}