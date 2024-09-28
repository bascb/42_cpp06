/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:46:40 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/28 16:36:26 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include "convertUtils.hpp"

class ScalarConverter
{
	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& );
		ScalarConverter& operator=( const ScalarConverter& );
		~ScalarConverter( void );
	public:
		static void convert( const std::string& literal );
};

#endif