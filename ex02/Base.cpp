/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:30:52 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/29 00:02:09 by bcastelo         ###   ########.fr       */
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

void identify(Base* p)
{
    if (p == NULL)
    {
        std::cout << "No pointer to class" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "Type = A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type = B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type = C" << std::endl;
    else
        std::cout << "Unale to identify type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A a_type = dynamic_cast<A&>(p);
        std::cout << "Type = A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B b_type = dynamic_cast<B&>(p);
            std::cout << "Type = B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                C c_type = dynamic_cast<C&>(p);
                std::cout << "Type = C" << std::endl;
            }
            catch (std::exception &e)
            {
                 std::cout << "Unale to identify type" << std::endl;
            }
        }
    }
}