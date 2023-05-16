/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:07:12 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 18:30:50 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>

class Weapon
{
	public:
		Weapon(std::string const & type);
		~Weapon(void);

		const std::string&	getType(void) const;
		void				setType(std::string const & newType);

	private:
		std::string			_type;
};

std::ostream& operator<<(std::ostream& ostream, Weapon const & rhs);

#endif
