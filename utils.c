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


