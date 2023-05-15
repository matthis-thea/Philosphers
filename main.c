/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/15 18:29:03 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

// void *printhello(void *data)
// {
//     char *str = "Hello World !\n";
//     int i = 0;
//     t_finale *ppp;
//     ppp = (t_finale *) data;
//     printf("Id du philo %d,\nTemps pour mourir %d,\nTemps pour manger %d,\nTemps pour dormir %d\n", ppp->id_philo, ppp->time_die, ppp->time_eat, ppp->time_sleep);
//     // pthread_mutex_lock(&ppp->fourchette_d);
//     // printf("Le philo Numero (%d) compte...\n", ppp->id_philo);
//     while(str[i])
//     {
//         write(1, &str[i], 1);
//         i++;
//     }
//     // printf("Le philo Numero (%d) a fini de compte...\n", ppp->id_philo);
//     // pthread_mutex_unlock(&ppp->fourchette_d);
//     return (NULL);
// }

// int main(int argc, char **argv)
// {
//     t_finale          p;
//     t_finale         *pp;
//     int i = 0;
//     pp = malloc(sizeof(t_finale));
//     final_parse(argv, argc, pp);
//     // printf("Nombre de philosophers %d\n", pp->nb_phil);
//     while (i < pp->nb_phil)
//     {
//         // printf("Id du philo %d,\nTemps pour mourir %d,\nTemps pour manger %d,\nTemps pour dormir %d\n", pp[i].id_philo, pp->time_die, pp->time_eat, pp->time_sleep);
//         // pthread_create(&pp[i].philo, NULL, printhello, &pp[i]);
//         // pthread_join(pp[i].philo, NULL);
//         i++;
//     }
//     pthread_create(&pp[0].philo, NULL, printhello, &pp[0]);
// 	return (0);
// }

typedef	struct              s_p
{
    pthread_mutex_t         mutex;
    int                     i;
    pthread_t               thread_id1;
}                           t_p;

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void    *go1(void *pp)
{
    char *str;
    int i = 0;
    t_p *ppp;

    ppp = (t_p *)pp;
    str = "tread 1 : coucou ca va ? \n";
    pthread_mutex_lock(&ppp->mutex); // si on enleve ici
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    pthread_mutex_unlock(&ppp->mutex); // si on enleve ici
    return (NULL);
}

int main(int argc, char **argv)
{
    (void) argv;
    t_p                     *pp;

    pp = (malloc(sizeof(t_p) * 1));
    pthread_mutex_init(&pp->mutex, NULL);			// obligatoire de init le mutex
    int i = 0;
    while (i < argc)
    {
        pthread_create(&pp[i].thread_id1, NULL, go1, (void *)pp);
        i++;
    }
    sleep(1);
}
