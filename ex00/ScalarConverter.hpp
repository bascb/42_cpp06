/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:46:40 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/04 20:00:34 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		static void convert( const std::string& literal );
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& );
		ScalarConverter& operator=( const ScalarConverter& );
		virtual ~ScalarConverter( void ) = 0;
};

#endif