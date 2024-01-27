#include "philosophers.h"

void	write_status(t_status status, t_philo *philo)
{
	long	passed;

	passed = get_time(MILISECOND) - philo->start_time;
	if (philo->all_meals)
		return ;
	handle_mutex_code(&philo->data->write_mutex, LOCK);
	if ((status == TFF || status == TSF) && !sim_done(philo->data))
	printf("%-6ld %d has taken a fork\n", passed, philo->nb_philo);
	else if (status == EATING && !sim_done(philo->data))
		printf("%-6ld %d is eating\n", passed, philo->nb_philo);
	else if (status == SLEEPING && !sim_done(philo->data))
		printf("%-6ld %d is sleeping\n", passed, philo->nb_philo);
	else if (status == THINKING && !sim_done(philo->data))
		printf("%-6ld %d is thinking\n", passed, philo->nb_philo);
	else if (status == DIED && !sim_done(philo->data))
		printf("%-6ld %d died\n", passed, philo->nb_philo);
	handle_mutex_code(&philo->data->write_mutex, UNLOCK);
}
