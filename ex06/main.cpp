/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:54:22 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/20 17:51:00 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "HarlFilter expects one argument, the log level" << std::endl;
		return (EXIT_FAILURE);
	}
	Harl	harlito;
	std::string	argument = argv[1];
	harlito.complain(argument);

	return (EXIT_SUCCESS);
}
