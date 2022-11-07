/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:58:15 by bena              #+#    #+#             */
/*   Updated: 2022/11/07 09:03:24 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "structs.h"
#include "philosophers.h"
#include <string.h>
#include <stdio.h>

void	print_philos(t_data *data)
{
	t_philo	*aux;

	aux = (*data->lst_head);
	while (aux)
	{
		printf("(%d) Philo: (%d)", get_time(), aux->id);
		if (aux->status == TEST)
			printf(" <TEST>\n");
		ft_usleep(100000);
		aux = aux->next;
	}
}

t_philo	*ft_philolast(t_philo *lst)
{
	u_int32_t	start_id;

	if (!lst)
		return (NULL);
	start_id = lst->id;
	while (lst->next)
	{
		lst = lst->next;
		if (start_id == lst->id)
			break ;
	}
	return (lst);
}

void	ft_philoadd_back(t_philo **lst, t_philo *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->prev = ft_philolast(*lst);
		ft_philolast(*lst)->next = new;
	}
}

t_philo	*create_philo_node(u_int32_t id, t_times tv)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	memset(node, 0, sizeof(t_philo));
	node->id = id;
	node->tv = tv;
	node->status = TEST;
	return (node);
}
