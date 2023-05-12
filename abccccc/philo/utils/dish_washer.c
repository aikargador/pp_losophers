/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dish_washer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:06:58 by aikram            #+#    #+#             */
/*   Updated: 2023/05/10 17:32:26 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

void	ultimate_destructor(t_hands *hands)
{
	t_hands	*tmp;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while (++i[1] <= hands->hand)
		hands = hands->next;
	while (++i[0] < i[1])
	{
		tmp = hands->next;
		pthread_mutex_destroy(&hands->cuffs);
		free(hands);
		hands = tmp;
	}
}

void	*mission_failed_retreat(t_hands *hands, int l)
{
	t_hands	*tmp;
	int		i;

	i = 0;
	while (++i < l)
	{
		if (i + 1 < l)
			tmp = hands->next;
		pthread_mutex_destroy(&hands->cuffs);
		free(hands);
		if (i + 1 < l)
			break ;
		hands = tmp;
	}
	return (NULL);
}

int	free_hands(t_philo *philo)
{
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	return (1);
}

int	terminate_philos(t_able *table)
{
	free(table->pps);
	return (1);
}
