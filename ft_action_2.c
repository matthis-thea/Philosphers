/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/18 17:19:47 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void launch(t_fin *p)
{
	pthread_mutex_unlock(&p->check_write);
	pthread_mutex_lock(&p->fourchette_g);
	pthread_mutex_lock(&p->check_write);
	ft_fork(p);
	pthread_mutex_unlock(&p->check_write);
	if (!p->fourchette_d)
	{
		ft_usleep(p->next->time_die * 2);
		return ;
	}
	pthread_mutex_lock(p->fourchette_d);
	pthread_mutex_lock(&p->check_write);
	ft_fork(p);
	pthread_mutex_unlock(&p->check_write);
	pthread_mutex_lock(&p->check_write);
	ft_eat(p);
	p->last_dinner = ft_actual_time();
	pthread_mutex_unlock(&p->check_write);
	ft_usleep(p->next->time_eat);
	pthread_mutex_unlock(&p->fourchette_g);
	pthread_mutex_unlock(p->fourchette_d);
	pthread_mutex_lock(&p->check_write);
	ft_sleep(p);
	pthread_mutex_unlock(&p->check_write);
	ft_usleep(p->next->time_sleep);
	pthread_mutex_lock(&p->check_write);
	ft_think(p);
	pthread_mutex_unlock(&p->check_write);
}

void ft_each_eat(t_fin *p)
{
	long int		time;

	time = ft_actual_time() - p->next->time_start;
	if (!test(p))
	{
		printf("%ldms ate %d\n",time, p->next->nb_eat);
	}
}
