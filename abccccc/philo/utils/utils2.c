/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:53:22 by aikram            #+#    #+#             */
/*   Updated: 2023/05/12 15:34:41 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
		((char *)str)[i++] = '\0';
	return (str);
}

bool	valid_arg_utl(char *str)
{
	if (!chk_numeric(str))
		return (false);
	if (!str[0])
	{
		write(1, "\e[38;5;202mphilosophers: cricket chirps\e[0m", 43);
		usleep(200000);
		write(1, ".", 1);
		usleep(200000);
		write(1, ".", 1);
		usleep(200000);
		write(1, ".\n", 2);
		return (false);
	}
	return (true);
}

int	look_out_for_the_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death_control);
	if (philo->table->death_certificate)
	{
		pthread_mutex_unlock(&philo->table->death_control);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->death_control);
	return (0);
}

void	artificial_intelligence(t_info *info)
{
	int	n[6];

	n[0] = info->tt_die;
	n[1] = info->tt_eat;
	n[2] = info->tt_sleep;
	n[3] = -1;
	n[5] = 0;
	info->fig = 1;
	while (++n[3] < 3)
	{
		n[4] = 0;
		while (n[n[3]])
		{
			n[n[3]] /= 10;
			n[4]++;
		}
		if (n[5] < n[4])
			n[5] = n[4];
	}
	info->dig = n[5];
	while (n[5])
	{
		info->fig *= 10;
		n[5]--;
	}
}

int	printer(t_philo *philo, char *clr, int ded, char *msg)
{
	gettimeofday(&philo->curnt_ime, NULL);
	pthread_mutex_lock(&philo->table->printm);
	if (ded)
	{
		if (look_out_for_the_dead(philo))
			return (simprint_unlock(philo));
		printf("%s%0*ld \e[9m\e[2m%d\e[29m\e[22m %s", clr, \
			philo->table->info.dig, (((philo->curnt_ime.tv_sec * 1000 + \
			philo->curnt_ime.tv_usec / 1000) - philo->table->initime) \
			% philo->table->info.fig), philo->id, msg);
	}
	else
	{
		if (look_out_for_the_dead(philo))
			return (simprint_unlock(philo));
		printf("%s%0*ld %d %s", clr, philo->table->info.dig, \
			(((philo->curnt_ime.tv_sec * 1000 + philo->curnt_ime.tv_usec \
			/ 1000) - philo->table->initime) % philo->table->info.fig), \
			philo->id, msg);
	}
	pthread_mutex_unlock(&philo->table->printm);
	return (0);
}
