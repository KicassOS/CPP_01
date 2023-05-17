/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:55:42 by pszleper          #+#    #+#             */
/*   Updated: 2023/05/17 20:15:49 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
# define SEDISFORLOSERS_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include <cstdlib>

std::string	ft_handle_invalid_input(int argc, char **argv);
void		ft_close_files(std::ifstream & input_filestream, std::ofstream & output_filestream);

#endif