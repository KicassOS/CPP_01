/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:16:44 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 16:25:59 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main()
{
	std::cout << "Testing randomChump() with Brian as argument" << std::endl;
	randomChump("Brian");

	std::cout << "Testing newZombie() with Steve as argument" << std::endl;
	Zombie *steve = newZombie("Steve");
	std::cout << "Now let's make Steve announce himself" << std::endl;
	steve->announce();
	std::cout << "Okay great, let's delete him now" << std::endl;
	delete steve;
	return (EXIT_SUCCESS);
}
