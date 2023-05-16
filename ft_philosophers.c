/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/16 13:21:24 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int ft_start(t_finale *p)
{
    int i;
    int error;

    i = 0;
    while (i < p->nb_phil)
    {
        error = pthread_create(&p->next[i].philo, NULL, ft_philosophers, &p->next[i]);
        if (error != 0)
            ft_error(-1);
        i++;
    }
    return (1);
}

void	*ft_philosophers(void *data)
{
	t_finale					*philo;

	philo = (t_finale *) data;
    if (philo->next->id_philo % 2 == 0)
        ft_usleep(philo->time_eat / 10);
    printf("id du philo qui vient pointer %d\n", philo->next->id_philo);
	return (NULL);
}