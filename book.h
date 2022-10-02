#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include "util.h"

class book : public Product
{
	public:
		book(const std::string category, const std::string name, double price, int qty,
					const std::string isbn, const std::string author);
		
		~book();

		// Returns the appropriate keywords that this product should be associated with
		std::set<std::string> keywords() const;

		// // Allows for a more detailed search beyond simple keywords
		// bool isMatch(std::vector<std::string>& searchTerms) const;

		// Returns a string to display the product info for hits of the search
		std::string displayString() const;

		//Outputs the product info in the database format
		void dump(std::ostream& os) const;


	protected:
		std::string ISBN;
		std::string Author;
};
#endif