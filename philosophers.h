/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:35:53 by mlegendr           #+#    #+#            */
/*   Updated: 2024/02/08 15:52:37 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

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

typedef enum e_time_code
{
	SECOND,
	MILISECOND,
	MICROSECOND,
}			t_time_code;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TFF,
	TSF,
	DIED,
}			t_status;

typedef struct s_data	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				nb_fork;
}				t_fork;

typedef struct s_philo
{
	int				nb_philo;
	long			nb_meals;
	bool			all_meals;
	long			last_meal;
	t_fork			*f_fork;
	t_fork			*s_fork;
	pthread_t		nb_thread;
	pthread_mutex_t	philo_mutex;
	t_data			*data;
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
	bool			threads_ready;
	long			nb_running_threads;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	write_mutex;
	pthread_t		monitor;
	t_fork			*forks;
	t_philo			*philos;
	pthread_cond_t	cond_var;
};

/*utils*/
void	exit_w_msg(const char *str);
long	ft_atol(const char *str);
long	get_time(t_time_code code);
void	ft_usleep(long time, t_data *data);
void	clean_data(t_data *data);

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
long	get_long(pthread_mutex_t *mutex, long *dest);
bool	sim_done(t_data *data);

/*multithreading*/
void	create_all_threads(t_data *data);
bool	running_thread(pthread_mutex_t *mutex, long *threads, long nb_philo);
void	increase_long(pthread_mutex_t *mutex, long *value);
void	desync_philo(t_philo *philo);

/*write functions*/
void	write_status(t_status status, t_philo *philo);

/*simulation*/
void	dinnerparty(t_data *data);
void	*dinner_sim(void *data);
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo, bool pre);
void	*lone_dinner(void *data);

/*monitor*/
void	*monitor_dinner(void *data);
bool	philo_died(t_philo *philo);
void	philo_dead(t_philo *philo);

void	set_threads_ready(t_data *data);

#endif
