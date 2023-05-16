/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/16 18:33:12 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDE_H
# define FT_INCLUDE_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_base
{
	int				nb_phil;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	
}			t_base;

typedef struct s_fin
{
	pthread_t		philo;
	int				id_philo;
	pthread_mutex_t	fourchette_d;
	pthread_mutex_t	*fourchette_g;
	t_base			*next;
}				t_fin;

typedef struct s_finale
{
	t_base			base;
	t_fin			*fin;
}			t_finale;

int				ft_nb_argc(int argc);
int				ft_if_char(char **argv);
int				ft_if_pos(char **argv);
int				ft_verif_totale(int argc, char **argv);
int				ft_final_parse(char **argv, int argc, t_finale *p);
void			ft_final_parse_two(t_finale *p);
void			*ft_philosophers(void *data);

long long int	ft_atoi(char *thestring);
int				ft_error(int error);
long int		ft_long_error(void);
long int		ft_actual_time(void);
void			ft_usleep(long int time_in_ms);
void			*ft_start(t_finale *p);

#endif