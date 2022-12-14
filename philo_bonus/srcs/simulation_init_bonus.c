/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:10:41 by becastro          #+#    #+#             */
/*   Updated: 2022/12/09 19:37:58 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include "nodes_bonus.h"
#include <pthread.h>
#include <fcntl.h>

void	init_treadhs(t_philo **head, t_data *data)
{
	t_philo		*aux;

	sem_unlink(SEM_PRINT_STATS);
	data->printing = sem_open(SEM_PRINT_STATS, O_CREAT, SEM_PERMS, 1);
	sem_unlink(SEM_PRINT);
	data->global_prints = sem_open(SEM_PRINT, O_CREAT, SEM_PERMS, 0);
	sem_unlink(SEM_CREATE_PROCESS);
	data->init_childs = sem_open(SEM_CREATE_PROCESS, O_CREAT, SEM_PERMS, 0);
	sem_unlink(SEM_FORKS);
	data->forks = sem_open(SEM_FORKS, O_CREAT, SEM_PERMS, data->n_philos);
	aux = (*head);
	gettimeofday(&data->g_time, NULL);
	while (aux)
	{
		aux->pid = fork();
		if (aux->pid == 0)
			init_routine(aux);
		aux = aux->next;
		if (aux == (*head))
			break ;
	}
	sem_post(data->init_childs);
}

void	init_philos(t_data *data)
{
	static u_int32_t	id;
	t_philo				*philo_head;
	u_int32_t			i;

	i = data->n_philos;
	philo_head = NULL;
	while (i--)
	{
		id++;
		ft_philoadd_back(&philo_head, create_philo_node(id, data));
	}
	philo_head->prev = ft_philolast(philo_head);
	ft_philolast(philo_head)->next = philo_head;
	data->philo_lst = philo_head;
	init_treadhs(&philo_head, data);
}
