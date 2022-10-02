#include "mydatastore.h"

using namespace std;

MyDataStore::~MyDataStore() 
{ 
	for(map<string, Product*>::iterator it = MyProduct.begin(); it != MyProduct.end(); ++it) 
	{
    delete it->second;
	}
	for(map<string, User*>::iterator it = MyUsers.begin(); it != MyUsers.end(); ++it) 
	{
    delete it->second;
	}
}

// Adds a product to the data store
void MyDataStore::addProduct(Product* p)
{
	MyProduct.insert(make_pair(p->getName(), p));
}

// Adds a user to the data store
void MyDataStore::addUser(User* u)
{
	MyUsers.insert(make_pair(u->getName(), u));
}

// Adds a user's cart to the data store
void MyDataStore::addCart(std::string username, std::vector<Product*> cart)
{
	MyCart.insert(make_pair(username, cart));
}

// Adds a product to a user's cart
void MyDataStore::addProductToCart(std::string username, Product* p)
{
	map<string, vector<Product*>>::iterator it = MyCart.find(username);

	// Checking if username's cart exists
	if (it == MyCart.end())
	{
		vector<Product*> temp;
		temp.push_back(p);
		this->addCart(username, temp);
	}
	else
	{
		(it->second).push_back(p);
	}
}

// Return a vector of all Poducts in a user's cart
std::vector<Product*> MyDataStore::viewCart(std::string username)
{
	map<string, vector<Product*>>::iterator it = MyCart.find(username);
	if (it == MyCart.end())
	{
		cout << "Empty Cart" << endl;
		vector<Product*> temp;
		return temp;
	}
	return it->second;
}

// Follows the buy instructions for a user's cart
void MyDataStore::buyCart(std::string username)
{
	map<string, vector<Product*>>::iterator it = MyCart.find(username);
	vector<Product*> temp;

	// Goes through every item in the user's cart
	for (vector<Product*>::iterator it1 = (it->second).begin(); it1 != (it->second).end(); ++it1)
	{
		double balance = (MyUsers.find(username))->second->getBalance();
		double price = (*it1)->getPrice();
		int quantity = (*it1)->getQty();

		// Checking if item could be 'bought'
		if (balance >= price && quantity !=0)
		{
			(*it1)->subtractQty(1);
			(MyUsers.find(username))->second->deductAmount(price);
		}
		else
		{
			temp.push_back(*it1);
		}
	}
	it->second = temp;
}


// Performs a search of products whose keywords match the given "terms"
// type 0 = AND search (intersection of results for each term) while
// type 1 = OR search (union of results for each term)
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
	vector<Product*> products;

	if ((type != 0 && type != 1) || terms.empty())
	{
		cout << "INCORRECT TYPE" << endl;
		return products;
	}

	// Having all the search term added to one set
	set<string> termSet;
	for (vector<string>::iterator it = terms.begin(); it != terms.end(); ++it)
	{
		set<string> temp = parseStringToWords(*it);
		termSet = setUnion<string>(termSet, temp);
	}


	// Looping through each product in our data store
	for (map<string, Product*>::iterator i = MyProduct.begin(); i != MyProduct.end(); ++i)
	{
		// Obtaining the set of keyword associated with the product
		set<string> productSet = i->second->keywords();
			
		set<string> results;

		if (type == 0) // AND
		{
			results = setIntersection<string>(productSet, termSet);
			if (results == termSet)
			{
				products.push_back(i->second);
			}
		}
		else if (type == 1) // OR
		{
			results = setIntersection<string>(productSet, termSet);
			if (!results.empty())
			{
				products.push_back(i->second);
			}
		}
	}
	return products;
}


// Reproduce the database file from the current Products and User values
void MyDataStore::dump(std::ostream& ofile)
{
	// Checking if products and users are empty
	if (MyProduct.empty() || MyUsers.empty())
	{
		cout << "ERROR: No Users or Products" << endl;
		return;
	}
	
	// Product Data
	ofile << "<products>" << endl;
	for (map<string, Product*>::iterator it = MyProduct.begin(); it != MyProduct.end(); ++it)
	{
		it->second->dump(ofile);
	}
	ofile << "</products>" << endl;

	// User Data
	ofile << "<users>" << endl;
	for (map<string, User*>::iterator it = MyUsers.begin(); it != MyUsers.end(); ++it)
	{
		it->second->dump(ofile);
	}
	ofile << "</users>" << endl;
}

// Returns whether a user exists in the data store
bool MyDataStore::userExist(const std::string username)
{
	return MyUsers.find(username) != MyUsers.end();
}