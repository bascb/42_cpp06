/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:17:54 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/04 19:41:04 by bcastelo         ###   ########.fr       */
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
    std::cout << "Going to convert " << literal << std::endl;
}
