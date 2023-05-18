/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/18 13:25:27 by haze             ###   ########.fr       */
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