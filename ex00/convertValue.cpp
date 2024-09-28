/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertValue.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:30:06 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/28 17:19:54 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convertUtils.hpp"

void    setValidationState(value *to_set, int state)
{
    to_set->v_char = state;
    to_set->v_int = state;
    to_set->v_float = state;
    to_set->v_double = state;
}

void    convertPseudo(value *to_convert, const std::string& literal)
{
    std::string Pseudo_d[3] = {"nan", "-inf", "+inf"};
    std::string Pseudo_f[3] = {"nanf", "-inff", "+inff"};
    int i;
    
    for (i = 0; i < 3; i++)
    {
        if (literal ==  Pseudo_d[i] || literal ==  Pseudo_f[i])
        {
            to_convert->v_char = IMPOSSIBLE;
            to_convert->v_int = IMPOSSIBLE;
            to_convert->v_float = i + 2;
            to_convert->v_double = i + 2;
            return;
        }
    }
}

void    convertChar(value *to_convert, const std::string& literal)
{
    to_convert->c_char = literal[0];
    to_convert->c_int = static_cast<int>(to_convert->c_char);
    to_convert->c_float = static_cast<float>(to_convert->c_char);
    to_convert->c_double = static_cast<double>(to_convert->c_char);
}

void    convertInt(value *to_convert, const std::string& literal)
{
    std::stringstream convert_stream(literal);
    
    convert_stream >> to_convert->c_int;
    if (convert_stream.fail())
    {
        setValidationState(to_convert, IMPOSSIBLE);
        return;
    }
    if (to_convert->c_int > -129 && to_convert->c_int < 128)
    {
        to_convert->c_char = static_cast<char>(to_convert->c_int);
        if (!isprint(to_convert->c_char))
        {
            to_convert->v_char = NON_DISPAYABLE;
        }
    }
    else
    {
        to_convert->v_char = IMPOSSIBLE;
    }
    to_convert->c_float = static_cast<float>(to_convert->c_int);
    to_convert->c_double = static_cast<double>(to_convert->c_int);
}

void    convertFloat(value *to_convert, const std::string& literal)
{
    std::stringstream convert_stream(literal);
    std::stringstream limits_stream(literal);
    double check_limits;
    
    convert_stream >> to_convert->c_float;
    if (convert_stream.fail())
    {
        setValidationState(to_convert, IMPOSSIBLE);
        return;
    }
    limits_stream >> check_limits;
    if (check_limits > -129 && check_limits < 128)
    {
        to_convert->c_char = static_cast<char>(to_convert->c_float);
        if (!isprint(to_convert->c_char))
        {
            to_convert->v_char = NON_DISPAYABLE;
        }
    }
    else
    {
        to_convert->v_char = IMPOSSIBLE;
    }
    if (check_limits > std::numeric_limits<int>::min() - 1.0 && check_limits < std::numeric_limits<int>::max() + 1.0)
    {
        to_convert->c_int = static_cast<int>(to_convert->c_float);
    }
    else
    {
        to_convert->v_int = IMPOSSIBLE;
    }
    to_convert->c_double = static_cast<double>(to_convert->c_float);
}

void    convertDouble(value *to_convert, const std::string& literal)
{
    std::stringstream convert_stream(literal);
    
    convert_stream >> to_convert->c_double;
    if (convert_stream.fail())
    {
        setValidationState(to_convert, IMPOSSIBLE);
        return;
    }
    if (to_convert->c_double > -129 && to_convert->c_double < 128)
    {
        to_convert->c_char = static_cast<char>(to_convert->c_double);
        if (!isprint(to_convert->c_char))
        {
            to_convert->v_char = NON_DISPAYABLE;
        }
    }
    else
    {
        to_convert->v_char = IMPOSSIBLE;
    }
    if (to_convert->c_double > std::numeric_limits<int>::min() - 1.0 && to_convert->c_double < std::numeric_limits<int>::max() + 1.0)
    {
        to_convert->c_int = static_cast<int>(to_convert->c_double);
    }
    else
    {
        to_convert->v_int = IMPOSSIBLE;
    }
    if (fabs(to_convert->c_double) > std::numeric_limits<float>::min() && fabs(to_convert->c_double) < std::numeric_limits<float>::max())
    {
        to_convert->c_float = static_cast<float>(to_convert->c_double);
    }
    else
    {
        to_convert->v_float = IMPOSSIBLE;
    }
}

void    convertValue(int type, value *to_convert, const std::string& literal)
{
    void (*functions[5])(value *, const std::string&) = {convertChar, convertInt, convertFloat, convertDouble, convertPseudo};
    int i;

    for (i = 0; i < 5; i++)
    {
        if(type == i + 1)
        {
            functions[i](to_convert, literal);
        }
    }
}