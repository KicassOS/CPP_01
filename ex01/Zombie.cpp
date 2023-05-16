/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 08:20:49 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 17:26:02 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << this->_name <<  " constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " destructor called" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
