/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:46:31 by mlegendr          #+#    #+#             */
/*   Updated: 2024/01/25 20:46:57 by matisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*catch_malloc_error(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_w_msg("Error: Malloc failed.");
	return (ptr);
}
