/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:17:54 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/28 16:59:31 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
    std::cout << "ScalarConverter Default constructor called" << std::endl;
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
