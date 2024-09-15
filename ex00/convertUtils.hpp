/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertUtils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:28:29 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/15 22:15:47 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTUTILS_HPP
#define CONVERTUTILS_HPP

#include <iostream>
#include <string>
#include <cctype>

#define INVALID -1
#define CHAR 1
#define INTEGER 2
#define FLOAT 3
#define DOUBLE 4

int	detectType( const std::string& literal );

void printType(int type);

#endif