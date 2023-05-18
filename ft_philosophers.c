/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/18 02:30:08 by haze             ###   ########.fr       */
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
        error = pthread_create(&p->fin[i].philo, NULL, ft_philosophers, &p->fin[i]);
        pthread_join(p->fin[p->base.nb_phil - 1].philo, NULL);
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
    while (test(1))
    {
        pthread_create(&p->verif_dead, NULL, ft_verif_dead, data);
        launch(p);
		pthread_detach(p->verif_dead);
    }
    printf("C'est sorti\n");
	return (NULL);
}

void    *ft_verif_dead(void *data)
{
    t_fin   *p;

    p = (t_fin *) data;
    int v
    ft_usleep(p->next->time_die);
    pthread_mutex_lock(&p->verif_death);
    if ((ft_actual_time() - p->last_dinner) >= (long)(p->next->time_die))
    {
        pthread_mutex_lock(&p->check_write);
        ft_dead(p);
        pthread_mutex_unlock(&p->check_write);
        pthread_mutex_unlock(&p->verif_death);
        
        return (NULL);
    }
    pthread_mutex_unlock(&p->verif_death);
    return (NULL);
}

int test(int i)
{
    if (i == 1)
        return (1);
    return (0);
}