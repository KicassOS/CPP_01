/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:07:17 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 18:36:39 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const & type) : _type(type)
{
	return;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string const & newType)
{
	this->_type = newType;
}

std::ostream& operator<<(std::ostream& ostream, Weapon const & rhs)
{
	ostream << rhs.getType();
	return (ostream);
}
