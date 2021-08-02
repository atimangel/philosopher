#include "philo.h"

int		clean_table(t_condition *condition)
{
	int	i;

	i = 0;
	while (i < condition->number)
	{
		pthread_mutex_destroy(condition->fork + i++);
		printf("wash %i fork\n", i);
	}
	pthread_mutex_destroy(condition->mic);
	printf("turn off MIC\n");
	free(condition->fork);
	free(condition->mic);
	free(condition->philo);
}
