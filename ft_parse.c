/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/16 13:14:45 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int	ft_nb_argc(int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	return (0);
}

int	ft_if_char(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
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

int	ft_if_pos(char **argv)
{
	int	number;
	int	i;

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

int	ft_verif_totale(int argc, char **argv)
{
	int	number;

	number = ft_nb_argc(argc);
	if (number == 0)
		return (ft_error(-2));
	number = ft_if_char(argv);
	if (number == 0)
		return (ft_error(-2));
	number = ft_if_pos(argv);
	if (number == 0)
		return (ft_error(-2));
	return (1);
}

int	ft_final_parse(char **argv, int argc, t_finale *p)
{
	int	number;

	number = ft_verif_totale(argc, argv);
	if (number == 0)
		return (0);
	p->nb_phil = ft_atoi(argv[1]);
	p->time_die = ft_atoi(argv[2]);
	p->time_eat = ft_atoi(argv[3]);
	p->time_sleep = ft_atoi(argv[4]);
	p->nb_eat = -1;
	if (argc == 6)
		p->nb_eat = ft_atoi(argv[5]);
	return (1);
}
