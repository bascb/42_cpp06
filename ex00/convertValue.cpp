/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertValue.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:30:06 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/22 19:43:46 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convertUtils.hpp"

void    convertChar(value *to_convert, const std::string& literal)
{
    to_convert->c_char = literal[0];
    to_convert->c_int = static_cast<int>(to_convert->c_char);
    to_convert->c_float = static_cast<float>(to_convert->c_char);
    to_convert->c_double = static_cast<double>(to_convert->c_char);
}

void    convertInt(value *to_convert, const std::string& literal)
{
    to_convert->c_char = literal[0];
    to_convert->c_int = static_cast<int>(to_convert->c_char);
    to_convert->c_float = static_cast<float>(to_convert->c_char);
    to_convert->c_double = static_cast<double>(to_convert->c_char);
}

void    convertValue(int type, value *to_convert, const std::string& literal)
{
    void (*functions[2])(value *, const std::string&) = {convertChar, convertInt};
    int i;

    for (i = 0; i < 2; i++)
    {
        if(type == i + 1)
        {
            functions[i](to_convert, literal);
        }
    }
}