/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:41:22 by bcastelo          #+#    #+#             */
/*   Updated: 2024/09/29 00:06:16 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"

#define WIDTH 60

void	print_border( void );

void	print_left(int space);

void	print_rigth(int space);

int	calculate_space(int header_len);

int	calculate_right_space(int header_len);

void	print_header(std::string header);

void	print_comment(std::string comment);

void	print_help(char *prog_name);

int	main(void)
{
    Base *Ramdom_type;
    Base *sim_null;
    
	print_header("Identify type");
    Ramdom_type = generate();
    sim_null = NULL;
    identify(Ramdom_type);
    identify(*Ramdom_type);
    identify(sim_null);
    identify(*sim_null);
    delete Ramdom_type;
	return (0);
}

void	print_border( void )
{
	for (int i = 0; i < WIDTH; i++)
		std::cout << "*";
	std::cout << std::endl;
}

void	print_left(int space)
{
	std::cout << "*";
	for (int i = 0; i < space; i++)
		std::cout << " ";
}

void	print_rigth(int space)
{
	for (int i = 0; i < space; i++)
		std::cout << " ";
	std::cout << "*" << std::endl; 
}

int	calculate_space(int header_len)
{
	int	space;

	space = (WIDTH - header_len - 2) / 2;
	return (space);
}

int	calculate_right_space(int header_len)
{
	int	space;

	space = (WIDTH - header_len - 2) / 2;
	space += (WIDTH - header_len - 2) % 2;
	return (space);
}

void	print_header(std::string header)
{
	int space;

	space = calculate_space(header.size());
	print_border();
	print_left(space);
	std::cout << header;
	space = calculate_right_space(header.size());
	print_rigth(space);
	print_border();
}

void	print_comment(std::string comment)
{
	int space;

	space = calculate_space(comment.size());
	std::cout << std::endl;
	print_left(space);
	std::cout << comment;
	space = calculate_right_space(comment.size());
	print_rigth(space);
	std::cout << std::endl;
}

void	print_help(char *prog_name)
{
	print_header("Usage");
	std::cout << prog_name << std::endl;
}