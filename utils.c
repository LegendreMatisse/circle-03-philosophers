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
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_w_msg("Error: Malloc failed.");
	return (ptr);
}
