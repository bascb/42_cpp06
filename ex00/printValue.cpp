/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printValue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:01:56 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/22 19:35:22 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convertUtils.hpp"

void printChar(value *val)
{
    std::string Errors[3] = {"ok", "impossible", "Non displayable"};
    
    std::cout << "char: ";
    if (val->v_char == CONVERSION_OK)
    {
        std::cout << val->c_char;
    }
    else
    {
        std::cout << Errors[val->v_char];
    }
}

void printInt(value *val)
{
    std::string Errors[2] = {"ok", "impossible"};
    
    std::cout << "int: ";
    if (val->v_int == CONVERSION_OK)
    {
        std::cout << val->c_int;
    }
    else
    {
        std::cout << Errors[val->v_int];
    }
}

void printFloat(value *val)
{
   std::string Errors[4] = {"ok", "nanf", "-inff", "+inff"};
    
    std::cout << "float: ";
    if (val->v_float == CONVERSION_OK)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(1);
        std::cout << val->c_float << "f";
    }
    else
    {
        std::cout << Errors[val->v_float];
    }
}

void printDouble(value *val)
{
   std::string Errors[4] = {"ok", "nan", "-inf", "+inf"};
    
    std::cout << "double: ";
    if (val->v_double == CONVERSION_OK)
    {
        std::cout << std::fixed;
        std::cout << std::setprecision(1);
        std::cout << val->c_double;
    }
    else
    {
        std::cout << Errors[val->v_double];
    }
}

void printValue(value *val)
{
    void (*functions[4])( value * ) = {printChar, printInt, printFloat, printDouble};
    int i;

    for (i = 0; i < 4; i++)
    {
        functions[i](val);
        std::cout << std::endl;
    }
}

void printType(int type)
{
    std::string Types[5] = {"Unable to detect", "Char", "Int", "Float", "Double"};
    int i;
    
    std::cout << "Literal type: ";
    for (i = 0; i < 5; i++)
    {
        if ( type == i)
        {
            std::cout << Types[i] << std::endl;
            return ;
        }
    }
    std::cout << "Invalid input" << std::endl;
}