/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:27:56 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/22 18:02:23 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convertUtils.hpp"

int detectChar( const std::string& literal )
{
    if (literal.length() == 1)
    {
        if (isdigit(literal[0]))
        {
            return (INTEGER);    
        }
        if (!isprint(literal[0]))
        {
            std::cout << "Invalid char: Must be displayable" << std::endl;
            return (INVALID);
        }
        return (CHAR);
    }
    return (0);
}

int detectInt( const std::string& literal )
{
    size_t i;
    
    if (literal[0] == '+' || literal[0] == '-' || isdigit(literal[0]))
    {
        for (i = 1; i < literal.length(); i++)
        {
            if (!isdigit(literal[i]))
            {
                return (0);
            }
        }
        return (INTEGER);
    }
    return (0);
}

int detectFloat( const std::string& literal )
{
    size_t i;
    size_t len;
    int dots_nbr;
    
    len = literal.length();
    if (literal[len - 1] != 'f')
    {
        return (0);
    }
    if (literal[0] == '+' || literal[0] == '-' || isdigit(literal[0]))
    {
        dots_nbr = 0;
        for (i = 1; i < len - 1; i++)
        {
            if (!isdigit(literal[i]) && literal[i] != '.')
            {
                return (0);
            }
            if (literal[i] == '.')
            {
                dots_nbr++;
            }
        }
        if (dots_nbr != 1)
        {
            return (INVALID);
        }
        return (FLOAT);
    }
    return (0);
}

int detectDouble( const std::string& literal )
{
    size_t i;
    size_t len;
    int dots_nbr;
    
    if (literal == "-inf" || literal == "+inf" || literal == "nan") 
    {
        return (DOUBLE);
    }
    len = literal.length();
    if (literal[0] == '+' || literal[0] == '-' || isdigit(literal[0]))
    {
        dots_nbr = 0;
        for (i = 1; i < len; i++)
        {
            if (!isdigit(literal[i]) && literal[i] != '.')
            {
                return (0);
            }
            if (literal[i] == '.')
            {
                dots_nbr++;
            }
        }
        if (dots_nbr > 1)
        {
            return (INVALID);
        }
        return (DOUBLE);
    }
    return (0);
}

int	detectType( const std::string& literal )
{
    int (*functions[4])( const std::string& ) = {detectChar, detectFloat, detectDouble, detectInt};
    int i;
    int type;

    for (i = 0; i < 4; i++)
    {
        type = functions[i](literal);
        if (type)
        {
            return (type);
        }
    }
    return (INVALID);
}

