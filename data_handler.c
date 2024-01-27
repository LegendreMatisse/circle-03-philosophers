/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:02:48 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/27 16:51:58 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	arg_validation(t_data *data, char **argv)
{
	data->nb_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2] * 1000);
	data->time_to_eat = ft_atol(argv[3] * 1000);
	data->time_to_sleep = ft_atol(argv[4] * 1000);
	if (data->time_to_die < 60000
		|| data->time_to_eat < 60000
		|| data->time_to_sleep < 60000)
		exit_w_msg("Error: Time must be at least 60ms.");
	if (argv[5])
		data->nb_meals = ft_atol(argv[5]);
	else
		data->nb_meals = -1;
}

void	init_data(t_data *data)
{
	int	i;

	i = -1;
	data->end = false;
	data->threads_ready = false;
	handle_mutex_code(&data->data_mutex, INIT);
	handle_mutex_code(&data->write_mutex, INIT);
	data->philos = catch_malloc_error(sizeof(t_philo) * data->nb_philo);
	data->forks = catch_malloc_error(sizeof(t_fork) * data->nb_philo);
	while (++i < data->nb_philo)
	{
		handle_mutex_code(&data->forks[i].mutex, INIT);
		data->forks[i].nb_fork = i;
	}
	init_philos(data);
}

void	init_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->nb_philo)
	{
		philo = table->philos + i;
		philo->nb_philo = i + 1;
		philo->nb_meals = 0;
		philo->data = data;
		handle_mutex_code(&philo->philo_mutex, INIT);
		give_fork(philo, data->forks, i);
	}
}

void	give_fork(t_philo *philo, t_fork *forks, int i)
{
	int	nb_philo;

	nb_philo = philo->table->nb_philo;
	philo->s_fork = &forks[i];
	philo->f_fork = &forks[(i + 1) % nb_philo];
	if (philo->nb_philo % 2 == 0)
	{
		philo->f_fork = &forks[i];
		philo->s_fork = &forks[(i + 1) % nb_philo];
	}
}
