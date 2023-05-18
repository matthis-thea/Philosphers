/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/18 19:34:43 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void	ft_final_parse_two(t_finale *p)
{
	int	i;

	i = 0;
	p->base.time_start = ft_actual_time();
	p->base.finish = 0;
	p->fin->inc_eat = 0;
	pthread_mutex_init(&p->base.is_dead, NULL);
	pthread_mutex_init(&p->base.verif_death, NULL);
	while (i < p->base.nb_phil)
	{
		p->fin[i].id_philo = i + 1;
		p->fin[i].fourchette_d = NULL;
		p->fin[i].last_dinner = p->base.time_start;
		pthread_mutex_init(&p->fin[i].fourchette_g, NULL);
		pthread_mutex_init(&p->fin[i].check_write, NULL);
		pthread_mutex_init(&p->fin[i].w, NULL);
		if (p->base.nb_phil == 1)
			return ;
		if (i == p->base.nb_phil - 1)
			p->fin[i].fourchette_d = &p->fin[0].fourchette_g;
		else
			p->fin[i].fourchette_d = &p->fin[i + 1].fourchette_g;
		p->fin[i].next = &p->base;
		i++;
	}
}
