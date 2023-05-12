/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:07:01 by aikram            #+#    #+#             */
/*   Updated: 2023/05/12 16:35:38 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

int	time_out(t_val init_time, int time_out)
{
	t_val	current_time;
	long	res;

	res = 0;
	gettimeofday(&current_time, NULL);
	if (!time_out)
		time_out = 50;
	res = ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
			- (init_time.tv_sec * 1000 + init_time.tv_usec / 1000));
	if (res < 0)
		res += 1000;
	if (res >= time_out)
		return (1);
	return (0);
}

int	eat_em_all(t_philo *philo)
{
	t_val	beninging_time;

	if (look_out_for_the_dead(philo))
		return (1);
	if (time_stamp(philo, YEL, 0, EAT))
		return (1);
	gettimeofday(&beninging_time, NULL);
	while (69)
	{
		if (death_reaper(philo))
			return (1);
		if (look_out_for_the_dead(philo))
			return (1);
		if (time_out(beninging_time, philo->table->info.tt_eat))
			break ;
	}
	return (0);
}

int	dream_about_life_with_arms(t_philo *philo)
{
	t_val	beninging_time;

	if (look_out_for_the_dead(philo))
		return (1);
	if (time_stamp(philo, CYN, 0, SLP))
		return (1);
	gettimeofday(&beninging_time, NULL);
	while (69)
	{
		if (death_reaper(philo))
			return (1);
		if (look_out_for_the_dead(philo))
			return (1);
		if (time_out(beninging_time, philo->table->info.tt_sleep))
			break ;
	}
	return (0);
}

int	odd_philosophers(t_philo *philo)
{
	if (death_reaper(philo))
		return (1);
	pthread_mutex_lock(&philo->the_hand->cuffs);
	if (time_stamp(philo, MAG, 0, FRK))
	{
		pthread_mutex_unlock(&philo->the_hand->cuffs);
		return (1);
	}
	if (death_reaper(philo))
		return (1);
	pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
	if (time_stamp(philo, MAG, 0, FRK))
		return (free_hands(philo));
	gettimeofday(&philo->reset_ime, NULL);
	if (eat_em_all(philo))
		return (free_hands(philo));
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	return (0);
}

int	even_philosophers(t_philo *philo)
{
	if (death_reaper(philo))
		return (1);
	pthread_mutex_lock(&philo->the_neighbours_hand->cuffs);
	if (time_stamp(philo, MAG, 0, FRK))
	{
		pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
		return (1);
	}
	if (death_reaper(philo))
		return (1);
	pthread_mutex_lock(&philo->the_hand->cuffs);
	if (time_stamp(philo, MAG, 0, FRK))
		return (free_hands(philo));
	gettimeofday(&philo->reset_ime, NULL);
	if (eat_em_all(philo))
		return (free_hands(philo));
	pthread_mutex_unlock(&philo->the_neighbours_hand->cuffs);
	pthread_mutex_unlock(&philo->the_hand->cuffs);
	return (0);
}
