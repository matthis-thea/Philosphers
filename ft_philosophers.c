/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/16 18:38:22 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void *ft_start(t_finale *p)
{
    int i;
    int error;

    i = 0;
    while (i < p->base.nb_phil)
    {
        p->fin[i].next = &p->base;
        error = pthread_create(&p->fin[i].philo, NULL, ft_philosophers, &p->fin[i]);
        if (error != 0)
            ft_error(-1);
        i++;
    }
    return (NULL);
}

void	*ft_philosophers(void *data)
{
	t_fin					*p;

	p = (t_fin *) data;

    if (p->id_philo% 2 == 0)
        ft_usleep(p->next->nb_eat / 10);
    char *str = "Hello World !\n";
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    // printf("Id du philosopher : %d\n", p->next->id_philo);
	return (NULL);
}