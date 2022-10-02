## HW 2

	- Name: Tingqi (Ting) Wang
	- Email: twang356@usc.edu

### Programming Problem Notes

 - How we should compile your code (`g++` command or `make` target)
	
	- To compile my amazon.cpp code, just enter 'make clean' then 'make' in the terminal and all files will be compiled
	- To check for memory leak, compile using above instructions then enter 'valgrind --tool=memcheck --leak-check=full ./amazon database.txt'


 - Design decisions you made or other non-trivial choices for your implementation
	
	- I chose to use a std::map to store the products, the users, and the users' carts
	- I chose to use a std::vector to model the users' carts


 - Any additional tests you wrote and what files those exist in

	- UTIL.cpp TEST:
		- IN: UTIL_test.cpp
		- TO COMPILE: 
			g++ -g -Wall -std=c++11 util.cpp UTIL_test.cpp -o UTIL_test
		- TO RUN:
			./UTIL_test
	- NotEnoughMoneyInUserAccount Test:
		- IN: test1.txt
		- To COMPILE:
			NOT REQUIRED
		- TO RUN:
			./amazon test1.txt
	- NotEnoughProduct Test:
		- IN: test2.txt
		- To COMPILE:
			NOT REQUIRED
		- TO RUN:
			./amazon test2.txt


 - Known errors/anything to help us grade (though we will run automated tests,
knowing what features may be broken/missing may help us provide some partial credit)
	
	- My test files do not utilize GTest and just uses simple 'cout' and 'if' statements to test my program as I couldn't figure out how to use GTest.
	- Please ignore the isMatch() function implementation, I thought it was required. I did not remove it because it says that it may be implemented in future projects.
	- I was unable to get the dump() function in the Product class and its children class (book, clothing, and movie) to work properly. When called, dump() will only output the category specific data and not the product data (e.g. name, category...).
	- My program does not check for non-int inputs for index in the 'ADD' command.
