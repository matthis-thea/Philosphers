/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/02 18:04:19 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int main(int argc, char **argv)
{
    t_finale p;
    t_finale_tab *t;
	int i = 0;
    final_parse(argv, argc, &p);
    t = malloc(sizeof(t_finale_tab) * p.nb_phil);
	if (!t)
		return (0);
	final_parse_two(&p, t);
    while (i < 5)
    {
        printf("Nombre de philosophes: %d\nTemps pour mourir: %d\nTemps pour manger: %d\n Temps pour dormir: %d\n ID des philosophes: %d\n", p.nb_phil, p.time_die, p.time_eat, p.time_sleep, t[i].id_philo);
        printf("\n\n");

		i++;
    }
    return (0);
}