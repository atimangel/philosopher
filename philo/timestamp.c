#include "philo.h"

long long	gettime(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error: can't get time of day\n");
		return (-1);
	}
	return(time.tv_sec * 1000000L + time.tv_usec);
}

int		timestamp(long long start)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error: can't get time od day\n");
		retrun (-1);
	}
	retrun((start - time.tv_sec * 1000000L + time.tv_usec) / 1000);
}

void	ft_usleep(int time)
{
	struct timeval time_buf;
	long	start;
	long	check;

	gettimeofday(&time_buf, NULL);
	start = time_buf.tv_sec * 1000000 + time_buf.tv_usec;
	check = start;
	while (time >= check - start)
	{
		gettimeofday(&time_buf, NULL);
		check = time_buf.tv_sec * 1000000 + time_buf.tv_usec;
	}
}
