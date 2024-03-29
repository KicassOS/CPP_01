/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:26:19 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/20 17:04:48 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain( std::string level );
	
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif