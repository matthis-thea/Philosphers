/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/02 17:35:11 by haze             ###   ########.fr       */
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

int final_parse(char **argv, int argc, t_finale *p)
{
	int	number;

	number = ft_verif_totale(argc, argv);
	if (number == 0)
		return (0);
	p->nb_phil = ft_atoi(argv[1]);
	p->time_die = ft_atoi(argv[2]);
	p->time_eat = ft_atoi(argv[3]);
	p->time_sleep = ft_atoi(argv[4]);
	return (1);
}

void final_parse_two(t_finale *p, t_finale_tab *t)
{
	int i;

	i = 0;
	while (i < p->nb_phil)
	{
		t[i].id_philo = i + 1;
		pthread_mutex_init(&t[i].fourchette_d, NULL);
		if (i == p->nb_phil - 1)
			t[i].fourchette_g =  &t[0].fourchette_d;
		else
			t[i].fourchette_g =  &t[i + 1].fourchette_d;
		i++;

	}
}