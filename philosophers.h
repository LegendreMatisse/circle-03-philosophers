/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:35:53 by mlegendr           #+#    #+#            */
/*   Updated: 2024/01/25 18:08:57 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>

typedef struct s_data	t_data;

typedef struct s_fork
{
	pthread_mutex_t	*mutex;
	int				nb_fork;
}				t_fork;

typedef struct s_philo
{
	int			nb_philo;
	long		nb_meals;
	bool		all_meals;
	long		last_meal;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	*nb_thread;
	t_data		*data;
}				t_philo;

struct s_data
{
	long		nb_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nb_meals;
	long		start_time;
	bool		end;
	t_fork		*forks;
	t_philo		*philos;
}

typedef enum e_mutex_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_mutex_code;

/*utils*/
void	exit_w_msg(const char *str);
long	ft_atol(const char *str);

/*validation*/
void	arg_validation(t_data *data, char **argv);

/*error catchers*/
void	*catch_malloc_error(size_t size);
