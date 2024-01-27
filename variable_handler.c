/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:52:28 by matisse           #+#    #+#             */
/*   Updated: 2024/01/27 16:52:53 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	handle_mutex_code(mutex, LOCK);
	*dest = value;
	handle_mutex_code(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *dest)
{
	bool	value;

	handle_mutex_code(mutex, LOCK);
	value = *dest;
	handle_mutex_code(mutex, UNLOCK);
	return (value);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	handle_mutex_code(mutex, LOCK);
	*dest = value;
	handle_mutex_code(mutex, UNLOCK);
}

void	get_long(pthread_mutex_t *mutex, long *dest)
{
	long	value;

	handle_mutex_code(mutex, LOCK);
	value = *dest;
	handle_mutex_code(mutex, UNLOCK);
	return (value);
}

bool	sim_done(t_data *data)
{
	return (get_bool(data->data_mutex, &data->end));
}
