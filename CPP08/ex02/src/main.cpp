/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:21:49 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/05 18:51:00 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		// Test1
		std::cout << "Test 1: " << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}

		std::stack<int> s(mstack);
	}

	{
		// Test2
		MutantStack<int> mstack;

		mstack.push(20);
		mstack.push(10);
		mstack.push(30);

		std::cout << "\n\nTest 2: " << std::endl;
		MutantStack<int>::iterator it;
		for (it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		std::cout << "List: " << std::endl;
		std::list<int> lst;
		lst.push_back(20);
		lst.push_back(10);
		lst.push_back(30);

		std::list<int>::iterator lst_it;
		for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it)
			std::cout << *lst_it << std::endl;
	}

	return 0;
}
