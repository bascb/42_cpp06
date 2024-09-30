/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:17:54 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/30 19:38:06 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
    std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& )
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& )
{
    std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter( void )
{
    std::cout << "ScalarConverter Default destructor called" << std::endl;
}

void ScalarConverter::convert( const std::string& literal )
{
    int type;
    value converted = {};
    
    if (literal.length() == 0)
    {
       std::cout << "No input" << std::endl; 
       return ;
    }
    type = detectType(literal);
    if (type == -1)
    {
        std::cout << "Invalid input" << std::endl; 
        return ;
    }
    convertValue(type, &converted, literal);
    printValue( &converted);
}
