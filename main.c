/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/02 18:04:19 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int main(int argc, char **argv)
{
    t_finale    *p;
    p = malloc(sizeof(t_finale));
    final_parse(argv, argc, p);
    printf("Juste pour le test %d\n", test);
    return (0);
}