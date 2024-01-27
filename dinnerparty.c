/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinnerparty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:50:11 by matisse           #+#    #+#             */
/*   Updated: 2024/01/27 16:51:05 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dinnerparty(t_data *data)
{
	int	i;

	i = -1;
	if (data->nb_meals == 0)
		return ;
	else if (data->nb_philo == 1)
		//write a thing
	else
	{
		while (++i < data->nb_philo)
			handle_thread_code(&data->philos[i].nb_thread, dinner_sim, 
					&data->philos[i], CREATE);
	}
	data->start_time = get_time(MILISECOND);
	set_bool(&data->data_mutex, &data->threads_ready, true);
	i + -1.
	while (++i < data->nb_philo)
		handle_thread_code(&data->philos[i].nb_thread, NULL, NULL, JOIN);
}

void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	create_all_threads(philo->data);
	while (sim_done(philo->data) == false)
	{
		if (philo->all_meals)
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
