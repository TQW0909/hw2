#include <sstream>
#include <iomanip>
#include "clothing.h"

using namespace std;

clothing::clothing(const std::string category, const std::string name, double price, int qty,
						const std::string size, const std::string brand) :
Product(category, name, price, qty),
clothingSize(size),
Brand(brand)
{

}

clothing::~clothing()
{
	
}

// Returns the appropriate keywords that this product should be associated with
std::set<std::string> clothing::keywords() const
{
	set<string> temp = parseStringToWords(name_);
	set<string> brand = parseStringToWords(Brand);
	temp = setUnion<string>(temp, brand);

	return temp;
}

// Returns a string to display the product info for hits of the search
std::string clothing::displayString() const
{
	string temp = "";

	// Line 1
	temp += name_ + "\n";

	// Line 2
	temp += "Size: " + clothingSize + " Brand: " + Brand + "\n";

	// Line 3
	temp += to_string(price_);
	temp += " " + to_string(qty_) + " left." + "\n";

	return temp;
}

// Outputs the clothing info in the database format
void clothing::dump(std::ostream& os) const
{
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
	// category-specific-info
	os << clothingSize << endl;	
	os << Brand << endl;	
}