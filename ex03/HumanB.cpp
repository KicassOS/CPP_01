/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:07:31 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 19:36:45 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const & name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::setWeapon(Weapon & weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
