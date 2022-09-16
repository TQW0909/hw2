#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "util.h"

class movie : public Product
{
	public:
		movie(const std::string category, const std::string name, double price, int qty,
					const std::string isbn, const std::string author);

		// Returns the appropriate keywords that this product should be associated with
		std::set<std::string> keywords() const;

		// Returns a string to display the product info for hits of the search
		std::string displayString() const;

		//Outputs the product info in the database format
		void dump(std::ostream& os) const;


	protected:
		std::string Genre;
		std::string Rating;
};
#endif