/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:30:52 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/28 23:18:19 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base( void )
{
    std::cout << "Base Default destructor called" << std::endl;
}

Base *generate( void )
{
    int random_nbr;
    srand(time(0));
    random_nbr = rand() % 3;
    if (random_nbr == 0) {return new A;}
    if (random_nbr == 1) {return new B;}
    if (random_nbr == 2) {return new C;}
    return NULL;
}