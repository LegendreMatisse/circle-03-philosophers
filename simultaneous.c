#include "philosophers.h"

//create_all_threads(philo->data);

void	create_all_threads(t_data *data)
{
	while (get_bool(data->data_mutex, &data->threads_ready) == false)
		usleep(50);
}