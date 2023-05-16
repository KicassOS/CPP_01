/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:16:44 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 17:52:18 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>

int	main()
{
	std::string		brain_str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain_str;
	std::string&	stringREF = brain_str;

	std::cout << "Address of the string in memory: " << &brain_str << std::endl;
	std::cout << "Address stored in stringPTR:     " << stringPTR << std::endl;
	std::cout << "Address stored in stringREF:     " << &stringREF << std::endl;

	std::cout << "Value of the string in memory:   " << brain_str << std::endl;
	std::cout << "Value stored in stringPTR:       " << *stringPTR << std::endl;
	std::cout << "Value stored in stringREF:       " << stringREF << std::endl;
	return (EXIT_SUCCESS);
}
