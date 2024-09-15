/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:17:54 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/15 22:15:13 by bcastelo         ###   ########.fr       */
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
//    char char_value;
//    int int_value;
//    float float_value;
//    double double_value;
    
    if (literal.length() == 0)
    {
       std::cout << "No input" << std::endl; 
       return ;
    }
    std::cout << "Going to convert " << literal << std::endl;
    type = detectType(literal);
    printType(type);
    if (type == -1)
    {
        std::cout << "Invalid input" << std::endl; 
        return ;
    } 
}
