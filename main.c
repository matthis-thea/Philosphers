/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/18 12:00:02 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int main(int argc, char **argv)
{
    t_finale p;

    ft_final_parse(argv, argc, &p);
    // printf("Nombre de philosopher %d\nTemps pour mourir %d\nTemps pour manger %d\nTemps pour dormir %d\n Nombre de fois pour dormir %d\n", p.nb_phil, p.time_die, p.time_eat, p.time_sleep, p.nb_eat);
    p.fin = malloc(sizeof(t_fin) * p.base.nb_phil);
    if (!p.fin)
    {
        printf("Allocation failed !\n");
        return (0);
    }
    ft_final_parse_two(&p);
    // // printf("Id du philosopher : %d\n", p.next[2].id_philo);
    if (!ft_start(&p))
        free(p.fin);
    return (0);
}
