/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/18 02:11:44 by haze             ###   ########.fr       */
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
	int				time_die;
	int				time_eat;
	int				nb_phil;
	int				nb_eat;
	int				time_sleep;
	long int		time_start;

	
}			t_base;

typedef struct s_fin
{
	pthread_t		philo;
	int				id_philo;
	pthread_t		verif_dead;
	pthread_mutex_t	verif_death;
	pthread_t		check_dead;
	pthread_mutex_t	check_write;
	pthread_mutex_t	*fourchette_d;
	long int		last_dinner;
	pthread_mutex_t	fourchette_g;
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
void			*ft_verif_dead(void *data);
int				ft_finish(t_fin *p);
int 			test(int i);




void ft_think(t_fin *p);
void ft_eat(t_fin *p);
void ft_sleep(t_fin *p);
void ft_fork(t_fin *p);
void ft_dead(t_fin *p);
void launch(t_fin *p);


long long int	ft_atoi(char *thestring);
int				ft_error(int error);
long int		ft_long_error(void);
long int		ft_actual_time(void);
void			ft_usleep(long int time_in_ms);
int				ft_start(t_finale *p);

#endif