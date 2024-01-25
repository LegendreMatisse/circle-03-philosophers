/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:44:11 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/25 20:44:41 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	catch_thread_error(int status, t_mutex_code code)
{
	if (status == 0)
		return ;
	if (EAGAIN == status)
		exit_w_msg("Error: Not enough resources to create thread.");
	else if (EPERM == status)
		exit_w_msg("Error: No permission.");
	else if (EINVAL == status && code == CREATE)
		exit_w_msg("Error: Invalid attribute.");
	else if (EINVAL == status && (code == JOIN || code == DETACH))
		exit_w_msg("Error: Invalid thread.");
	else if (ESRCH == status)
		exit_w_msg("Error: No thread found.");
	else if (status == EDEADLK)
		exit_w_msg("Error: Deadlock detected.");
}

void	handle_thread_code(pthread_t *thread, void *(*routine)(void *),
		void *data, t_mutex_code code)
{
	if (code == CREATE)
		catch_thread_error(pthread_create(thread, NULL, routine, data), code);
	else if (code == JOIN)
		catch_thread_error(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		catch_thread_error(pthread_detach(*thread), code);
	else
		exit_w_msg("Error: Wrong thread code.");
}
