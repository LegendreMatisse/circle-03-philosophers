/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:35:18 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/27 19:37:39 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		arg_validation(&data, argv);
		init_data(&data);
		dinnerparty(&data);
		clean_data(&data);
	}
	else
		exit_w_msg("Error: Wrong number of arguments.");
	return (0);
}

void	clean_data(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < data->nb_philo)
	{
		philo = data->philos + i;
		handle_mutex_code(&philo->philo_mutex, DESTROY);
	}
	handle_mutex_code(&data->write_mutex, DESTROY);
	handle_mutex_code(&data->data_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
}
