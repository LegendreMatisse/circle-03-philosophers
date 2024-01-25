#include "philosophers.h"

void	*catch_malloc_error(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_w_msg("Error: Malloc failed.");
	return (ptr);
}
