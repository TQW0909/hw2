#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <map>
#include <queue>
#include "datastore.h"
#include "util.h"
#include "product.h"
#include "user.h"


class MyDataStore : public DataStore
{
	public:
		~MyDataStore();

		// Adds a product to the data store
		void addProduct(Product* p);

		// Adds a user to the data store
		void addUser(User* u);

		// Adding user cart
		void addCart(std::string username, std::vector<Product*> cart);

		// Adding to a users cart
		void addProductToCart(std::string username, Product* p);

		// Returns a vector of Products in the user's cart
		std::vector<Product*> viewCart(std::string username);

		// Buys all items in the cart
		void buyCart(std::string username);

		// Performs a search of products whose keywords match the given "terms"
    // type 0 = AND search (intersection of results for each term) while
    // type 1 = OR search (union of results for each term)
		std::vector<Product*> search(std::vector<std::string>& terms, int type);

		// Reproduce the database file from the current Products and User values
		void dump(std::ostream& ofile);

		// Returns whether user exists
		bool userExist(const std::string username);

	private:
		std::map<std::string, User*> MyUsers;
		std::map<std::string, Product*> MyProduct;
		std::map<std::string, std::vector<Product*>> MyCart;

};
#endif