/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:16:44 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 17:33:39 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main()
{
	Zombie*	horde;
	int	hordeSize = 5;

	std::cout << "Testing zombieHorde() with -1 as number of zombies" << std::endl;
	horde = zombieHorde(-1, "Brian");

	std::cout << "Testing zombieHorde() with 0 as number of zombies" << std::endl;
	horde = zombieHorde(0, "Steve");

	std::cout << "Testing zombieHorde() with 5 as number of zombies" << std::endl;
	horde = zombieHorde(5, "Brandon");
	std::cout << "Let's make them all announce() themselves" << std::endl;
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();

	std::cout << "Okay great, let's delete them now" << std::endl;
	delete[] horde;
	return (EXIT_SUCCESS);
}
