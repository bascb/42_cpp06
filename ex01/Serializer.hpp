/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:02:04 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/28 19:55:19 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
    int value;
    std::string name;
};

class Serializer
{
	private:
		Serializer( void );
		Serializer( const Serializer& );
		Serializer& operator=( const Serializer& );
		~Serializer( void );
	public:
		static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif