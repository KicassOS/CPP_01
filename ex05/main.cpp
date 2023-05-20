/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:26:43 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/20 17:15:42 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harlito;

	harlito.complain("DEBUG");
	harlito.complain("INFO");
	harlito.complain("WARNING");
	harlito.complain("ERROR");
	return (0);
}

