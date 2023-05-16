/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:39:46 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 17:26:14 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Can't create a horde comprising of a negative or non-existent amount of zombies" << std::endl;
		return NULL;
	}
	Zombie*	array_ptr = new	Zombie[N];

	for (int i = 0; i < N; i++)
		array_ptr[i] = Zombie(name);
	return (array_ptr);
}
