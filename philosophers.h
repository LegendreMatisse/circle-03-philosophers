/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:35:53 by mlegendr           #+#    #+#            */
/*   Updated: 2024/01/25 20:45:58 by matisse          ###   ########.fr       */
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

typedef struct s_data	t_data;

typedef struct s_fork
{
	pthread_mutex_t	*mutex;
	int				nb_fork;
}				t_fork;

typedef struct s_philo
{
	int			nb_philo; //id
	long		nb_meals; //meals_counter
	bool		all_meals; //full
	long		last_meal; //last_meal_time
	t_fork		*f_fork; //first_fork
	t_fork		*s_fork; //second_fork
	pthread_t	*nb_thread; //thread_id
	t_data		*data; //table
}				t_philo;

struct s_data
{
	long			nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_meals;
	long			start_time;
	bool			end;
	bool			hreads_ready;
	pthread_mutex_t	*data_mutex;
	t_fork			*forks;
	t_philo		*	philos;
};

/*utils*/
void	exit_w_msg(const char *str);
long	ft_atol(const char *str);

/*validation*/
void	arg_validation(t_data *data, char **argv);

/*error catchers*/
void	*catch_malloc_error(size_t size);

/*mutex management*/
void	catch_mutex_error(int status, t_mutex_code code);
void	handle_mutex_code(pthread_mutex_t *mutex, t_mutex_code code);

/*thread management*/
void	catch_thread_error(int status, t_mutex_code code);
void	handle_thread_code(pthread_t *thread, void *(*routine)(void *),
			void *data, t_mutex_code code);

/*init*/
void	give_fork(t_philo *philo, t_fork *forks, int i);
void	init_philos(t_data *data);
void	init_data(t_data *data);

/*variable manipulation*/
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *dest);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
void	get_long(pthread_mutex_t *mutex, long *dest);
bool	sim_done(t_data *data);

/*multithreading*/
void	create_all_threads(t_data *data);
