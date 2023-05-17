/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:39:42 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/17 22:20:40 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

std::string	ft_replace_occurrences_in_line(std::string& buffer, std::string& to_find, std::string& replacement, size_t& occ_index, size_t& line_length)
{
	// copy the contents from the start of buffer up until the occurence into temp
	std::string	temp = buffer.substr(0, occ_index);

	// while there are still occurences to be found in buffer, update the occurrence index and replace
	while ((occ_index = buffer.find(to_find)) < line_length)
	{
		temp = buffer.substr(0, occ_index);
		// replace the current occurence
		temp += replacement;
		// add the remaining buffer contents
		temp += buffer.substr(occ_index + to_find.length());
		buffer = temp;
	}
	return (buffer);
}

void	ft_replace(std::ifstream& input, std::ofstream& output, std::string& buffer, std::string& to_find, std::string& replacement)
{
	size_t	occurrence_index = 0;
	size_t	line_length = 0;

	while (std::getline(input, buffer))
	{
		occurrence_index = buffer.find(to_find);
		line_length = buffer.length();
		if (occurrence_index < line_length) // found a match
			buffer = ft_replace_occurrences_in_line(buffer, to_find, replacement, occurrence_index, line_length);
		output << buffer;
		if (!input.eof())
			output << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::string		input_filename = ft_handle_invalid_input(argc, argv);
	if (input_filename.length() == 0) // catching duplicate arguments here
		exit(EXIT_SUCCESS);

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
	std::string	to_replace = argv[2];
	std::string	replace_with = argv[3];

	ft_replace(input_filestream, output_filestream, filebuffer, to_replace, replace_with);

	ft_close_files(input_filestream, output_filestream);
	return (EXIT_SUCCESS);
}
