/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:26:04 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/21 13:15:21 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return;
}

Harl::~Harl()
{
	return;
}

void	Harl::complain( std::string level )
{
	std::string	warning_levels[4]			= {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*func_ptrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i							= 0;
	for (i = 0; i < 4 && warning_levels[i] != level; i++)
		;
	switch(i)
	{
		case 0:
			(this->*func_ptrs[0])();
			(this->*func_ptrs[1])();
			(this->*func_ptrs[2])();
			(this->*func_ptrs[3])();
			break;
		case 1:
			(this->*func_ptrs[1])();
			(this->*func_ptrs[2])();
			(this->*func_ptrs[3])();
			break;
		case 2:
			(this->*func_ptrs[2])();
			(this->*func_ptrs[3])();
			break;
		case 3:
			(this->*func_ptrs[3])();
			break;
		default:
			std::cout << GENERIC_RESPONSE << std::endl;
			break;
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n" << std::endl;
}
