/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/02 17:50:43 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDE_H
# define FT_INCLUDE_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_finale
{
    int					nb_phil;
    int					time_die;
    int 				time_eat;
    int 				time_sleep;             
}			t_finale;

typedef struct s_finale_tab
{
    pthread_t   		philo;
    int					id_philo;
	pthread_mutex_t		fourchette_d;
	pthread_mutex_t		*fourchette_g;
}               t_finale_tab;

int	ft_nb_argc(int argc);
int ft_if_char(char **argv);
int ft_if_pos(char **argv);
int ft_verif_totale(int argc, char **argv);
int final_parse(char **argv, int argc, t_finale *p);
void final_parse_two(t_finale *p, t_finale_tab *t);


int	ft_atoi(const char *thestring);
int	error(void);

#endif