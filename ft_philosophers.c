/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/17 21:37:05 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int ft_start(t_finale *p)
{
    int i;
    int error;

    i = 0;
    while (i < p->base.nb_phil)
    {
        p->fin[i].next = &p->base;
        epthread_create(&p->fin[i].philo, NULL, ft_philosophers, &p->fin[i]);
        if (error != 0)
            return(ft_error(-1));
        i++;
    }
    return (1);
}

void    *ft_philosophers(void *data)
{
	t_fin					*p;

	p = (t_fin *) data;

    if (p->id_philo % 2 == 0)
        ft_usleep(p->next->time_eat / 10);
    char *str = "ecriture\n";
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
	return (NULL);
}

void    *check_dead(void *data)
{
    t_fin   *p;

    p = (t_fin *) data;
    ft_usleep(p->next->time_die);
    pthread_mutex_lock(&p.)
    return (NULL);
}