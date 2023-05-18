/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/18 18:35:46 by haze             ###   ########.fr       */
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
        error = pthread_create(&p->fin[i].philo, NULL, ft_philosophers, &p->fin[i]);
        if (error != 0)
            return(ft_error(-1));
        i++;
    }
    i = 0;
    while (i < p->base.nb_phil)
    {
        pthread_join(p->fin[i].philo, NULL);
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
    while (!test(p))
    {
        pthread_create(&p->verif_dead, NULL, ft_verif_dead, data);
        launch(p);
		pthread_detach(p->verif_dead);
    }
	return (NULL);
}

void    *ft_verif_dead(void *data)
{
    t_fin   *p;

    p = (t_fin *) data;
    ft_usleep(p->next->time_die);
    p->inc_eat++;
    pthread_mutex_lock(&p->next->verif_death);
    if ((ft_actual_time() - p->last_dinner) >= (long)(p->next->time_die))
    {
        pthread_mutex_lock(&p->check_write);
        ft_dead(p);
        p->next->finish = 1;
        pthread_mutex_unlock(&p->check_write);
    }
    else if (p->inc_eat == p->next->nb_eat)
    {
        pthread_mutex_lock(&p->check_write);
        ft_each_eat(p);
        p->next->finish = 1;
        pthread_mutex_unlock(&p->check_write);
    }
    pthread_mutex_unlock(&p->next->verif_death);
    return (NULL);
}

int test(t_fin *p)
{
    pthread_mutex_lock(&p->next->is_dead);
    if (p->next->finish)
    {
        pthread_mutex_unlock(&p->next->is_dead);
        return (1);
    }
    pthread_mutex_unlock(&p->next->is_dead);
    return (0);
}

int ft_stop(t_finale *p)
{
    int i;

    i = 0;
    pthread_mutex_destroy(&p->base.verif_death);
    pthread_mutex_destroy(&p->base.is_dead);
    while (i < p->base.nb_phil)
    {
        if (p->base.nb_phil > 1)
            pthread_mutex_destroy(p->fin[i].fourchette_d);
        pthread_mutex_destroy(&p->fin[i].check_write);
	    pthread_mutex_destroy(&p->fin[i].w);
        i++;
    }
    free(p->fin);
    return (1);
}
