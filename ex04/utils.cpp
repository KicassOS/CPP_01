/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:55:25 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/17 22:21:14 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

void	ft_close_files(std::ifstream & input_filestream, std::ofstream & output_filestream)
{
	input_filestream.close();
	output_filestream.close();

	if (input_filestream.is_open())
	{
		std::cerr << "The input file could not be closed properly" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (output_filestream.is_open())
	{
		std::cerr << "The output file could not be closed properly" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	ft_reject_only_whitespace_filename(std::string filename)
{
	if (filename.length() == 0)
	{
		std::cerr << "First argument to program must not be an empty string" << std::endl;
		exit(EXIT_FAILURE);	
	}
	for (size_t i = 0; i < filename.length(); i++)
	{
		if (!std::isspace(filename[i]))
			return;
	}
	std::cerr << "First argument to program must not be an empty string" << std::endl;
	exit(EXIT_FAILURE);
}

bool	ft_handle_same_arguments(char **argv, std::string input_filename)
{
	std::string	to_replace = argv[2];
	std::string	replacement = argv[3];
	if (to_replace == replacement)
	{
		// simply copy the files over
		std::ifstream	input_filestream(input_filename.c_str());
		if (!input_filestream.is_open() || input_filestream.fail())
		{
			std::cerr << "The input file could not be opened" << std::endl;
			exit(EXIT_FAILURE);
		}

		std::string		output_filename = input_filename + ".replace";
		std::ofstream	output_filestream(output_filename.c_str());
		if (!output_filestream.is_open() || output_filestream.fail())
		{
			std::cerr << "The output file could not be opened" << std::endl;
			input_filestream.close();
			exit(EXIT_FAILURE);
		}

		std::string	filebuffer = "";
		while (std::getline(input_filestream, filebuffer))
		{
			output_filestream << filebuffer;
			if (!input_filestream.eof())
				output_filestream << std::endl;
		}

		ft_close_files(input_filestream, output_filestream);
		return (true);
	}
	else
		return (false);
}

std::string	ft_handle_invalid_input(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "USAGE: ./SedIsForLosers FILENAME TO_REPLACE REPLACEMENT" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string input_filename = argv[1];
	ft_reject_only_whitespace_filename(input_filename);
	if (ft_handle_same_arguments(argv, input_filename) == true)
		return ("");
	return (input_filename);
}
