#include "List.hpp"
#include <list>

/*

all = 0
constructor_test = 1
iterator_test = 2
capacity_test = 3
element_access_test = 4
modifiers_test = 5

*/
#ifndef TEST
# define TEST 0
#endif

template < class T >
void describe_list(std::list<T> lst, std::string name)
{
	int i = 0;
	std::cout << name << " :" << std::endl;
	if (lst.empty())
		std::cout << "(empty)";
	else
		for (typename std::list<T>::iterator itr = lst.begin(); itr != lst.end(); itr++)
		{
			std::cout << i << ":[" << *itr << "] ";
			i++;
		}
	std::cout << std::endl;
}

template < class T >
void describe_list(ft::List<T> lst, std::string name)
{
	int i = 0;
	std::cout << name << " :" << std::endl;
	if (lst.empty())
		std::cout << "(empty)";
	else
		for (typename ft::List<T>::iterator itr = lst.begin(); itr != lst.end(); itr++)
		{
			std::cout << i << ":[" << *itr << "] ";
			i++;
		}
	std::cout << std::endl;
}

template < class T >
void describe_list(std::list<T> std_lst, std::string std_name, ft::List<T> ft_lst, std::string ft_name)
{
	describe_list(std_lst, std_name);
	describe_list(ft_lst, ft_name);
	std::cout << std::endl;
}

void constructor_test(int size)
{
	std::cout << "Constructor size(" << size << ")" << std::endl;
// default constructor
	std::list<int> std_lst;
	ft::List<int> ft_lst;
	describe_list(std_lst, "std_list", ft_lst, "ft_lst");

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}
	describe_list(std_lst, "std_list", ft_lst, "ft_lst");

// fill constructor
	std::list<int> std_lst_fill(size);
	ft::List<int> ft_lst_fill(size);
	describe_list(std_lst_fill, "std_lst_fill", ft_lst_fill, "ft_lst_fill");

	// ====================================================================== BAD CONSTRUCTOR CALLED
	// std_lst_fill = std::list<int>(size, 5);
	// ft_lst_fill = ft::List<int>(size, 5);
	// describe_list(std_lst_fill, "std_lst_fill", ft_lst_fill, "ft_lst_fill");
	// TODO ========================================================================================

// range constructor
	std::list<int> std_lst_range(std_lst.begin(), std_lst.end());
	ft::List<int> ft_lst_range(ft_lst.begin(), ft_lst.end());
	describe_list(std_lst_range, "std_lst_range", ft_lst_range, "ft_lst_range");

// copy constructor
	std::list<int> std_lst_copy(std_lst);
	ft::List<int> ft_lst_copy(ft_lst);
	describe_list(std_lst_copy, "std_lst_copy", ft_lst_copy, "ft_lst_copy");


// assignment constructor
	std::list<int> std_lst_assignment;
	ft::List<int> ft_lst_assignment;
	std_lst_assignment = std_lst_range;
	ft_lst_assignment = ft_lst_range;
	describe_list(std_lst_assignment, "std_lst_assignment", ft_lst_assignment, "ft_lst_assignment");

	std::cout << "=========================" << std::endl;
}

void iterator_test(int size)
{
	std::cout << "Iterator size(" << size << ")" << std::endl;
	std::list<int> std_lst;
	std::list<int> ft_lst;

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

// iterators
	std::cout << "STD Iterator: " << std::endl;
	for (std::list<int>::iterator itr = std_lst.begin(); itr != std_lst.end(); itr++)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl << "FT Iterator: " << std::endl;
	for (std::list<int>::iterator itr = ft_lst.begin(); itr != ft_lst.end(); itr++)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl << std::endl;

// const_iterators
	std::cout << "STD Const Iterator: " << std::endl;
	for (std::list<int>::const_iterator itr = std_lst.begin(); itr != std_lst.end(); itr++)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl << "STD Const Iterator: " << std::endl;
	for (std::list<int>::const_iterator itr = ft_lst.begin(); itr != ft_lst.end(); itr++)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl << std::endl;

// reverse_iterators
	std::cout << "STD Reverse Iterator: " << std::endl;
	for (std::list<int>::reverse_iterator itr = std_lst.rbegin(); itr != std_lst.rend(); itr++)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl << "FT Reverse Iterator: " << std::endl;
	for (std::list<int>::reverse_iterator itr = ft_lst.rbegin(); itr != ft_lst.rend(); itr++)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl << std::endl;

// const_reverse_iterator
	std::cout << "STD Const Reverse Iterator: " << std::endl;
	for (std::list<int>::const_reverse_iterator itr = std_lst.rbegin(); itr != std_lst.rend(); itr++)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl << "FT Const Reverse Iterator: " << std::endl;
	for (std::list<int>::const_reverse_iterator itr = ft_lst.rbegin(); itr != ft_lst.rend(); itr++)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl;

	std::cout << "=========================" << std::endl;
}

void capacity_test(int size)
{
	std::cout << "Capacity size(" << size << ")" << std::endl;
	std::list<int> std_lst;
	std::list<int> ft_lst;

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

// capacity
	std::cout << "STD size : " << std_lst.size() << std::endl;
	std::cout << "FT size : " << ft_lst.size() << std::endl << std::endl;

	std::cout << "STD max_size : " << std_lst.max_size() << std::endl;
	std::cout << "FT max_size : " << ft_lst.max_size() << std::endl << std::endl;

	std::cout << "STD empty : " << std_lst.empty() << std::endl;
	std::cout << "FT empty : " << ft_lst.empty() << std::endl;

	std::cout << "=========================" << std::endl;
}

void element_access_test(int size)
{
	std::cout << "Element_access size(" << size << ")" << std::endl;
	std::list<int> std_lst;
	std::list<int> ft_lst;

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

// element access
	std::cout << "STD front : " << std_lst.front() << std::endl;
	std::cout << "FT front : " << ft_lst.front() << std::endl << std::endl;

	std::cout << "STD back : " << std_lst.back() << std::endl;
	std::cout << "FT back : " << ft_lst.back() << std::endl;

	std::cout << "=========================" << std::endl;
}

void modifiers_test(int size)
{
	std::cout << "Modifiers size(" << size << ")" << std::endl;

	std::list<int> std_lst;
	ft::List<int> ft_lst;

	// ====================================================================== BAD ASSIGN CALLED
	// std_lst.assign(size, size);
	// ft_lst.assign(size, size);
	// std::cout << "assign(" << size << ":" << size << ")" << std::endl;
	// describe_list(std_lst, "std_lst", ft_lst, "ft_lst");
	// TODO ==========================================================================================

	std_lst = std::list<int>(size);
	ft_lst = ft::List<int>(size);
	describe_list(std_lst, "std_lst", ft_lst, "ft_lst");
	std::list<int> std_lst_assign;
	ft::List<int> ft_lst_assign;
	std_lst_assign.assign(std_lst.begin(), std_lst.end());
	ft_lst_assign.assign(ft_lst.begin(), ft_lst.end());
	std::cout << "assign from iterator :" << std::endl;
	describe_list(std_lst_assign, "std_lst_assign", ft_lst_assign, "ft_lst_assign");

	std::list<int> std_lst_back;
	ft::List<int> ft_lst_back;
	for (int i = 0; i < size; i++)
	{
		std_lst_back.push_back(i);
		ft_lst_back.push_back(i);
	}
	describe_list(std_lst_back, "std_lst_back", ft_lst_back, "ft_lst_back");

	std::list<int> std_lst_front;
	ft::List<int> ft_lst_front;
	for (int i = 1; i < size; i++)
	{
		std_lst_front.push_front(i);
		ft_lst_front.push_front(i);
	}
	describe_list(std_lst_front, "std_lst_front", ft_lst_front, "ft_lst_front");
	
	// std::cout << "pop_back :" << std::endl;
	// while (!std_lst.empty() && !ft_lst.empty())
	// {
	// 	std_lst.pop_back();
	// 	ft_lst.pop_back();
	// 	describe_list(std_lst, "std_lst", ft_lst, "ft_lst");
	// }

	// std::cout << "pop_front :" << std::endl;
	// while (!std_lst_assign.empty() && !ft_lst_assign.empty())
	// {
	// 	std_lst_assign.pop_front();
	// 	ft_lst_assign.pop_front();
	// 	describe_list(std_lst_assign, "std_lst", ft_lst_assign, "ft_lst");
	// }

	// ====================================================================== PUSH_FRONT
	// Error: Code commente au dessus
	// TODO ==========================================================================================

}

int main()
{

#if TEST == 0 || TEST == 1

	// constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);

#endif
#if TEST == 0 || TEST == 2

	// iterator_test(1000); // OK Sur linux (juste chiant a afficher)
	iterator_test(10);
	iterator_test(5);
	iterator_test(2);
	iterator_test(1);
	iterator_test(0);

#endif
#if TEST == 0 || TEST == 3

	// capacity_test(1000); // OK Sur linux (juste chiant a afficher)
	capacity_test(10);
	capacity_test(5);
	capacity_test(2);
	capacity_test(1);
	capacity_test(0);

#endif
#if TEST == 0 || TEST == 4

	// element_access_test(1000); // OK Sur linux (juste chiant a afficher)
	element_access_test(10);
	element_access_test(5);
	element_access_test(2);
	element_access_test(1);
	element_access_test(0);

#endif
#if TEST == 0 || TEST == 5

	// modifiers_test(1000); // OK Sur linux (juste chiant a afficher)
	modifiers_test(10);
	modifiers_test(5);
	modifiers_test(2);
	modifiers_test(1);
	modifiers_test(0);

#endif

	/*
	std::cout << "INT TESTS" << std::endl;
	ft::List<int> testint;
	testint.push_back(2);
	testint.push_back(1);
	testint.push_back(3);
	std::list<int> testint_base;
	testint_base.push_back(2);
	testint_base.push_back(1);
	testint_base.push_back(4);

	//testint.clear();
	//test erase END
	std::cout << "sizeTest base --> " << testint_base.max_size() << std::endl;
	std::cout << "sizeTest new  --> " << testint.max_size() << std::endl;
	testint_base.assign(testint_base.begin(), testint_base.end());
	testint.assign(testint_base.begin(), testint_base.end());
	std::cout<< "ft::List front()  --> " << testint.front() << std::endl;
	std::cout<< "std::list front() --> " << testint_base.front() << std::endl;
	std::cout<< "ft::List back()  --> " << testint.back() << std::endl;
	std::cout<< "std::list back() --> " << testint_base.back() << std::endl;
	std::cout<< "ft::List begin()  --> " << *(testint.begin()) << std::endl;
	std::cout<< "std::list begin() --> " << *(testint_base.begin()) << std::endl;

	std::cout << std::endl << "STRING TESTS" << std::endl;
	ft::List<std::string> teststring;
	teststring.push_back("string_1");
	teststring.push_back("string_2");
	teststring.push_back("string_3");
	std::list<std::string> teststring_base;
	teststring_base.push_back("string_1");
	teststring_base.push_back("string_2");
	teststring_base.push_back("string_4");

	teststring_base.insert(teststring_base.begin(), "ble");
	std::cout << "Base" << std::endl;
	teststring_base.assign(teststring_base.begin(), teststring_base.end());
	std::cout << "Mine" << std::endl;
	teststring.assign(teststring_base.begin(), teststring_base.end());
	std::cout<< "ft::List front()  --> " << teststring.front() << std::endl;
	std::cout<< "std::list front() --> " << teststring_base.front() << std::endl;
	std::cout<< "ft::List back()  --> " << teststring.back() << std::endl;
	std::cout<< "std::list back() --> " << teststring_base.back() << std::endl;
	std::cout<< "ft::List begin()  --> " << *(++teststring.begin()) << std::endl;
	std::cout<< "std::list begin() --> " << *(++teststring_base.begin()) << std::endl;
	std::cout<< "ft::List --end()  --> " << *(--teststring.end()) << std::endl;
	std::cout<< "std::List --end() --> " << *(--teststring_base.end()) << std::endl;
	std::cout<< "ft::List rbegin()  --> " << *(teststring.rbegin()) << std::endl;
	std::cout<< "std::List rbegin() --> " << *(teststring_base.rbegin()) << std::endl;
	std::cout<< "ft::List --rend()  --> " << *(--teststring.rend()) << std::endl;
	std::cout<< "std::List --rend() --> " << *(--teststring_base.rend()) << std::endl;


	std::cout << "SORT TESTS" << std::endl;
	std::cout<< "ft::List front()  --> " << testint.front() << std::endl;
	std::cout<< "std::list front()  --> " << testint_base.front() << std::endl;
	testint.sort();
	testint_base.sort();
	std::cout<< "ft::List front()  --> " << testint.front() << std::endl;
	std::cout<< "std::list front()  --> " << testint_base.front() << std::endl;


	std::cout << "ERASE / CLEAR TESTS" << std::endl;
	std::cout << "erase begin val = " << testint.front() << std::endl;
	testint.erase(testint.begin());
	testint.erase(testint.begin());
	testint.erase(testint.begin());
	std::cout << "erase from begin to end - 1" << std::endl;
	testint.erase(testint.begin(), --testint.end());
	std::cout << "clear" << std::endl;
	testint.clear();
	std::cout << "clear on cleared list" << std::endl;
	testint.clear();*/
}