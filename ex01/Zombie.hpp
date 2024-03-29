/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 08:18:13 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 18:19:30 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string const & name);
		~Zombie(void);

		void		announce(void) const;

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
