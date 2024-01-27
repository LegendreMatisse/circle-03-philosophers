/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:03:44 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/25 18:06:21 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_w_msg(const char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

long	ft_atol(const char *str)
{
	long	nb;

	nb = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+')
		++str;
	else if (*str == '-')
		exit_w_msg("Error: No negative numbers.");
	else if (*str < '0' || *str > '9')
		exit_w_msg("Error: Not a number.");
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		if (nb > INT_MAX)
			exit_w_msg("Error: Number too big.");
		str++;
	}
	return (nb);
}

long	get_time(t_time_code code)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		exit_w_msg("Error: gettimeofday failed.");
	if (code == SECOND)
		return (time.tv_sec + time.tv_usec / 1000000);
	else if (code == MILLISECOND)
		return (time.tv_sec * 1000 + time.tv_usec / 1000);
	else if (code == MICROSECOND)
		return (time.tv_sec * 1000000 + time.tv_usec);
	else
		exit_w_msg("Error: Wrong time code.");
	return (123123123);
}
