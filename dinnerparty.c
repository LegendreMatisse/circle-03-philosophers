/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinnerparty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:50:11 by matisse           #+#    #+#             */
/*   Updated: 2024/01/27 19:58:48 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dinnerparty(t_data *data)
{
	int	i;

	i = -1;
	if (data->nb_meals == 0)
		return ;
	data->start_time = get_time(MILISECOND);
	create_all_threads(data);
	set_bool(&data->data_mutex, &data->threads_ready, true);
	i = -1;
	while (++i < data->nb_philo)
		handle_thread_code(&data->philos[i].nb_thread, NULL, NULL, JOIN);
	set_bool(&data->data_mutex, &data->end, true);
	handle_thread_code(&data->monitor, NULL, NULL, JOIN);
}

void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	set_long(&philo->philo_mutex, &philo->last_meal, get_time(MILISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->nb_running_threads);
	desync_philo(philo);
	while (sim_done(philo->data) == false)
	{
		if (get_bool(&philo->philo_mutex, &philo->all_meals))
			break ;
		philo_eat(philo);
		write_status(SLEEPING, philo);
		ft_usleep(philo->data->time_to_sleep, philo->data);
		philo_think(philo, false);
		philo_dead(philo);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	handle_mutex_code(&philo->f_fork->mutex, LOCK);
	write_status(TFF, philo);
	handle_mutex_code(&philo->s_fork->mutex, LOCK);
	write_status(TSF, philo);
	set_long(&philo->philo_mutex, &philo->last_meal, get_time(MILISECOND));
	philo->nb_meals++;
	write_status(EATING, philo);
	ft_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->nb_meals > 0 && philo->nb_meals == philo->data->nb_meals)
		set_bool(&philo->philo_mutex, &philo->all_meals, true);
	handle_mutex_code(&philo->f_fork->mutex, UNLOCK);
	handle_mutex_code(&philo->s_fork->mutex, UNLOCK);
}

void	philo_think(t_philo *philo, bool pre)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (pre == false)
		write_status(THINKING, philo);
	if (philo->data->nb_philo % 2 == 0)
		return ;
	t_eat = philo->data->time_to_eat;
	t_sleep = philo->data->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.5, philo->data);
}

void	*lone_dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	create_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal, get_time(MILISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->nb_running_threads);
	write_status(TFF, philo);
	while (sim_done(philo->data) == false)
		ft_usleep(200, philo->data);
	return (NULL);
}
