/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_watch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:01:45 by matisse           #+#    #+#             */
/*   Updated: 2024/01/27 22:01:50 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_dinner(void *data)
{
	int		i;
	t_data	*d;

	d = (t_data *)data;
	while (!running_thread(&d->data_mutex, &d->nb_running_threads,
			d->nb_philo))
		;
	while (sim_done(d) == false)
	{
		i = -1;
		while (++i < d->nb_philo && sim_done(d) == false)
		{
			if (philo_died(d->philos + i))
			{
				set_bool(&d->data_mutex, &d->end, true);
				write_status(DIED, d->philos + i);
			}
		}
	}
	return (NULL);
}

bool	philo_died(t_philo *philo)
{
	long	passed;
	long	deceased;

	if (get_bool(&philo->philo_mutex, &philo->all_meals) == true)
		return (false);
	passed = get_time(MILISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal);
	deceased = philo->data->time_to_die / 1000;
	if (passed > deceased)
		return (true);
	else
		return (false);
}

void philo_dead(t_philo *philo)
{
	if (philo_died(philo))
	{
		//set_bool(&philo->philo_mutex, &philo->all_meals, true);
		set_bool(&philo->data->data_mutex, &philo->data->end, true);
	}
}
