/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/04/26 14:18:45 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int	ft_nb_argc(int argc)
{
	if (argc == 5)
		return (1);
	return (0);
}

int ft_if_char(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while(argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

int ft_if_pos(char **argv)
{
	int number;
	int i;

	i = 1;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (number < 0)
			return (0);
		if ((i == 1 && number > 5) || (i == 1 && number < 1))
			return (0);
		if (number > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int ft_verif_totale(int argc, char **argv)
{
	int number;

	number = ft_nb_argc(argc);
	if (number == 0)
		return (error());
	number = ft_if_char(argv);
	if (number == 0)
		return (error());
	number = ft_if_pos(argv);
	if (number == 0)
		return (error());
	return (1);
}

int main(int argc, char **argv)
{
    if (ft_verif_totale(argc, argv) == 0)
		return (0);
	return (1);
}