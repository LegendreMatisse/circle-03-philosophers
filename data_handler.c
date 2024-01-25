/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:02:48 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/25 18:05:04 by matisse          ###   ########.fr       */
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
	data->end = false;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		exit_w_msg("Error: Malloc failed.");
	data
}
