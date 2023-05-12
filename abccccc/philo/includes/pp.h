/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:23:05 by aikram            #+#    #+#             */
/*   Updated: 2023/05/12 16:43:04 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PP_H
# define PP_H

//------------------------------ header files ----------------------------------
# include <unistd.h>//idk
# include <stdio.h>//printf
# include <string.h>// idk
# include <stdlib.h>// malloc free exit success and failiure
# include <pthread.h>// anything related to threads
# include <stdbool.h>// bool
# include <limits.h>// intmax
# include <errno.h>
# include <sys/time.h>

//--------------------------------- colors -------------------------------------

# define MAG "\e[0;35m"
# define YEL "\e[0;33m"
# define CYN "\e[0;36m"
# define GRN "\e[0;32m"
# define RED "\e[1;31m"
# define RST "\e[0m"

//--------------------------------- messages -----------------------------------

# define FRK "has attached a prosthetic arm\e[0m 🦾\n"
# define EAT "is eating\e[0m 🦾🍛🦾\n"
# define SLP "😴 is sleeping\e[0m 🌚\n"
# define THK "🤔 is sinking...\e[0m 🗿\n"
# define DED "☠️☠️☠️ \e[48;5;236m\e[1;31mWASTED!\e[0m \e[0;31m☠️☠️☠️\e[0m\n"

# define CMA "\e[0;31mphilosophers: %s: comma, SERIOUSLY, COMMA,!,!,!,!\e[0m\n"
# define POS "\e[38;5;158mphilosophers: \e[0;31m%s\e[38;5;158m: be positive!\e[0m\n"
# define BIG "\e[38;5;136mphilosophers: %s: argument too big, DIET!\e[0m\n"
# define NUM "\e[38;5;140mphilosophers: %s: numeric arg only!\e[0m\n"
# define DEC "\e[0;31mphilosophers: %s: DECIMAL?, gimme a break! orrrr\
....    kitkat! 🗿\e[0m\n"
# define ZT "\e[38;5;224mphilosophers: zero philos?, why not \e[38;5;161mz\
\e[38;5;162me\e[38;5;163mr\e[38;5;164mo\e[38;5;165m_\e[38;5;166mt\e[38;5;167mw\
\e[38;5;168mo\e[38;5;169m!\e[0m\n"

//-------------------------------- structs -------------------------------------

typedef struct s_able	t_able;
typedef struct timeval	t_val;

typedef struct s_info
{
	int	dig;
	int	fig;
	int	pp_amt;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	tpp_meat;
}	t_info;

typedef struct s_hands {
	int				hand;
	pthread_mutex_t	cuffs;
	struct s_hands	*next;
}	t_hands;

typedef struct s_philo {
	int				id;
	long			is_pp_dead;
	pthread_t		birth_certificate;
	t_able			*table;
	t_hands			*the_hand;
	t_hands			*the_neighbours_hand;
	struct timeval	reset_ime;
	struct timeval	curnt_ime;
}	t_philo;

struct	s_able {
	int				death_certificate;
	t_info			info;
	t_philo			*pps;
	t_hands			*hands;
	long			initime;
	struct timeval	init_ime;
	pthread_mutex_t	death_control;
	pthread_mutex_t	printm;
};

//------------------------------- source ---------------------------------------

/* main.c */
int		death_reaper(t_philo *drPhil);
int		time_stamp(t_philo *philo, char *clr, int ded, char *msg);

/* philo.c */
int		eat_em_all(t_philo *philo);
int		odd_philosophers(t_philo *philo);
int		even_philosophers(t_philo *philo);
int		dream_about_life_with_arms(t_philo *philo);
int		think_about_life_with_arms(t_philo *philo);

/* simulation.c */
int		bon_appetit(t_philo *philo);
int		lone_wolf(t_philo *philo);
int		green_light(t_philo *philo, long initime);
int		simprint_unlock(t_philo *philo);
//------------------------------- utils ----------------------------------------

/* utils0.c */
void	ft_cautious_free(void **pointer);
void	ft_very_cautious_free(void ***pointer);
bool	chk_numeric(char *str);
bool	valid_arg(int c, char **v);
void	init_info(int c, char **v, t_info *info);

/* utils1.c */
bool	ret_putstr_fd(char *s, char *inc, int fd, bool free);
bool	ft_putstr_fd(char *s, int fd);
int		ft_atopi(const char *str);
void	ft_lstadd_back(t_hands **lst, t_hands *new);
t_hands	*ft_lstlast(t_hands *lst);

/* utils2.c */
bool	valid_arg_utl(char *str);
int		look_out_for_the_dead(t_philo *philo);
void	artificial_intelligence(t_info *info);
int		printer(t_philo *philo, char *clr, int ded, char *msg);
void	*ft_calloc(size_t count, size_t size);

/* cuffs_ltd.c */
t_hands	*cuffs_manufacturer(void);
t_hands	*cuffs_init(int amt_of_prosthetic_arms);
int		protection_init(t_able *table);

/* dish_washer.c */
void	ultimate_destructor(t_hands *hands);
void	*mission_failed_retreat(t_hands *hands, int l);
int		terminate_philos(t_able *table);
int		free_hands(t_philo *philo);

#endif