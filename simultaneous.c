/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simultaneous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:53:07 by matisse           #+#    #+#             */
/*   Updated: 2024/01/27 19:54:08 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//create_all_threads(philo->data);

void	create_all_threads(t_data *data)
{
	while (get_bool(&data->data_mutex, &data->threads_ready) == false)
		;
}
