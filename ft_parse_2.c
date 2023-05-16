/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/16 13:19:09 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void	ft_final_parse_two(t_finale *p)
{
	int	i;

	i = 0;
	while (i < p->nb_phil)
	{
		p->next[i].id_philo = i + 1;
		p->next[i].fourchette_g = NULL;
		pthread_mutex_init(&p->next[i].fourchette_d, NULL);
		if (p->nb_phil == 1)
			return ;
		if (i == p->nb_phil - 1)
			p->next[i].fourchette_g = &p->next[i].fourchette_d;
		else
			p->next[i].fourchette_g = &p->next[i].fourchette_d;
		i++;
	}
}
