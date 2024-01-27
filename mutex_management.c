/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:42:39 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/27 19:46:16 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	else if (ENOMEM == status)
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
