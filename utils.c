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

void	*catch_malloc_error(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_w_msg("Error: Malloc failed.");
	return (ptr);
}

void	catch_mutex_error(int status, t_mutex_code code)
{
	if (status == 0)
		return ;
	if (EINVAL == status && (code == LOCK || code == UNLOCK))
		exit_w_msg("Error: Invalid mutex.");
	else if (EINVAL == status && code == INIT)
		exit_w_msg("Error: Invalid attribute.");
	else if (EDEADLK == status)
		exit_w_msg("Error: Deadlock detected.");
	else if (EPERM == status)
		exit_w_msg("Error: No lock on thread.");
	else if (ENOMEN == status)
		exit_w_msg("Error: No memory available.");
	else if (EBUSY == status)
		exit_w_msg("Error: Mutex is locked.");

}

void	handle_mutex_code(pthread_mutex_t *mutex, t_mutex_code code)
{
	if (code == LOCK)
		catch_mutex_error(pthread_mutex_lock(mutex), code);
	else if (code == UNLOCK)
		catch_mutex_error(pthread_mutex_unlock(mutex), code);
	else if (code == INIT)
		catch_mutex_error(pthread_mutex_init(mutex, NULL), code);
	else if (code == DESTROY)
		catch_mutex_error(pthread_mutex_destroy(mutex), code);
	else
		exit_w_msg("Error: Wrong mutex code.");
}
