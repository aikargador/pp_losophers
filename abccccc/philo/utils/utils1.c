/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uts1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:07:15 by aikram            #+#    #+#             */
/*   Updated: 2023/05/10 17:54:44 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

t_hands	*ft_lstlast(t_hands *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_hands **lst, t_hands *new)
{
	if (!new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

int	ft_atopi(const char *str)
{
	unsigned long	res;

	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *(str)++ - '0';
		if (res > INT_MAX)
			return (-1);
	}
	if (res > 2147483647)
		return (-1);
	return (res);
}

bool	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &(s[index]), 1);
		index++;
	}
	return (false);
}

bool	ret_putstr_fd(char *s, char *inc, int fd, bool free)
{
	size_t	i[2];

	i[0] = -1;
	while (s[++i[0]] && s[i[0]] != '%')
		write(fd, &(s[i[0]]), 1);
	if (inc && *inc)
	{
		i[1] = -1;
		while (inc[++i[1]])
			write(fd, &(inc[i[1]]), 1);
		if (free)
			ft_cautious_free((void **)&inc);
		write(fd, " ", 1);
	}
	i[0] += 1;
	while (s[++i[0]])
		write(fd, &(s[i[0]]), 1);
	return (false);
}
