/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/16 13:19:22 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int main(int argc, char **argv)
{
    t_finale p;

    ft_final_parse(argv, argc, &p);
    p.next = malloc(sizeof(t_fin) * p.nb_phil);
    ft_final_parse_two(&p);
    ft_start(&p);
    return (0);
}
