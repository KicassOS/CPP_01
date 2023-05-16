/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:07:23 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 19:36:33 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string const & name);
		~HumanB(void);

		void	setWeapon(Weapon & weapon);
		void	attack(void);

	private:
		std::string	const	_name;
		Weapon*				_weapon;
};


#endif