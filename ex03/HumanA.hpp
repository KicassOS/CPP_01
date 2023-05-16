/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:07:43 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 19:34:02 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string const & name, Weapon const & weapon);
		~HumanA(void);

		void	attack(void);

	private:
		std::string	const	_name;
		Weapon const &			_weapon;
};

#endif
