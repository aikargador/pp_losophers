/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:00:37 by aikram            #+#    #+#             */
/*   Updated: 2023/05/12 15:50:45 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

int	bon_appetit(t_philo *philo)
{
	if (death_reaper(philo))
		return (1);
	if (time_stamp(philo, GRN, 0, THK))
		return (1);
	if (philo->id % 2)
	{
		if (odd_philosophers(philo))
			return (1);
	}
	else
	{
		if (even_philosophers(philo))
			return (1);
	}
	if (dream_about_life_with_arms(philo))
		return (1);
	return (0);
}

int	lone_wolf(t_philo *philo)
{
	gettimeofday(&philo->reset_ime, NULL);
	if (time_stamp(philo, GRN, 0, THK))
		return (0);
	pthread_mutex_lock(&philo->the_hand->cuffs);
	if (time_stamp(philo, MAG, 0, FRK))
	{
		pthread_mutex_unlock(&philo->the_hand->cuffs);
		return (0);
	}
	while (69)
	{
		if (death_reaper(philo))
		{
			pthread_mutex_unlock(&philo->the_hand->cuffs);
			return (0);
		}
		usleep(69);
	}
	return (0);
}

int	green_light(t_philo *philo, long initime)
{
	gettimeofday(&philo->reset_ime, NULL);
	philo->is_pp_dead = (philo->reset_ime.tv_sec * 1000 + \
		philo->reset_ime.tv_usec / 1000);
	if (philo->is_pp_dead >= initime)
		return (1);
	return (0);
}

int	simprint_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->printm);
	return (1);
}
