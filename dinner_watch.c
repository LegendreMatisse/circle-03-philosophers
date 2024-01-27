#include "philosophers.h"

void	*monitor_dinner(void *data)
{
	int		i;
	t_data	*d;

	d = (t_data *)data;
	while (!running_thread(&data->data_mutex, &data->nb_running_threads,
			data->nb_philo))
		;
	while (sim_done(d) == false)
	{
		i = -1;
		while (++i < data->nb_philo && sim_done(d) == false)
		{
			if (philo_died(&data->philos + i))
			{
				set_bool(&data->data_mutex, &data->end, true);
				write_status(DEAD, &data->philos + i);
			}
		}
	}
	return (NULL);
}

bool	philo_died(t_philo *philo)
{
	long	passed;
	long	deceased;

	if (get_bool(&philo->philo_mutex, &philo->all_meals) == true)
		return (false);
	passed = get_time(MILISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal);
	deceased = philo->data->time_to_die / 1000;
	if (passed > deceased)
		return (true);
	else
		return (false);
}
