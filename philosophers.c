/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:35:18 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/25 18:05:29 by matisse          ###   ########.fr       */
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
	{
		exit_w_msg("Error: Wrong number of arguments.");
	}
	return (0);
}
