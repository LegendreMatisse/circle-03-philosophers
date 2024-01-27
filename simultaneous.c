/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simultaneous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:53:07 by matisse           #+#    #+#             */
/*   Updated: 2024/01/27 20:41:39 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//create_all_threads(philo->data);

void	create_all_threads(t_data *data)
{
	while (get_bool(&data->data_mutex, &data->threads_ready) == false)
		;
}

bool	running_thread(pthread_mutex_t *mutex, long *threads, long nb_philo)
{
	bool	running;

	running = false;
	handle_mutex_code(mutex, LOCK);
	if (*threads == nb_philo)
		running = true;
	handle_mutex_code(mutex, UNLOCK);
	return (running);
}	

void	increase_long(pthread_mutex_t *mutex, long *value)
{
	handle_mutex_code(mutex, LOCK);
	*value += 1;
	handle_mutex_code(mutex, UNLOCK);
}

void desync_philo(t_philo *philo)
{
	if (philo->data->nb_philo % 2 == 0)
	{
		if (philo->nb_philo % 2 == 0)
			ft_usleep(30, philo->data);
	}
	else
	{
		if (philo->nb_philo % 2 == 1)
			philo_think(philo, true);
	}
}
