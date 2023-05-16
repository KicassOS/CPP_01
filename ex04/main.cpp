/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:39:42 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/16 21:11:23 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

void	ft_reject_only_whitespace_filename(std::string filename)
{
	for (int i = 0; i < filename.length(); i++)
	{
		if (!std::isspace(filename[i]))
			return;
	}
	std::cerr << "First argument to program must not be an empty string" << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "USAGE: ./SedIsForLosers FILENAME TO_REPLACE REPLACEMENT" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string input_filename = argv[1];
	ft_reject_only_whitespace_filename(input_filename);

	std::ifstream	input_filestream(input_filename);
	std::string		output_filename = input_filename + ".replace";
	std::ofstream	output_filestream(output_filename);
	if (!input_filestream.is_open())
	{
		std::cerr << "The input file could not be opened" << std::endl;
		return (EXIT_FAILURE);
	}
	if (!output_filestream.is_open())
	{
		std::cerr << "The output file could not be opened" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string	filebuffer;
	std::string	to_replace = argv[2];
	std::string	replace_with = argv[3];

	while (std::getline(input_filestream, filebuffer))
	{
		
	}

	input_filestream.close();
	output_filestream.close();
	if (input_filestream.is_open())
	{
		std::cerr << "The input file could not be closed properly" << std::endl;
		return (EXIT_FAILURE);
	}
	if (output_filestream.is_open())
	{
		std::cerr << "The output file could not be closed properly" << std::endl;
		return (EXIT_FAILURE);
	}
	
	return (EXIT_SUCCESS);
}
