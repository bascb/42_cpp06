/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertUtils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:28:29 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/28 10:14:10 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTUTILS_HPP
#define CONVERTUTILS_HPP

#include <iostream>
#include <iomanip> 
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <cmath>

#define INVALID -1
#define CHAR 1
#define INTEGER 2
#define FLOAT 3
#define DOUBLE 4

#define CONVERSION_OK 0
#define IMPOSSIBLE 1
#define NON_DISPAYABLE 2
#define PSEUDO_NAN 2
#define INF_MINUS 3
#define INF_PLUS 4

typedef struct
{
    char    c_char;
    int     v_char;
    int     c_int;
    int     v_int;
    float   c_float;
    int     v_float;
    double  c_double;
    int     v_double;  
} value;

int	detectType( const std::string& literal );

void convertValue(int type, value *to_convert, const std::string& literal);

void printValue(value *val);

void printType(int type);

#endif