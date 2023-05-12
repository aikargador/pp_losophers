/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:07:17 by aikram            #+#    #+#             */
/*   Updated: 2023/05/11 18:12:02 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

void	ft_cautious_free(void **pointer)
{
	free(*pointer);
	*pointer = NULL;
}

void	ft_very_cautious_free(void ***pointer)
{
	free(*pointer);
	*pointer = NULL;
}

bool	chk_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		return (ret_putstr_fd(POS, str, 2, false));
	if (str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		return (ret_putstr_fd(DEC, str, 2, false));
	if (str[i] == ',')
		return (ret_putstr_fd(CMA, str, 2, false));
	if (str[i])
		return (ret_putstr_fd(NUM, str, 2, false));
	if (ft_atopi(str) == -1)
		return (ret_putstr_fd(BIG, str, 2, false));
	return (true);
}

bool	valid_arg(int c, char **v)
{
	int	i;

	i = -1;
	if (c < 5)
		return (ft_putstr_fd("\e[38;5;88mphilosophers: min 4 args!\e[0m\n", 2));
	if (c > 6)
		return (ft_putstr_fd("\e[38;5;88mphilosophers: max 5 args!\e[0m\n", 2));
	while (v[1][++i])
		if (v[1][i] != '0')
			break ;
	if (!v[1][i])
		return (ft_putstr_fd(ZT, 2));
	v++;
	while (*v)
		if (!valid_arg_utl(*(v)++))
			return (false);
	return (true);
}

void	init_info(int c, char **v, t_info *info)
{
	info->pp_amt = ft_atopi(v[1]);
	info->tt_die = ft_atopi(v[2]);
	info->tt_eat = ft_atopi(v[3]);
	info->tt_sleep = ft_atopi(v[4]);
	if (c == 6)
		info->tpp_meat = ft_atopi(v[5]);
	else
		info->tpp_meat = 0;
}
