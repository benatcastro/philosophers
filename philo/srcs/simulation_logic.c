/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:33:52 by bena              #+#    #+#             */
/*   Updated: 2022/12/07 18:37:57 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*death_checker(void *data_ptr)
{
	t_data	*data;
	t_philo	*aux;

	data = (t_data *)data_ptr;
	aux = (data->philo_lst);
	while (aux)
	{
		if ((get_time() - aux->last_eat) >= data->data_tv->tt_die)
			break ;
		aux = aux->next;
	}
	data->simulation_state = PHILO_DIED;
	print_simulation_state(data, aux);
	return (NULL);
}

void	*times_eaten_checker(void *data_ptr)
{
	t_data		*data;
	t_philo		*aux;
	u_int32_t	philo_counter;

	data = (t_data *)data_ptr;
	philo_counter = data->n_philos;
	aux = (data->philo_lst);
	if (!data->must_eat)
		return (NULL);
	while (aux)
	{
		if (aux->t_eaten == data->eat_times && !aux->finished_eaten)
		{
			aux->finished_eaten = true;
			data->eaten_philos++;
		}
		if (data->eaten_philos == philo_counter)
			break ;
		aux = aux->next;
	}
	data->simulation_state = PHILO_EATEN;
	print_simulation_state(data, NULL);
	return (NULL);
}
