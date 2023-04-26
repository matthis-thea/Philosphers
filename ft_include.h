/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/04/26 14:17:30 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDE_H
# define FT_INCLUDE_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_nb_argc(int argc);
int ft_if_char(char **argv);
int ft_if_pos(char **argv);
int ft_verif_totale(int argc, char **argv);




int	ft_atoi(const char *thestring);
int	error(void);

#endif