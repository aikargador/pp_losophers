/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuffs_ltd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:07:20 by aikram            #+#    #+#             */
/*   Updated: 2023/05/12 15:23:06 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

t_hands	*cuffs_manufacturer(void)
{
	t_hands	*hand;

	hand = ft_calloc(1, sizeof(t_hands));
	if (!hand)
		return (NULL);
	hand->next = NULL;
	return (hand);
}

t_hands	*cuffs_init(int amt_of_prosthetic_arms)
{
	t_hands	*hands;
	t_hands	*tmp;
	int		i;

	i = 0;
	hands = 0;
	while (++i <= amt_of_prosthetic_arms)
	{
		tmp = cuffs_manufacturer();
		if (!tmp)
			return (mission_failed_retreat(hands, i));
		ft_lstadd_back(&hands, tmp);
		tmp->hand = i;
		if (pthread_mutex_init(&tmp->cuffs, NULL))
			return (mission_failed_retreat(hands, i));
	}
	tmp->next = hands;
	return (hands);
}

int	protection_init(t_able *table)
{
	if (pthread_mutex_init(&table->printm, NULL))
	{
		ultimate_destructor(table->hands);
		return (1);
	}
	if (pthread_mutex_init(&table->death_control, NULL))
	{
		pthread_mutex_destroy(&table->printm);
		ultimate_destructor(table->hands);
		return (1);
	}
	return (0);
}
