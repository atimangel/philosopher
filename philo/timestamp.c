#include "philo.h"

long	timestamp(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000L + time.tv_usec / 1000L);
}
